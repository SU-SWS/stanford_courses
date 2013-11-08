Drupal Features module for pulling course information from explorecourses.stanford.edu

-- SUMMARY --
Author: John Bickar

-- NOTES ON THE 7.X-2.X BRANCH --
 The 7.x-2.x branch is currently undergoing heavy development and should not be considered stable in any of the alpha verions.

-- INSTALLATION --
Install and enable as you would any normal Drupal module.

-- HELP --
After enabling the module, visit admin/help/stanford_courses for instructions on importing courses.

-- UPGRADE --
If upgrading from earlier versions, please review the CHANGELOG.txt to see what has changed.

Before any upgrade please follow best practices and backup your database.

An upgrade path from the 1.x branch to the 2.x branch has been added. Simply replace the module with the 2.x version and run update.php.

                        ******** WARNING **********

The 2.x branch upgrade path will delete content and manipulate your course content type. The course section content type and importer will no longer exist in the 2.x branch. These content types and nodes will be deleted. If you are using these content types please consider staying on the 1.x branch and contacting Stanford Web Services for more information on how to proceed.

The stanford_course_section views have been delete in this version. It's been deleted because its functionality has been subsumed.


