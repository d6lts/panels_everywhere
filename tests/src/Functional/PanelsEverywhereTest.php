<?php

namespace Drupal\Tests\panels_everywhere\Functional;

use \Drupal\Tests\BrowserTestBase;

/**
 * Make sure that PE can be enabled.
 *
 * @group panels_everywhere
 */
class PanelsEverywhereTest extends BrowserTestBase {

  /**
   * {@inheritdoc}
   */
  protected $profile = 'standard';

  /**
   * {@inheritdoc}
   */
  public static $modules = [
    'panels_everywhere',
  ];

  /**
   * Verify the front page still loads.
   */
  public function testFrontPage() {
    // Load the test node.
    $this->drupalGet('<front>');
    $this->assertSession()->statusCodeEquals(200);
  }

}
