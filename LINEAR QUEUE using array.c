#include <stdio.h>
#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to enqueue an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (front == -1) {
            front = 0;  // Initialize front if it's the first element
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
    } else {
        printf("Dequeued %d\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}
