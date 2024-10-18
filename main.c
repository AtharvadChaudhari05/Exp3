

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;
void initialize(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int getFront(Queue *q);
int getRear(Queue *q);
void display(Queue *q);
int main() {
    Queue q;
    int choice, value;
    initialize(&q);
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front\n");
        printf("4. Get Rear\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Check if Queue is Full\n");
        printf("7. Display Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull(&q)) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter the item to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    printf("Enqueued %d\n", value);
                }
                display(&q);
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    printf("Dequeued value: %d\n", dequeue(&q));
                }
                display(&q);
                break;
            case 3:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Front value: %d\n", getFront(&q));
                }
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Rear value: %d\n", getRear(&q));
                }
                break;
            case 5:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                if (isFull(&q)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 7:
                display(&q);
                break;
            case 8:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    }
    return 0;
}
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->items[++(q->rear)] = value;
        printf("%d enqueued into queue.\n", value);
    }
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        return q->items[(q->front)++];
    }
}
int getFront(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}
int getRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return q->items[q->rear];
    }
}
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}




