#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

element queue[MAX_QUEUE_SIZE];
int rear = MAX_QUEUE_SIZE - 1;
int front = MAX_QUEUE_SIZE - 1;

void addq(element item)
{
    if ((rear + 1) % MAX_QUEUE_SIZE == front)
        queueFull();
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}

element deleteq()
{
    if (front == rear)
        return queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}

void queueFull()
{
    fprintf(stderr, "Queue is full\n");
    exit(EXIT_FAILURE);
}

element queueEmpty()
{
    element e;
    e.key = -1;

    fprintf(stderr, "Queue is empty\n");
    return e;
}

int queueNumber()
{
    return (MAX_QUEUE_SIZE + rear - front) % MAX_QUEUE_SIZE;
}

int queueLens()
{
    return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element deleteK(int indexK)
{
    int start, cur, next, len;

    start     = (front +  indexK + 1) % MAX_QUEUE_SIZE;

    len = queueLens();

    for (int i = 0; i < len - 1; i++) {
        cur = (start + i) % MAX_QUEUE_SIZE;
        next = (cur + 1) % MAX_QUEUE_SIZE;
        queue[cur] = queue[next]; 
    }
    rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void queuePrint()
{
    int cur, start;
    int len = queueLens();

    start = (front + 1) % MAX_QUEUE_SIZE;
    for (int i = 0; i < len; i++) {
        cur = (start + i) % MAX_QUEUE_SIZE;
        printf("%d ", queue[cur].key);
    }
    printf("\n");
}

void addK(int indexK, element e)
{
    int end, cur, next, len;

    len = queueLens();

    printf("front = %d, rear = %d\n", front, rear);
    end = (front + 1 + indexK) % MAX_QUEUE_SIZE;

    for (cur = rear, next = (cur + 1) % MAX_QUEUE_SIZE;
         next != end;
         cur = (cur - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE,
         next = (cur + 1) % MAX_QUEUE_SIZE) {

        queue[next] = queue[cur];
    }
    queue[end] = e;
    rear = (rear + 1) % MAX_QUEUE_SIZE;
}

