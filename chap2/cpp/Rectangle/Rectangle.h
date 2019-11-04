#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    public:
        Rectangle(int x = 0, int y = 0, int h = 0, int w = 0);
        ~Rectangle(){};       // destructor
        int GetHeight();    // 
        int GetWidth();
    private:
        int xLow, yLow, height, width;
};
#endif