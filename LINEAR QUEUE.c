#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

// Structure to represent the queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to create a queue and initialize front and rear
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        return 1;
    }
    return 0;
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // First element enqueued
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    } else {
        value = queue->items[queue->front];
        queue->front++;
        printf("Dequeued %d\n", value);
        return value;
    }
}

// Function to display the queue elements
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    display(queue);  // Display the queue

    dequeue(queue);
    dequeue(queue);

    display(queue);  // Display the queue after dequeue operations

    enqueue(queue, 60);  // Try to enqueue an element when the queue is full

    return 0;
}
