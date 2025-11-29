/*
 * Priority Queue Implementation using Linked List
 * 
 * A priority queue where elements with lower priority values are dequeued first.
 * Elements are maintained in sorted order by priority.
 */

#include <iostream>

class PriorityQueue {
private:
    struct Node {
        int data;
        int priority;
        Node* next;
        
        Node(int d, int p) : data(d), priority(p), next(nullptr) {}
    };

    Node* head;

public:
    /**
     * Constructor
     */
    PriorityQueue() : head(nullptr) {}

    /**
     * Destructor
     */
    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    /**
     * Check if priority queue is empty
     */
    bool isEmpty() const {
        return head == nullptr;
    }

    /**
     * Add element with priority to the queue
     * Elements are inserted in sorted order by priority (lower priority first)
     * @param data Element value
     * @param priority Priority value (lower = higher priority)
     */
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // Special case: empty queue or new node has higher priority than head
        if (head == nullptr || head->priority > priority) {
            newNode->next = head;
            head = newNode;
        } else {
            // Traverse to find the appropriate position
            Node* temp = head;
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    /**
     * Remove the highest priority node (lowest priority value)
     */
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        std::cout << "Dequeued: " << temp->data 
                  << " (priority: " << temp->priority << ")" << std::endl;
        delete temp;
    }

    /**
     * Get the front element without removing it
     * @return Front element's data, or -1 if empty
     */
    int peek() const {
        if (isEmpty()) {
            std::cout << "No element at the front." << std::endl;
            return -1;
        }
        return head->data;
    }

    /**
     * Display all elements in the priority queue
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty." << std::endl;
            return;
        }

        std::cout << "Priority Queue (data, priority): ";
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "(" << temp->data << "," << temp->priority << ") ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueue pq;

    // Enqueue elements with priorities
    pq.enqueue(10, 3);
    pq.enqueue(20, 1); // Higher priority (lower value)
    pq.enqueue(30, 4);
    pq.enqueue(40, 2);

    pq.display();

    std::cout << "Front element: " << pq.peek() << std::endl;

    pq.dequeue();
    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}

