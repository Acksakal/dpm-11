#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct Queue Queue;

struct Queue {
    int len;
    Node *head;
    Node *tail;
    void (*enqueue)(Queue *, int item);
    int (*dequeue)(Queue *);
    int (*peek)(Queue *);
};

void enqueue(Queue *q, int item) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = item;
    new_node->next = NULL;
    
    if (q->tail) {
	q->tail->next = new_node;
    } else {
	q->head = new_node;
    }

    q->tail = new_node;
    q->len++;
}

int dequeue(Queue *q) {
    if (q->head == NULL) return -1;
    Node *temp = q->head;
    int val = temp->value;
    q->head = temp->next;

    if (q->head == NULL) q->tail = NULL;
    free(temp);
    q->len--;
    return val;
}

int peek(Queue *q) {
    return q->head ? q->head->value: -1;
}


int main() {
    Queue *q = malloc(sizeof(Queue));
    q->len = 0;
    q->head = q->tail = NULL;
    q->enqueue = enqueue;
    q->dequeue = dequeue;
    q->peek = peek;

    q->enqueue(q, 5);
    q->enqueue(q, 10);

    printf("Peek: %d\n", q->peek(q));
    printf("Dequeued: %d\n", q->dequeue(q));
    printf("Dequeued: %d\n", q->dequeue(q));
    printf("Dequeued: %d\n", q->dequeue(q));

    free(q);
    return 0;
}
