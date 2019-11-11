#ifndef _DBLLIST_H_
#define _DBLLIST_H_

class DblList;

class DblListNode {
friend class DblList;
private:
    int data;
    DblListNode *left, *right;
};

class DblList {
public:
    // List manipulation operations
    void Delete(DblListNode*);
    void Insert(DblListNode*, DblListNode*);
private:
    DblListNode *first; // points to header node
};
#endif