#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

void Push(struct Stack *s, char ch) {
    s->items[++(s->top)] = ch;
}

char Pop(struct Stack *s) {
    return (s->top == -1) ? '\0' : s->items[(s->top)--];
}

char Peek(struct Stack *s) {
    return (s->top == -1) ? '\0' : s->items[s->top];
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

void InfixToPostfix(char *infix, char *postfix) {
    struct Stack s = {-1, {0}};
    int i = 0, j = 0;
    
    while (infix[i]) {
        if (isalnum(infix[i])) {  
            postfix[j++] = infix[i];  
        } else if (infix[i] == '(') {
            Push(&s, infix[i]);  
        } else if (infix[i] == ')') {  
            while (Peek(&s) != '(') {
                postfix[j++] = Pop(&s);
            }
            Pop(&s);  
        } else {  
            while (s.top != -1 && precedence(Peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = Pop(&s);
            }
            Push(&s, infix[i]);  
        }
        i++;
    }
    
    while (s.top != -1) {  
        postfix[j++] = Pop(&s);
    }
    postfix[j] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    
    InfixToPostfix(infix, postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    
    return 0;
}
