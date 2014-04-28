Drupal Features module for pulling course information from explorecourses.stanford.edu

-- SUMMARY --
Authors: John Bickar, Shea McKinney
Features Version: 2.x

-- INSTALLATION --
Install and enable as you would any normal Drupal module.

-- HELP --
After enabling the module, visit admin/help/stanford_courses for instructions on importing courses.

-- UPGRADE --
If upgrading from earlier versions, please review the CHANGELOG.txt to see what has changed.

Before any upgrade please follow best practices and backup your database.

An upgrade path from the 1.x branch to the 2.x branch has been added. Simply replace the module with the 2.x version and run update.php.

                        ******** WARNING **********

The 2.x branch upgrade path will delete content and manipulate your course content type. The course section content type and importer will no longer exist in the 2.x branch. These content types and nodes will be deleted. If you are using these content types please consider staying on the 1.x branch.

The stanford_course_section View has been deleted in this version because its functionality has been subsumed.


Example Course Importer URL:
http://explorecourses.stanford.edu/search?view=xml-20130201&filter-coursestatus-Active=on&page=0&catalog=&q=ARTHIST&collapse=
