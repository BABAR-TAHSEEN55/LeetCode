#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack *link;
};

struct Stack *top = NULL;

void Push(int x) {
    struct Stack *newnode;
    newnode = (struct Stack *)(malloc(sizeof(struct Stack)));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void Pop() {
    if (top == 0) {
        printf("Underflow: Stack is empty.\n");
        return;
    }
    struct Stack *temp = top;
    printf("Popped Element: %d\n", top->data);
    top = top->link;
    free(temp);
}

void Display() {
    if (top == 0) {
        printf("Stack is empty.\n");
        return;
    }
    struct Stack *temp = top;
    printf("Elements in the Stack:\n");
    while (temp != 0) {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}

void Peek() {
    if (top == 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top Element: %d\n", top->data);
}

int main() {
    // Push(5);
    // Push(3);
    // Push(6);
    Display();
    Pop();
    Display();
    Peek();
    return 0;
}
