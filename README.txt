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
* There is an intermittent DateTimeZone error on import - https://github.com/SU-SWS/stanford_courses/issues/6

-- NOTE ON COURSE SECTIONS --
There are several limitations to the Course Section importers.
1) If a course section is deleted from explorecourses.stanford.edu, it will not be deleted from 
  the Drupal site unless you delete and re-import all course section nodes from a Feed Importer.
2) On the 6.x-1.x branch, only one nodereference is created between a course node and a section node.

For these reasons, users are encouraged to use the link to the course listing on ExploreCourses 
  to view section information. The Course Section importer likely will be removed from future versions of the module.

-- NOTE ON TAGGING COURSES --
If a tagged course has been imported into a Drupal site, and that tag is subsequently removed 
  from the Course on ExploreCourses, the tag will not be removed from the Drupal node unless 
  you delete and re-import all course nodes from a Feed Importer.