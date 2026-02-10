#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

// Function to push element
void push(int element) {
    if (top == SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed into stack.\n", element);
    }
}

// Function to pop element
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Function to display stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    
    pop();
    
    display();
    
    return 0;
}
