/*
Trie (Prefix Tree) Implementation in C++
- A Trie stores strings efficiently for fast prefix search.
- Each node represents a character, and paths from root to nodes
  represent strings.
- Supports insert, search, and delete operations.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search a word in the Trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Delete a word from the Trie
    bool removeHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return node->children.empty();
        }

        char ch = word[depth];
        if (!removeHelper(node->children[ch], word, depth + 1))
            return false;

        delete node->children[ch];
        node->children.erase(ch);
        return !node->isEndOfWord && node->children.empty();
    }

    void remove(const string& word) {
        removeHelper(root, word, 0);
    }
};

// Demo main
int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("helium");

    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'helium': " << (trie.search("helium") ? "Found" : "Not Found") << endl;
    cout << "Search 'hero': " << (trie.search("hero") ? "Found" : "Not Found") << endl;

    trie.remove("helium");
    cout << "After removing 'helium', search 'helium': " 
         << (trie.search("helium") ? "Found" : "Not Found") << endl;

    return 0;
}