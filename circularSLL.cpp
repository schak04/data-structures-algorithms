/*
Circular Singly Linked List (CSLL) in C++

- The last node points back to the head (forming a circle).
- Supports insertion at beginning, end, specific position.
- Supports deletion at beginning, end, specific position.
- Can display the entire list and search for values.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head) return;
        Node* temp = head;
        Node* current = head->next;
        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at beginning
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at specific position (1-based index)
    void insertAtPos(int pos, int val) {
        if (pos < 1) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1) {
            insertBegin(val);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count != pos - 1) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteBegin() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head)
            temp = temp->next;

        Node* toDelete = temp->next;
        temp->next = head;
        delete toDelete;
    }

    // Delete from specific position (1-based index)
    void deleteAtPos(int pos) {
        if (!head || pos < 1) {
            cout << "Invalid operation\n";
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head || count != pos - 1) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    // Search for a value
    bool search(int val) {
        if (!head) return false;

        Node* temp = head;
        do {
            if (temp->data == val)
                return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }
};

// Example usage
int main() {
    CircularLinkedList cll;

    cll.insertEnd(10);
    cll.insertEnd(20);
    cll.insertBegin(5);
    cll.insertAtPos(2, 15);
    cll.display();  // 5 15 10 20

    cll.deleteBegin();
    cll.deleteEnd();
    cll.deleteAtPos(2);
    cll.display();  // 15

    cout << (cll.search(15) ? "Found" : "Not Found") << "\n";  // Found
    cout << (cll.search(100) ? "Found" : "Not Found") << "\n"; // Not Found

    return 0;
}
