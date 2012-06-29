Drupal Features module for pulling course information from explorecourses.stanford.edu

-- SUMMARY --
Author: John Bickar

-- NOTES ON THE 7.X-1.X BRANCH --
The 1.x branch for Drupal 7 provides a way to define relationships between Stanford Course nodes and
  Stanford Course Section nodes via the Entity Reference module (http://drupal.org/project/entityreference).
  The 1.x branch of the module currently does not automatically create those references.
The 2.x branch will automatically create one-to-one relationships from a Stanford Course Section
  node to a Stanford Course node, and one-to-many relationships from a Stanford Course node to Stanford
  Course Section nodes (based on common Subject, Code, and Course ID values).
  To do this, the dependency on the Entity Reference module likely will be deprecated
  in favor of the Relation (http://drupal.org/project/relation) and Rules (http://drupal.org/project/rules)
  modules. Upgrade path from 1.x to 2.x is currently unknown.
-- INSTALLATION --
Install and enable as you would any normal Drupal module.

-- HELP --
After enabling the module, visit admin/help/stanford_courses for instructions on importing courses.

-- UPGRADE --
If upgrading from earlier versions, please review the CHANGELOG.txt to see what has changed.


