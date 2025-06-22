/*
Circular Doubly Linked List (CDLL) in C++

- Each node has both next and prev pointers.
- Last node's next points to head, and head's prev points to last.
- Supports insertion and deletion at head, tail, and specific positions.
- Supports forward and reverse traversal.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    ~CircularDoublyLinkedList() {
        if (!head) return;
        Node* curr = head->next;
        while (curr != head) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        delete head;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    // Insert at beginning
    void insertBegin(int val) {
        insertEnd(val);
        head = head->prev; // move head to new node
    }

    // Insert at specific position (1-based)
    void insertAtPos(int pos, int val) {
        if (pos <= 1 || !head) {
            insertBegin(val);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head) {
            insertEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
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

        Node* last = head->prev;
        Node* temp = head;

        head = head->next;
        head->prev = last;
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

        Node* last = head->prev;
        Node* newLast = last->prev;

        newLast->next = head;
        head->prev = newLast;

        delete last;
    }

    // Delete from specific position (1-based)
    void deleteAtPos(int pos) {
        if (!head || pos <= 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < pos && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp == head) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete temp;
    }

    // Display forward
    void displayForward() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Forward: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    // Display reverse
    void displayReverse() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* last = head->prev;
        Node* temp = last;

        cout << "Reverse: ";
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != last);
        cout << "\n";
    }
};

// Example usage
int main() {
    CircularDoublyLinkedList cdll;

    cdll.insertEnd(10);
    cdll.insertEnd(20);
    cdll.insertBegin(5);
    cdll.insertAtPos(2, 15);  // After 5

    cdll.displayForward();   // 5 15 10 20
    cdll.displayReverse();   // 20 10 15 5

    cdll.deleteBegin();
    cdll.deleteEnd();
    cdll.deleteAtPos(2);

    cdll.displayForward();   // 15
    cdll.displayReverse();   // 15

    return 0;
}
