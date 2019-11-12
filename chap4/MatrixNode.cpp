#include "MatrixNode.h"

MatrixNode::MatrixNode(bool b, Triple *t) // constructor
{
    head = b;
    if (b) {next = right = down = this;} // row/column header node
    else triple = *t; // element node or header node for list of header nodes
}


