#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Function to generate a new string with a given number
char *generate_string(char *format, int value) {
  // Calculate the length of the string representation of the value
  // Adding 1 for the null terminator and extra space for prefix
  int length = snprintf(NULL, 0, format, value) + 1;

  // Allocate memory for the string
  char *str = (char *)malloc(length * sizeof(char));
  if (!str) {
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  // Generate the string
  snprintf(str, length, format, value);

  return str;
}

void mulitple_entries_test(int entries_amount) {
  ht_hash_table *ht = ht_new();
  char *key_format = "key_%d";
  char *value_format = "value_%d";

  for (int i = 0; i < entries_amount; i++) {
    char *key = generate_string(key_format, i);
    char *value = generate_string(value_format, i);
    ht_insert(ht, key, value);

    if (ht_search(ht, key) == NULL) {
      printf("NULL search obtained: %s", key);
      ht_del_hash_table(ht);
      return;
    }
  }

  printf("%d entries inserted", entries_amount);

  ht_del_hash_table(ht);
}

void clocked_entries_test(int amount) {
  // Start the stopwatch
  clock_t start_time = clock();

  // run test
  mulitple_entries_test(amount);

  // Stop the stopwatch and calculate elapsed time
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  printf("Inserted and retrieved %d entries in: %.4f seconds\n", amount,
         elapsed_time);
}

int main() { clocked_entries_test(1000000); }
