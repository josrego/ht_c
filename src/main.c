#include "hash_table.h"
#include <stdio.h>

int main() {}

// Test the hash table with a single insert
void single_entry_test() {
  // first we create the hash table
  ht_hash_table *ht = ht_new();

  // insert values
  char *key = "aKey";
  char *value = "aValue";
  ht_insert(ht, key, value);

  printf("Inserted: %s:%s\n", key, value);
  // print current hash map
  char *value_searched = ht_search(ht, key);
  printf("Searched for key: %s. Received: %s\n", key, value_searched);

  ht_delete(ht, key);
  if (ht_search(ht, key) == NULL) {
    printf("Value deleted\n");
  } else {
    printf("Value not deleted");
  }

  ht_del_hash_table(ht);
}
