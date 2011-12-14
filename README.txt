Drupal Features module for pulling course information from explorecourses.stanford.edu

DEPENDENCIES
------------
The XPath concat() function used to map to the GUID field (not a true GUID) requires the 6.x-1.x-dev version of feeds_xpathparser (confirmed to work with the -dev version of 2011-Jul-27 or later).

KNOWN ISSUES
------------
* When enabling the Feature via drush, drush will complain that it cannot find a release history for "text" and several other CCK modules. To avoid this, download CCK first.
* There is an intermittent DateTimeZone error on import - https://github.com/jbickar/stanford_courses/issues/6

