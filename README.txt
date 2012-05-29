Drupal Features module for pulling course information from explorecourses.stanford.edu

-- SUMMARY --
Author: John Bickar

-- INSTALLATION --
Install and enable as you would any normal Drupal module.

-- HELP --
After enabling the module, visit admin/help/stanford_courses for instructions on importing courses.

-- UPGRADE --
If upgrading from earlier versions, please review the CHANGELOG.txt to see what has changed.

-- KNOWN ISSUES --
* When enabling the Feature via drush, drush will complain that it cannot find a release history for "text" and several other CCK modules. To avoid this, download CCK first.
* There is an intermittent DateTimeZone error on import - https://github.com/jbickar/stanford_courses/issues/6

