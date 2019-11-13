enum Triple {var, ptr, no};
class PolyNode {
    PolyNode *next;         // link field
    int exp;
    Triple trio;
    union {
        char vble;
        PolyNode *down;     // link field
        int coef;
    };
};