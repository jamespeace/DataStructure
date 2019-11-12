#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Rectangle r,s;
    Rectangle *t = &s;

    if (r.GetHeight() * r.GetWidth() > t->GetHeight() * t->GetWidth())
        cout << "r ";
    else cout << "s ";
    cout << "has the greater area" << endl;
    return 0;
}
