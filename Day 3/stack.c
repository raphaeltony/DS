#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int top = -1, stack[MAXSIZE];

void push() {
    int item;
    if (top == MAXSIZE - 1)
        printf("\nOverflow/Stack is full");
    else {
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &item);
        stack[++top] = item;
    }
}

void pop() {
    if (top == -1)
        printf("\nUnderflow/Stack is empty");
    else
        printf("\nElement popped : %d", stack[top--]);
}

int peek() { return stack[top]; }

void isfull() {
    if (top == MAXSIZE - 1)
        printf("\nStack is full");
    else
        printf("\nStack is not full");
}

void isempty() {
    if (top == -1)
        printf("Stack is empty");
    else
        printf("\nStack is not empty");
}

void display() {
    int i;
    if (top == -1)
        printf("\nUnderflow/Stack is empty");
    else {
        printf("\nElements present in the stack\n");
        for (i = top; i >= 0; --i) printf("%d\n", stack[i]);
    }
}
int main() {
    int opt, a;
    char ch;
    while (1) {
        printf(
            "\nChoose an option "
            "(1-6):\n1.Push\n2.Pop\n3.Peek\n4.Isempty\n5.Isfull\n6.Display\n7."
            "Exit\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                a = peek();
                printf("Topmost element : %d", a);
                break;
            case 4:
                isempty();
                break;
            case 5:
                isfull();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice!!");
        }
        printf("\n");
    }

    return 0;
}