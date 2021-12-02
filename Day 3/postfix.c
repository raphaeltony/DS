#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 30

int top = -1;
char stack[MAXSIZE];

void push(char item) {
    if (top == MAXSIZE - 1)
        printf("\nOverflow/Stack is full");
    else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        printf("Underflow. Invalid Expression");
        return '$';
    } else
        return stack[top--];
}

int getPriority(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            break;
    }
}

void performOperation(char operator) {
    int a = pop();
    int b = pop();
    switch (operator) {
        case '+':
            push(b + a);
            break;

        case '-':
            push(b - a);
            break;

        case '*':
            push(b * a);
            break;

        case '/':
            push(b / a);
            break;

        default:
            break;
    }
}

void evaluate(char postfix[]) {
    int i = 0, numActive = 0;
    int num = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            numActive = 1;
            num = num * 10 + (postfix[i] - '0');
        } else if (postfix[i] == ' ') {
            if (numActive) {
                push(num);
                num = 0;
                numActive = 0;
            }
        } else {
            performOperation(postfix[i]);
        }
        i++;
    }
    printf("\nEvaluates to : %d", pop());
}

int main() {
    int i = 0, j = 0;
    char infix[30], postfix[60];
    printf("\nEnter Infix Expression :\n");
    scanf("%s", infix);

    push('(');
    strcat(infix, ")");
    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push('(');
        } else if (infix[i] == ')') {
            char ele = pop();
            while (ele != '(') {
                postfix[j++] = ' ';
                postfix[j++] = ele;
                ele = pop();
            }
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' ||
                   infix[i] == '/') {
            postfix[j++] = ' ';
            while (getPriority(infix[i]) <= getPriority(stack[top])) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(infix[i]);
        } else if (isdigit(infix[i])) {
            postfix[j] = infix[i];
            j++;
        }
        i++;
    }
    postfix[j] = '\0';
    printf("Postfix Expression : %s", postfix);
    evaluate(postfix);

    return 0;
}