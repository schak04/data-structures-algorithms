/*
 * Hash Table with Linear Probing
 * 
 * Collision resolution using linear probing: h(k) + i
 * where i is the probe number (increments by 1 each time).
 */

#include <iostream>
#include <vector>

class HashTableLinear {
private:
    static constexpr int TABLE_SIZE = 10;
    std::vector<int> table;
    static constexpr int EMPTY = -1;

    /**
     * Hash function using modulo operation
     */
    int hash(int key) const {
        return key % TABLE_SIZE;
    }

public:
    /**
     * Constructor
     */
    HashTableLinear() : table(TABLE_SIZE, EMPTY) {}

    /**
     * Insert a key using linear probing for collision resolution
     * @param key Key to insert
     */
    void insert(int key) {
        int index = hash(key);
        int originalIndex = index;

        // Linear probing: move to next slot if collision
        while (table[index] != EMPTY) {
            index = (index + 1) % TABLE_SIZE; // Move to the next slot
            if (index == originalIndex) {
                std::cout << "Hash table is full, cannot insert key " << key << std::endl;
                return;
            }
        }

        table[index] = key; // Insert the key
        std::cout << "Key " << key << " inserted at index " << index << std::endl;
    }

    /**
     * Search for a key in the hash table
     * @param key Key to search
     * @return true if found, false otherwise
     */
    bool search(int key) const {
        int index = hash(key);
        int originalIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return true; // Key found
            }
            index = (index + 1) % TABLE_SIZE; // Move to the next slot
            if (index == originalIndex) {
                break; // Full loop, key not found
            }
        }
        return false; // Key not found
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
    HashTableLinear ht;

    // Insert keys into the hash table
    ht.insert(23);
    ht.insert(43);
    ht.insert(13);
    ht.insert(27);
    ht.insert(33);

    std::cout << "\n";
    ht.display();

    // Search for keys
    int keyToSearch = 43;
    std::cout << "\nSearching for key " << keyToSearch << ": ";
    if (ht.search(keyToSearch)) {
        std::cout << "Key " << keyToSearch << " found in the hash table." << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " not found in the hash table." << std::endl;
    }

    keyToSearch = 50;
    std::cout << "Searching for key " << keyToSearch << ": ";
    if (ht.search(keyToSearch)) {
        std::cout << "Key " << keyToSearch << " found in the hash table." << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " not found in the hash table." << std::endl;
    }

    return 0;
}

