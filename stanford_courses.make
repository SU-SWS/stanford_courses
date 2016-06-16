core = 7.x
api = 2

; 7.x-1.x branch
projects[field_collection][type] = "module"
projects[field_collection][subdir] = "contrib"
projects[field_collection][download][type] = "git"
projects[field_collection][download][url] = "http://git.drupal.org/project/field_collection.git"
projects[field_collection][download][revision] = "bc01bdb3ad758bec1655206f9ac74490cfa60a2a"

; https://www.drupal.org/node/1063434 | Feeds and Field Collections should work together.
projects[field_collection][patch][] = https://www.drupal.org/files/issues/field_collection_feeds-1063434-209.patch




