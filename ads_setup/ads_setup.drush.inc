<?php
/**
 * @file
 * Drush commands for ads_setup module.
 */

/**
 * Implements hook_drush_command().
 */
function ads_setup_drush_command() {
  $items = array();
  $items['ads-configure'] = array(
    'callback'  => 'ads_setup_drush_configure',
    'arguments' => array(
      'properties_path' => array(
        'description' => dt('Required. Path to the json-encoded properties file.'),
        'required'    => TRUE,
      ),
      'module_name' => array(
        'description' => dt('Optional. Name of the module to [re]configure.'),
        'required'    => FALSE,
      ),
    ),
    'description' => dt('Perform all or only the specified module [re]configuration.'),
    'examples' => array(
      'drush ads-configure ./properties.json' => '',
      'drush ads-configure ./properties.json ads_animals' => '',
    ),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function ads_setup_drush_help($section) {
  switch ($section) {
    case 'ads-configure':
      return dt("Ads module[s] [re]configuration.");
  }
}

/**
 * Drush command (ads-configure).
 *
 * Perform all or only the specified module [re]configuration.
 *
 * @param string $properties_path
 *   Optional. Name of the module to [re]configure.
 * 
 * @param string $module_name
 *   Optional. Name of the module to [re]configure.
 */
function ads_setup_drush_configure($properties_path, $module_name = NULL) {
  ads_setup_configure($properties_path, $module_name);
}
