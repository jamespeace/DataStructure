#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_QUEUE_SIZE 10

typedef struct {
    int key;
} element;

void queueFull();
element queueEmpty();
void addq(element);
element deleteq();
void copy(void *, void *, void *);
#endif