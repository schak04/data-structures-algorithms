/*
Hashing:
- Reduces time complexity
- Hash function -> h(k) where k is the value to be inserted, deleted or searched
    -> index = h(k)
    -> arr[index] = k
- Collision: occurs when we already have a value at an index where we're supposed to insert a new value
    -> How to avoid collision: 
        1. Linear Probing -> h(k)+i
        2. Quadratic Probing -> h(k)+(i*i)
        3. Double Hashing
- Often used for efficient data lookup and retrieval
- Transforms data into fixed sized values
- Types:
    1. Modulo Hash Functions
    2. Folding Hash Functions
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// Initialize hash table
void initHashTable() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = EMPTY;
}

// Simple modulo hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using linear probing
void insert(int key) {
    int idx = hash(key);
    int i = 0;
    while (hashTable[(idx + i) % SIZE] != EMPTY) {
        i++;
        if (i == SIZE) {
            printf("Hash table full, cannot insert %d\n", key);
            return;
        }
    }
    hashTable[(idx + i) % SIZE] = key;
}

// Search
int search(int key) {
    int idx = hash(key);
    int i = 0;
    while (hashTable[(idx + i) % SIZE] != EMPTY && i < SIZE) {
        if (hashTable[(idx + i) % SIZE] == key) return 1;
        i++;
    }
    return 0;
}

// Delete
void deleteKey(int key) {
    int idx = hash(key);
    int i = 0;
    while (hashTable[(idx + i) % SIZE] != EMPTY && i < SIZE) {
        if (hashTable[(idx + i) % SIZE] == key) {
            hashTable[(idx + i) % SIZE] = EMPTY;
            return;
        }
        i++;
    }
}

// Display
void display() {
    printf("Hash Table: \n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("[%d] = %d\n", i, hashTable[i]);
        else
            printf("[%d] = EMPTY\n", i);
    }
}

// Main
int main() {
    initHashTable();

    insert(12);
    insert(22);
    insert(32);
    insert(42);

    display();

    printf("Search 22: %d\n", search(22));
    printf("Search 99: %d\n", search(99));

    deleteKey(22);
    printf("After deleting 22:\n");
    display();

    return 0;
}