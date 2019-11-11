#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "MatrixNode.h"
#include <istream>

using namespace std;

class Matrix {
friend istream& operator>>(istream&, Matrix&);
public:
    ~Matrix() {} // destructor
    int getRow() {return headnode->triple.row;};
    int getCol() {return headnode->triple.col;};
    int getTotal() {return headnode->triple.value;};
    MatrixNode* getRight() {return headnode->right;}
private:
    MatrixNode *headnode;
    static MatrixNode *av;
};

#endif