<?php
/**
 * @file
 * A template for local development settings file.
 * Copy this file to sites/default/local.settings.inc and enter local db
 * settings.
 * Add in any configuration variable settings to override variables in the local
 * environment.
 */

// Sets the development state for the environment
$disable_cache = FALSE;

// Prevents caching of JS and CSS
$rebuild_assets = TRUE;

// Database settings
$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'DB_NAME',
  'username' => 'DB_USER',
  'password' => 'DB_PASS',
  'host' => 'DB_HOST',
  'collation' => 'utf8_general_ci',
);

// Set file paths
$conf['file_public_path'] = 'sites/default/files';
$conf['file_temporary_path'] = 'sites/default/files/temp';
$conf['file_private_path'] = 'sites/default/files/private';

// Turn on error display
$conf['error_level'] = 2;

// If we have set disable_cache to TRUE we disable all aggregation and caching.
if (!empty($disable_cache)) {
  if (!class_exists('DrupalFakeCache')) {
    $conf['cache_backends'][] = 'includes/cache-install.inc';
  }
  $conf['cache_default_class'] = 'DrupalFakeCache';

  // Rely on the DB cache for form caching - otherwise forms fail.
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
}

// js and css preprocessing
if (!empty($rebuild_assets)) {
  $conf['preprocess_js'] = 0;
  $conf['preprocess_css'] = 0;
}
