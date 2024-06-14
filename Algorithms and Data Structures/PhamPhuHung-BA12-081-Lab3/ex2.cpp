#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Website {
    char url[100];
    char title[100];
};

struct Stack {
    struct Website stackArray[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(const struct Stack* stack) {
    return stack->top == -1;
}

int isFull(const struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, struct Website website) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push website.\n");
    } else {
        stack->top++;
        stack->stackArray[stack->top] = website;
    }
}

struct Website pop(struct Stack* stack) {
    struct Website emptyWebsite = { "", "" };

    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop website.\n");
        return emptyWebsite;
    } else {
        return stack->stackArray[stack->top--];
    }
}

struct Website peek(const struct Stack* stack) {
    struct Website emptyWebsite = { "", "" };

    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek website.\n");
        return emptyWebsite;
    } else {
        return stack->stackArray[stack->top];
    }
}

int main() {
    struct Stack backwardStack;
    struct Stack forwardStack;

    initStack(&backwardStack);
    initStack(&forwardStack);

    struct Website google = { "https://www.google.com", "Google" };
    struct Website github = { "https://www.github.com", "GitHub" };
    struct Website facebook = { "https://www.facebook.com", "Facebook" };

    push(&backwardStack, google);
    push(&backwardStack, github);
    push(&backwardStack, facebook);

    printf("Current website: %s\n", peek(&backwardStack).title);

    struct Website previousWebsite = pop(&backwardStack);
    push(&forwardStack, previousWebsite);

    printf("Current website: %s\n", peek(&backwardStack).title);

    if (!isEmpty(&forwardStack)) {
        struct Website nextWebsite = pop(&forwardStack);
        push(&backwardStack, nextWebsite);
    }

    printf("Current website: %s\n", peek(&backwardStack).title);

    return 0;
}
