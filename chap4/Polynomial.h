#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "Chain.h"

struct Term
{// All members of Term are public by default.
    int coef;   // coeffcient.
    int exp;    // exponent
    Term Set(int c, int e) {coef = c; exp = e; return *this;}
};

class Polynomial {
public:
    Polynomial operator+(Polynomial& b);
private:
    Chain<Term> poly;
};
#endif