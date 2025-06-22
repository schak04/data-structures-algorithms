/*
Circular Queue using Linked List in C++

- Nodes are linked circularly.
- Rear's next points to the front.
- Supports enqueue, dequeue, getFront, getRear, and display.
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    CircularQueue() {
        front = rear = nullptr;
    }

    // Destructor to clean up memory
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        cout << value << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        int removedValue;
        if (front == rear) {
            // Only one element
            removedValue = front->data;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            removedValue = temp->data;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        cout << removedValue << " dequeued\n";
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << "\n";
    }
};

// Example usage
int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    cout << "Front: " << q.getFront() << "\n";
    cout << "Rear: " << q.getRear() << "\n";

    return 0;
}
