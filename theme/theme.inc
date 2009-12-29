<?php
// $Id$

/**
 * @file
 * Contains preprocess functions for Panels Everywhere themes.
 */

function template_preprocess_pane_header(&$vars) {
  $vars['site_name'] = ctools_set_variable_token('site_name');
  $vars['site_slogan'] = ctools_set_variable_token('site_slogan');
  $vars['front_page'] = url();
  $vars['logo'] = ctools_set_variable_token('logo');
  $vars['search_box'] = ctools_set_variable_token('search_box');
}

function template_preprocess_pane_messages(&$vars) {
  $vars['tabs'] = ctools_set_variable_token('tabs');
  $vars['messages'] = ctools_set_variable_token('messages');
  $vars['help'] = ctools_set_variable_token('help');
}

function template_preprocess_pane_navigation(&$vars) {
  $vars['primary_links'] = menu_primary_links();
  $vars['secondary_links'] = menu_secondary_links();
  $vars['breadcrumb'] = menu_secondary_links();
}
