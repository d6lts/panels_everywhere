<?php
/**
 * @file
 *
 * Theme implementation to display the header block on a Drupal page.
 *
 * This utilizes the following variables thata re normally found in
 * page.tpl.php:
 * - $front_page
 * - $logo
 * - $site_name
 * - $site_slogan
 * - $search_box
 *
 * Additional items can be added via theme_preprocess_pane_header(). See
 * template_preprocess_pane_header() for examples.
 */
?>
<div id="header">
  <div id="logo-title">

    <?php if (!empty($logo)): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
    <?php endif; ?>

    <div id="name-and-slogan">
      <?php if (!empty($site_name)): ?>
        <h1 id="site-name">
          <a href="<?php print $front_page ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </h1>
      <?php endif; ?>

      <?php if (!empty($site_slogan)): ?>
        <div id="site-slogan"><?php print $site_slogan; ?></div>
      <?php endif; ?>
    </div> <!-- /name-and-slogan -->
  </div> <!-- /logo-title -->

  <?php if (!empty($search_box)): ?>
    <div id="search-box"><?php print $search_box; ?></div>
  <?php endif; ?>

</div> <!-- /header -->
