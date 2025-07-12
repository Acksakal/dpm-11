#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct Stack Stack;

struct Stack {
    int len;
    Node *head;
    void (*push)(Stack *, int item);
    int (*pop)(Stack *);
    int (*peek)(Stack *);
};

void push(Stack *s, int item) {
    Node *new_node = malloc(sizeof(Node));
    new_n ode->value = item;
    new_node->next = s->head;
    s->head = new_node;
    s->len++;
}

int pop(Stack *s) {
    if (!s->head) return -1;
    Node *temp = s->head;
    int val = temp->value;
    s->head = temp->next;
    free(temp);
    s->len--;
    return val;
}

int peek(Stack *s) {
    return s->head ? s->head->value : -1;
}

int main() {
    Stack *s = malloc(sizeof(Stack));
    s->len = 0;
    s->head = NULL;
    s->push = push;
    s->pop = pop;
    s->peek = peek;

    s->push(s, 5);
    s->push(s, 10);

    printf("Peek: %d\n", s->peek(s));
    ("Popped: %d\n", s->pop(s));
    ("Peek after pop: %d\n", s->peek(s));
    
    free(s);
    return 0;
}
