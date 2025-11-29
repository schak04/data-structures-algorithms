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
     static constexpr int DELETED = -2; // mark deleted slots
 
     int hash(int key) const {
         return key % TABLE_SIZE;
     }
 
 public:
     HashTable() : table(TABLE_SIZE, EMPTY) {}
 
     // Insert with linear probing
     void insert(int key) {
         int index = hash(key);
         int i = 0;
 
         while (table[(index + i) % TABLE_SIZE] != EMPTY && table[(index + i) % TABLE_SIZE] != DELETED) {
             i++;
             if (i == TABLE_SIZE) {
                 std::cout << "Hash table full, cannot insert " << key << std::endl;
                 return;
             }
         }
         table[(index + i) % TABLE_SIZE] = key;
         std::cout << "Key " << key << " inserted at index " << (index + i) % TABLE_SIZE << std::endl;
     }
 
     // Search with linear probing
     bool search(int key) const {
         int index = hash(key);
         int i = 0;
         while (table[(index + i) % TABLE_SIZE] != EMPTY && i < TABLE_SIZE) {
             if (table[(index + i) % TABLE_SIZE] == key)
                 return true;
             i++;
         }
         return false;
     }
 
     // Delete a key (linear probing)
     void remove(int key) {
         int index = hash(key);
         int i = 0;
         while (table[(index + i) % TABLE_SIZE] != EMPTY && i < TABLE_SIZE) {
             if (table[(index + i) % TABLE_SIZE] == key) {
                 table[(index + i) % TABLE_SIZE] = DELETED;
                 std::cout << "Key " << key << " deleted from index " << (index + i) % TABLE_SIZE << std::endl;
                 return;
             }
             i++;
         }
         std::cout << "Key " << key << " not found for deletion.\n";
     }
 
     void display() const {
         std::cout << "Hash Table:\n";
         for (int i = 0; i < TABLE_SIZE; i++) {
             if (table[i] == EMPTY)
                 std::cout << "Index " << i << ": ~\n";
             else if (table[i] == DELETED)
                 std::cout << "Index " << i << ": deleted\n";
             else
                 std::cout << "Index " << i << ": " << table[i] << "\n";
         }
     }
 };
 
 int main() {
     HashTable ht;
 
     std::cout << "=== Hash Table with Linear Probing Demo ===\n\n";
 
     ht.insert(5);
     ht.insert(15);
     ht.insert(25);
     ht.insert(7);
     ht.insert(17);
 
     std::cout << "\nInitial table:\n";
     ht.display();
 
     std::cout << "\nSearch 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
     std::cout << "Search 20: " << (ht.search(20) ? "Found" : "Not Found") << "\n";
 
     ht.remove(15);
     ht.remove(7);
 
     std::cout << "\nAfter deletions:\n";
     ht.display();
 
     return 0;
 } 