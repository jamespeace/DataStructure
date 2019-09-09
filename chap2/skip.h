#ifndef _SKIP_H_
#define _SKIP_H_

#define ASIZE 300


struct _cell
{
    int element;
    struct _cell *next;
};

typedef struct _cell *List;

#endif