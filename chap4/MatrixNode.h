#ifndef _MATRIXNODE_H_
#define _MATRIXNODE_H_
#include <iostream>
#include <istream>
using namespace std;

struct Triple {int row, col, value;};
class Matrix; // forward declaration
class MatrixNode {
friend class Matrix;
friend istream& operator>>(istream&, Matrix&); // for reading in a matrix
public:
    MatrixNode *getNext() {return next;}
    MatrixNode *getDown() {return down;}
    MatrixNode *getRight() {return right;}
    bool isHead() {return head;}
    void PrintTriple() {cout << "[" << triple.row << "][" << triple.col << "] = " << triple.value << endl;}
private:
    MatrixNode *down, *right;
    bool head;
    union { // anonymous union
        MatrixNode *next;
        Triple triple;
    };
    MatrixNode(bool, Triple*); // constructor
};

#endif