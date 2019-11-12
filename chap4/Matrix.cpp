#include <iostream>
#include <bits/stdc++.h> 
#include "Matrix.h"
#include "MatrixNode.h"

using namespace std;

Matrix::~Matrix()
{
    // Return all notes to the av list. This list is a chain liked via the right field.
    // av is a static variable that points to the first node of the av list.
    if (!headnode) return; // no nodes to delete
    MatrixNode *x = headnode->right;
    headnode->right = av; av = headnode;    // return headnode
    while (x != headnode) { // erase by rows
        MatrixNode *y = x->right;
        MatrixNode *p = y;
        while (p->right != x)
            p = p->right;
        p->right = av;
        av = y;
        x = x->next; // next row
    }
    headnode = 0;
}
istream& operator>>(istream& is, Matrix& matrix)
{
    // Read in a matrix and set up its linked representation.
    Triple s;
    int i;
    is >> s.row >> s.col >> s.value; // matrix dimensions
    int p = max(s.row, s.col);

    //set up header node for list of header nodes.
    if (p == 0) {
        matrix.headnode->right = matrix.headnode; return is;
    }

    // at least one row or column
    MatrixNode **head = new MatrixNode*[p];
    for (i = 0; i < p; i++) {
        head[i] = new MatrixNode(true, 0);
    }
    int currentRow = 0;
    MatrixNode *last = head[0]; // last node in current row

    for (i = 0; i < s.value; i++) { // input triples
        Triple t;
        is >> t.row >> t.col >> t.value;
        if (t.row > currentRow) { // close current row
            last->right = head[currentRow];
            currentRow = t.row;
            last = head[currentRow];
        } // end of if
        // link new node into row list
        last = last->right = new MatrixNode(false, &t); 
        // link new node into col list
        // using pointer "next" to point to the last col
        //
        head[t.col]->next = head[t.col]->next->down = last;
    } // end of for
    // close last row
    last->right = head[currentRow];
    // close all column lists
    for (i = 0; i < s.col; i++)  head[i]->next->down = head[i];

    // link the header nodes together

    for (i = 0; i < p-1; i++)
        head[i]->next = head[i+1];
    matrix.headnode = new MatrixNode(false, &s);
    head[p-1]->next = matrix.headnode;
    matrix.headnode->right = head[0];
    delete []head;
    return is;
}

int main(int argc, char const *argv[])
{
    Matrix m;
    filebuf in;
    if (!in.open("Matrix.in", ios::in)) throw "Cannot open file.";
    istream(&in) >> m;

    cout << "Start test..." << endl;
    cout << "Head information." << endl;
    cout << "row: " << m.getRow() << ", col: " << m.getCol() << ", total: " << m.getTotal() << endl;
    // row test
    cout << "=================" << endl;
    cout << "=== Row test. ===" << endl;
    cout << "=================" << endl;
    MatrixNode *p = m.getRight();
    MatrixNode *node;
    for (int i = 0; i < 5; i++) {
        node = p->getRight();
        while (!node->isHead()) {
            node->PrintTriple();
            node = node->getRight();
        }
        p = p->getNext();
    }
    cout << "=================" << endl;
    cout << "=== Col test. ===" << endl;
    cout << "=================" << endl;
    p = m.getRight();
    for (int i = 0; i < 5; i++) {
        node = p->getDown();
        while (!node->isHead()) {
            node->PrintTriple();
            node = node->getDown();
        }
        p = p->getNext();
    }
    return 0;
}
