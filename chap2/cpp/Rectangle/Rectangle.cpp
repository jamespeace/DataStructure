#include "Rectangle.h"

int Rectangle::GetHeight() {return height;}
int Rectangle::GetWidth() {return width;}

Rectangle::Rectangle(int x, int y, int h, int w)
:xLow(x),yLow(y),height(h),width(w)
{}