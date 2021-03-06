<?php

/**
 * @file
 * Contains preprocess functions for Panels Everywhere themes.
 */

function template_preprocess_pane_header(&$vars) {
  $vars['site_name'] = (theme_get_setting('toggle_name') ? filter_xss_admin(variable_get('site_name', 'Drupal')) : '');

  $vars['site_slogan'] = (theme_get_setting('toggle_slogan') ? filter_xss_admin(variable_get('site_slogan', '')) : '');
  $vars['front_page'] = url();
  $vars['logo'] = theme_get_setting('logo');

  // Only load the search box if the Search module is enabled and the search box
  // is enabled in the theme settings.
  $vars['search_box'] = '';
  if (module_exists('search') && theme_get_setting('toggle_search')) {
    $vars['search_box'] =  drupal_get_form('search_theme_form');
  }
}

function template_preprocess_pane_messages(&$vars) {
  $vars['tabs'] = theme('menu_local_tasks');
  $vars['messages'] = theme('status_messages');
  $vars['help'] = theme('help');
}

function template_preprocess_pane_navigation(&$vars) {
  // Adhere to the theme's settings for the navigation bar.
  $vars['primary_links'] = theme_get_setting('toggle_primary_links') ? menu_primary_links() : array();
  $vars['secondary_links'] = theme_get_setting('toggle_secondary_links') ? menu_secondary_links() : array();
  $vars['breadcrumb'] = theme('breadcrumb', drupal_get_breadcrumb());
}
