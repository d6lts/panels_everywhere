<?php
// $Id$

/**
 * @file
 * Plugin to handle the 'page_content' content type which allows the
 * mission statement of the site to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Page content'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('Page content that is available if the panel is being used to wrap content with the Panels Everywhere module.'),
  'category' => t('Page elements'),
  'required context' => new ctools_context_required(t('Page content'), 'page_content'),
);

/**
 * Output function for the 'page_content' content type.
 *
 * Outputs the mission statement for the site.
 */
function panels_everywhere_page_content_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  if (is_string($context->data)) {
    $block = new stdClass();
    $block->title = t('Dummy content');
    $block->content = $context->data;
    return $block;
  }

  return $context->data;
}

/**
 * Returns an edit form for custom type settings.
 */
function panels_everywhere_page_content_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}

/**
 * Returns the administrative title for a type.
 */
function panels_everywhere_page_content_content_type_admin_title($subtype, $conf, $context) {
  return $context->identifier;
}
