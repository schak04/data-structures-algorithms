/*
 * Stack Implementation using Array
 * 
 * A stack is a LIFO (Last In First Out) data structure.
 * isEmpty() -> Underflow, if we try to pop
 * isFull() -> Overflow, if we try to push
 */

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> arr;
    int top;
    static constexpr int MAX = 100;

public:
    /**
     * Constructor
     */
    Stack() : top(-1) {
        arr.resize(MAX);
    }

    /**
     * Check if stack is empty
     */
    bool isEmpty() const {
        return top == -1;
    }

    /**
     * Check if stack is full
     */
    bool isFull() const {
        return top == MAX - 1;
    }

    /**
     * Push element onto stack
     * @param value Value to push
     */
    void push(int value) {
        if (isFull()) {
            std::cout << "Cannot push. Stack is already full." << std::endl;
            return;
        }
        std::cout << "Element successfully pushed: " << value << std::endl;
        arr[++top] = value;
    }

    /**
     * Pop element from stack
     * @return Popped value, or -1 if empty
     */
    int pop() {
        if (isEmpty()) {
            std::cout << "Cannot pop. Stack is already empty." << std::endl;
            return -1;
        }
        std::cout << "Element successfully popped: " << arr[top] << std::endl;
        return arr[top--];
    }

    /**
     * Peek at top element
     */
    void peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return;
        }
        std::cout << "Element at the top: " << arr[top] << std::endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.peek();
    stack.push(20);
    stack.peek();
    stack.push(30);
    stack.peek();
    stack.push(40);
    stack.peek();
    stack.push(50);
    stack.peek();
    stack.push(60);
    stack.peek();

    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();

    return 0;
}

