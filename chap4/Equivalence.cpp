#include <iostream>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

class ENode {
    friend void Equivalence();
    friend void PrintEq(ENode **l, int n);
public:
    ENode(int d = 0) // constructor
        {data = d; link = 0;}
    ENode(int d, ENode *p = 0)
        {
            data = d; 
            if (p) {
                link = p;
                p = this;
            } else
            {
                link = nullptr;
            }
            
        }
private:
    int data;
    ENode *link;
};

void PrintEq(ENode **l, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        ENode *p = *(l+i);
        cout << "first[" << i << "]->";
        while (p) {
            cout << "\"" << p->data << "\"->";
            p = p->link;
        }
        cout << "NULL" << endl;
    }
}

void Equivalence()
{
    // Input the equivalence pairs and output the equivalence classes.
    std::ifstream inFile("equiv.in", ios::in); // "equiv.in" is the input file
    if (!inFile) throw "Cannot open input file.";
    int i, j, n;
    inFile >> n;    // read number of objects
    
    // initialize first and out
    ENode **first = new ENode* [n];
    bool *out = new bool[n];
    // use STL function fill to initialize
    for (i = 0; i < n; i++)
        *(first + i) = nullptr;
    fill(out, out + n, false);

    // Phase 1: input equivalence pairs
    while (inFile.good()) {
        inFile >> i >> j;
        first[i] = new ENode(j, first[i]);
        first[j] = new ENode(i, first[j]);
        cout << "i: " << i << ", j: " << j << endl;
    }
    PrintEq(first, n);
    // Phase 2: output equivalence classes
    for (i = 0; i < n; i++) {
        if (!out[i]) {// needs to be classes
            cout << endl << "A new class: " << i;
            out[i] = true;
            ENode *x = first[i]; ENode *top = 0; // initialize stack
            while(1) { // find rest of class
                while (x) { // process the list
                    j = x->data;
                    if (!out[j]) {
                        cout << ", " << j;
                        out[j] = true;
                        ENode *y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    } else {
                        x = x->link;
                    }
                } // end of while(x)
                if (!top)
                    break;
                x = first[top->data];
                ENode *p = top;
                top = top->link;    // unstack
                delete p;
            }   // end of while(1)
        }   // end of if (!out[i])
    }
    cout << endl;
        /*
    for (i = 0; i < n; i++)
        while (first[i]) {
            ENode *delnode = first[i];
            first[i] = delnode->link;
            delete delnode;
        }
    delete []first; delete [] out;
    */
}

int main(int argc, char const *argv[])
{
    Equivalence();
    return 0;
}
