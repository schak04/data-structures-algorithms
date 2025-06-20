#include <stdio.h>
#include <stdlib.h>

// isEmpty() --> Underflow, if we try to pop
// isFull() --> Overflow, if we try to push

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

// initialise stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// functions to check boundary cases
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX-1;
}

// push and pop functions
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Cannot push. Stack is already full.");
        return;
    }
    printf("Element successfully pushed: %d\n", value);
    stack->arr[++stack->top] = value;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Cannot pop. Stack is already empty.\n");
        return -1;
    }
    printf("Element successfully popped: %d\n", stack->arr[stack->top--]);
    return 0;
}

// peek function
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    printf("Element at the top: %d\n", stack->arr[stack->top]);
}

int main() {
    struct Stack stack;
    initStack(&stack);
    push(&stack, 10);
    peek(&stack);
    push(&stack, 20);
    peek(&stack);
    push(&stack, 30);
    peek(&stack);
    push(&stack, 40);
    peek(&stack);
    push(&stack, 50);
    peek(&stack);
    push(&stack, 60);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    peek(&stack);
    return 0;
}