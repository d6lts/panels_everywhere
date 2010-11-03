<?php
// $Id$

/**
 * @file
 * Contains preprocess functions for Panels Everywhere themes.
 */

function template_preprocess_pane_header(&$vars) {
  $vars['site_name'] = (theme_get_setting('toggle_name') ? filter_xss_admin(variable_get('site_name', 'Drupal')) : '');

  $vars['site_slogan'] = (theme_get_setting('toggle_slogan') ? filter_xss_admin(variable_get('site_slogan', '')) : '');
  $vars['front_page'] = url();
  $vars['logo'] = theme_get_setting('logo');
  $vars['search_box'] = (theme_get_setting('toggle_search') ? drupal_get_form('search_theme_form') : '');
}

function template_process_pane_header(&$vars) {
  $vars['title'] = drupal_get_title();
}

function template_preprocess_pane_messages(&$vars) {
  $vars['tabs'] = theme('menu_local_tasks');
  $vars['help'] = theme('help');
}

function template_process_pane_messages(&$vars) {
  $vars['messages'] = theme('status_messages');
}

function template_preprocess_pane_navigation(&$vars) {
  $vars['main_menu'] = menu_main_menu();
  $vars['secondary_menu'] = menu_secondary_menu();
}

function template_process_pane_navigation(&$vars) {
  $vars['main_menu'] = theme('links__system_main_menu', array(
    'links' => $vars['main_menu'],
    'attributes' => array('id' => 'main-menu', 'class' => array('links', 'clearfix')),
    'heading' => t('Main menu')
  ));
  $vars['secondary_menu'] = theme('links__system_secondary_menu', array(
    'links' => $vars['secondary_menu'],
    'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'clearfix')),
    'heading' => t('Secondary menu')
  ));
  $vars['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()));
}
