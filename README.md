# Drupal local settings

## Overview
Provides a local settings file for development environments. This allows you to sync a production database to local without having to change settings in the database.

## Installation
You will need to update your settings file to include this file. If you are using Acquia hosting add an elseif to your settings file below the acquia include:

```php
if (file_exists('/var/www/site-php')) {
  require('/var/www/site-php/nfsadev/nfsadev-settings.inc');
}
// include a local settings file if we are not in an Acquia live environment
// or on Acquia Dev Desktop.
elseif (!isset($_SERVER['DEVDESKTOP_DRUPAL_SETTINGS_DIR'])) {
  require('local.settings.inc');
}
```
