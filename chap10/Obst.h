#ifndef _OBST_H_
#define _OBST_H_

using namespace std;
class BST;

class BSTNode {
    friend class BST;
public:
    BSTNode(int value = 0, BSTNode* left = nullptr, BSTNode* right = nullptr):data(value), leftChild(left), rightChild(right){}
private:
    int data;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

class BST {
public:
    BST();
    void Obst(double *, double *, int);
    int KnuthMin(int i, int j);
};

#endif
