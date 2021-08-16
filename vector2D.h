#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{
private:
    int x;
    int y;
public:
    Vector2D(int _x = 0, int _y = 0): x(_x), y(_y){};
    ~Vector2D(){};
    int getX(){return x;};
    int getY(){return y;};
    Vector2D operator+(const Vector2D &);
    Vector2D & operator+=(const Vector2D &);
    Vector2D & operator=(const Vector2D &);
    bool operator==(const Vector2D &);
};

#endif