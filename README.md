h1. Drupal local settings
h2. Overview
Provides a local settings file for development environments. This allows you to sync a production database to local without having to change settings in the database.

h2. Installation
You will need to update your settings file to include this file. If you are using Acquia hosting add an elseif to your settings file below the acquia include:
    if (file_exists('/var/www/site-php')) {
      require('/var/www/site-php/nfsadev/nfsadev-settings.inc');
    }
    // include a local settings file if we are not in an Acquia live environment
    // or on Acquia Dev Desktop.
    elseif (!isset($_SERVER['DEVDESKTOP_DRUPAL_SETTINGS_DIR'])) {
      require('local.settings.inc');
    }
