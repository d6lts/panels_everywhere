$Id$

Panels Everywhere is an advanced method to completely do away with Drupal's
restrictive blocks system and instead use the much more freeing Panels Layout
system to control how your pages look. Panels Everywhere modifies the page as
it is being rendered to 'wrap' the content in a display and can even take
over your page theme to do away with the need for a page.tpl.php.

Doing this requires that you set up a few things properly, because Drupal is
not really designed for this kind of behavior.

Getting Started
===============

Be sure that you have a version of CTools newer than 12-28-2009 -- this
is either the current -dev or Panels 1.3 if it is out. At the time of this
writing, Panels 1.3 has not yet been released, so you will need to use
a -dev version (or from CVS).

Step 1
------

First, back up your site database, just in case. This will make it easy to
completely revert if you decide that Panels Everywhere is not for you. It
is also recommended that you first experiment with this on a small test site
so that you can get a feel for the effects this will have. Sites are best
built from the ground up on Panels Everywhere. Converting an existing site
may be quite difficult.

Step 2
------
Navigate to Administer >> Site building >> Panels >> Settings >> Everywhere.

Check the box to enable the site template. Do not, at this time, check the box
to enable taking over the page.tpl.php. You'll want to have a basic layout that
will properly take over page.tpl.php duties before you enable this.

Step 3
------
Navigate to Administer >> Site Building >> Pages and edit the site_template
(Default site template) page.

Add a new variant. Choose a layout. Add items that you like to the layout. Most
of the items you will want to add to this are in the Page Elements section.

Step 4
------
***It is critical that the Page Content pane is in this layout***. This 
pane represents the content that will be displayed. If it is not there,
the actual page you are viewing will not show up. If you end up looking
at this layout when trying to manage Panels, you could have a problem, and
you will have to manually disable the site template in your database.

Step 5
------
Add other page elements including as the Page Header, Page Navigation or Page 
Messages panes. If you have all three of these you should have most of the
items you would expect on a normal Drupal page layout.

Step 6
------
Preview your page. Make sure the dummy content appears. If you're satisfied,
go ahead and save. Once you save, your new layout should be functional for
all pages.

Step 7
------
Go back to Administer >> Site Building >> Panels >> Settings >> Everywhere 
and enable page.tpl.php override. 

Step 8
------
You might also consider creating a completely blank theme, because existing 
themes will have CSS that expects different markup. To create a blank theme:

1) mkdir sites/all/themes/blank
2) Create the following four lines in a file named blank.info:

name = Blank
description = Blank
core = 6.x
stylesheets[all][] = blank.css

3) Visit Administer >> Site building >> Themes and change your theme to the
   blank theme.

Extras
======

For best results, customized layouts are the way to go. They can include as
much or as little of the page template as you need, and are easily selectable.

The navigation, header and messages blocks can be easily customized by copying
the appropriate pane-*.tpl.php files from the themes directory to your theme,
changing them, and clearing cache. If you need to add additional variables,
look at the theme.inc file. You can create similar preprocess functions in
your template.php. The token function can accept any variable that would
normally appear in your page.tpl.php.

You can easily add more variants and use the regular expressions in the
String: comparision selection rules to change which display gets used
based on the URL. You can also use the "Context: exists" selection rule
to provide default panels only for content that is not already in a panel
by checking to see if the "Managed page" context exists.