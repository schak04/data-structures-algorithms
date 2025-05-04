#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// Function to generate a hash key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table using quadratic probing
void insert(int table[], int key) {
    int index = hash(key);
    int i = 1;

    // Quadratic probing for collision resolution
    while (table[index] != -1) {
        index = (hash(key) + i * i) % TABLE_SIZE; // Apply quadratic probing
        if (i >= TABLE_SIZE) { // If we've checked all slots
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
        i++;
    }

    table[index] = key; // Insert the key
    printf("Key %d inserted at index %d\n", key, index);
}

// Function to search for a key in the hash table
bool search(int table[], int key) {
    int index = hash(key);
    int i = 1;

    while (table[index] != -1) {
        if (table[index] == key) {
            return true; // Key found
        }
        index = (hash(key) + i * i) % TABLE_SIZE; // Apply quadratic probing
        if (i >= TABLE_SIZE) {
            break; // Full loop, key not found
        }
        i++;
    }
    return false; // Key not found
}

// Function to display the hash table
void display(int table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1) {
            printf("Index %d: %d\n", i, table[i]);
        } else {
            printf("Index %d: ~\n", i);
        }
    }
}

int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1; // Initialize table with -1 (indicating empty slots)
    }

    // Insert keys into the hash table
    insert(table, 23);
    insert(table, 43);
    insert(table, 13);
    insert(table, 27);
    insert(table, 33);

    // Display the hash table
    display(table);

    // Search for keys
    int keyToSearch = 43;
    if (search(table, keyToSearch)) {
        printf("Key %d found in the hash table.\n", keyToSearch);
    } else {
        printf("Key %d not found in the hash table.\n", keyToSearch);
    }

    return 0;
}
