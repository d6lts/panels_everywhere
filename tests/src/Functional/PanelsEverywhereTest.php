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
   * @var \Drupal\Core\Config\Entity\ConfigEntityStorageInterface
   */
  protected $pageStorage;

  /**
   * {@inheritdoc}
   */
  protected function setUp() {
    parent::setUp();

    $this->pageStorage = \Drupal::entityTypeManager()->getStorage('page');
  }

  /**
   * Verify the front page still loads while site_template is disabled.
   */
  public function testFrontPage() {
    $siteTemplate = $this->loadSiteTemplate();
    $this->assertEquals(FALSE, $siteTemplate->status(), 'Expect the site_template to be disabled by default');

    // Load the test node.
    $this->drupalGet('<front>');
    $this->assertSession()->statusCodeEquals(200);
  }

  /**
   * Verify that other pages load before and after enabling site_template.
   */
  public function testOtherPages() {
    // Check that 404 pages loads properly by default.
    $this->drupalGet('/some/page/that/should/not/exist');
    $this->assertSession()->statusCodeEquals(404);

    // Check that the login page load properly by default.
    $this->drupalGet('/user/login');
    $this->assertSession()->statusCodeEquals(200);

    // Enable site template & clear page-cache
    $this->loadSiteTemplate()
      ->setStatus(TRUE)
      ->save();
    drupal_flush_all_caches();

    // Check that 404 pages loads properly.
    $this->drupalGet('/some/page/that/should/not/exist');
    $this->assertSession()->statusCodeEquals(404);

    // Check that the login page load properly.
    $this->drupalGet('/user/login');
    $this->assertSession()->statusCodeEquals(200);
  }

  /**
   * Retrieves an un-cached version of the site_template from storage.
   *
   * @return \Drupal\page_manager\PageInterface
   */
  protected function loadSiteTemplate() {
    /** @var  $site_template \Drupal\page_manager\PageInterface */
    $this->pageStorage->resetCache(['site_template']);
    $site_template = $this->pageStorage->load('site_template');
    return $site_template;
  }

}
