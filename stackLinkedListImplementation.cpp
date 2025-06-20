/*
C++ implementation of a Stack using Linked List
- Uses class-based structure instead of structs.
- Includes constructor/destructor for better memory management.
- Follows proper encapsulation principles.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Value inserted in the node: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }

        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        cout << "Value popped from the node: " << poppedValue << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Element at top: " << top->data << endl;
    }

    void displayStack() {
        Node* temp = top;
        cout << "Stack:\n";
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

/* main function to demonstrate stack operations */
int main() {
    Stack stack;

    stack.push(10);
    // stack.peek();
    stack.push(20);
    // stack.peek();
    stack.push(30);
    // stack.peek();
    stack.push(40);
    // stack.peek();

    stack.displayStack();

    stack.pop();
    // stack.peek();
    stack.pop();
    // stack.peek();
    stack.pop();
    // stack.peek();
    stack.pop();
    // stack.peek();

    return 0;
}
