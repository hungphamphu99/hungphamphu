#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1; // Assuming -1 represents an error condition
    }
    return stack->arr[stack->top--];
}

void insertionSortWithStack(struct Stack* stack) {
    struct Stack temp;
    initStack(&temp);

    while (stack->top != -1) {
        int current = pop(stack);

        while (temp.top != -1 && temp.arr[temp.top] > current) {
            push(stack, temp.arr[temp.top]);
            pop(&temp);
        }

        push(&temp, current);
    }

    while (temp.top != -1) {
        push(stack, temp.arr[temp.top]);
        pop(&temp);
    }
}

int main() {
    struct Stack stk;
    initStack(&stk);

    push(&stk, 9);
    push(&stk, 5);
    push(&stk, 7);
    push(&stk, 1);
    push(&stk, 3);

    insertionSortWithStack(&stk);

    printf("Sorted stack: ");
    while (stk.top != -1) {
        printf("%d ", pop(&stk));
    }

    return 0;
}
