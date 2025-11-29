/*
 * Hash Table - Basic Implementation
 * 
 * Hash tables reduce time complexity for data lookup and retrieval.
 * Hash function: h(k) where k is the value
 *   -> index = h(k)
 *   -> arr[index] = k
 * 
 * Collision resolution methods:
 *   1. Linear Probing -> h(k) + i
 *   2. Quadratic Probing -> h(k) + (i*i)
 *   3. Double Hashing
 * 
 * Hash function types:
 *   1. Modulo Hash Functions
 *   2. Folding Hash Functions
 */

#include <iostream>
#include <vector>
#include <string>

class HashTable {
private:
    static constexpr int TABLE_SIZE = 10;
    std::vector<int> table;
    static constexpr int EMPTY = -1;

    /**
     * Hash function using modulo operation
     * @param key Key to hash
     * @return Hash index
     */
    int hash(int key) const {
        return key % TABLE_SIZE;
    }

public:
    /**
     * Constructor
     */
    HashTable() : table(TABLE_SIZE, EMPTY) {}

    /**
     * Insert a key into the hash table (basic, no collision handling)
     * @param key Key to insert
     */
    void insert(int key) {
        int index = hash(key);
        if (table[index] == EMPTY) {
            table[index] = key;
            std::cout << "Key " << key << " inserted at index " << index << std::endl;
        } else {
            std::cout << "Collision at index " << index << " for key " << key << std::endl;
        }
    }

    /**
     * Search for a key in the hash table
     * @param key Key to search
     * @return true if found, false otherwise
     */
    bool search(int key) const {
        int index = hash(key);
        return table[index] == key;
    }

    /**
     * Display the hash table
     */
    void display() const {
        std::cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != EMPTY) {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            } else {
                std::cout << "Index " << i << ": ~" << std::endl;
            }
        }
    }
};

int main() {
    HashTable ht;

    std::cout << "=== Basic Hash Table Demo ===\n\n";

    // Insert keys
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(7);
    ht.insert(17);

    std::cout << "\n";
    ht.display();

    // Search for keys
    std::cout << "\nSearching for key 15: " << (ht.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for key 20: " << (ht.search(20) ? "Found" : "Not Found") << std::endl;

    std::cout << "\nNote: This is a basic implementation without collision resolution.\n";
    std::cout << "For collision handling, see LinearProbing.cpp and QuadraticProbing.cpp\n";

    return 0;
}

