#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 5  // Must be > 1 for meaningful usage

typedef struct {
    int data[BUFFER_SIZE];
    int head;  // Write position
    int tail;  // Read position
    int size;  // Number of items currently in buffer
} RingBuffer;

// --- Initialize the buffer ---
void init(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->size = 0;
}

// --- Check if full ---
bool is_full(RingBuffer *rb) {
    return rb->size == BUFFER_SIZE;
}

// --- Check if empty ---
bool is_empty(RingBuffer *rb) {
    return rb->size == 0;
}

// --- Enqueue / Push ---
bool push(RingBuffer *rb, int value) {
    if (is_full(rb)) return false;

    rb->data[rb->head] = value;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->size++;
    return true;
}

// --- Dequeue / Pop ---
bool pop(RingBuffer *rb, int *value) {
    if (is_empty(rb)) return false;

    *value = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->size--;
    return true;
}

// --- Peek front value (optional) ---
bool peek(RingBuffer *rb, int *value) {
    if (is_empty(rb)) return false;
    *value = rb->data[rb->tail];
    return true;
}

// --- Demo ---
int main() {
    RingBuffer rb;
    init(&rb);

    // Push some values
    for (int i = 1; i <= BUFFER_SIZE; i++) {
        if (push(&rb, i))
            printf("Pushed: %d\n", i);
        else
            printf("Buffer full, couldn't push %d\n", i);
    }

    // Pop all values
    int val;
    while (pop(&rb, &val)) {
        printf("Popped: %d\n", val);
    }

    return 0;
}
