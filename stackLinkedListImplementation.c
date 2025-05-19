#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack* )malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Note: No use of creating isFull() function because a linked list can never be 'full'

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next=stack->top;
    stack->top=newNode;
    printf("Value inserted in the node: %d\n", value);
}

void pop(struct Stack* stack) {
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top=stack->top->next;
    free(temp);
    printf("Value popped from the node: %d\n", popped);
}

void peek(struct Stack* stack) {
    printf("Element at top: %d\n", *stack->top);
}

void displayStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    printf("Stack:\n");
    while (temp!=NULL) {
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    // peek(stack);
    push(stack, 20);
    // peek(stack);
    push(stack, 30);
    // peek(stack);
    push(stack, 40);
    // peek(stack);
    displayStack(stack);

    pop(stack);
    // peek(stack);
    pop(stack);
    // peek(stack);
    pop(stack);
    // peek(stack);
    pop(stack);
    // peek(stack);

    return 0;
}