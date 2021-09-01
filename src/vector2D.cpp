#include "vector2D.h"

/// compare with second vector2D

bool Vector2D::operator==(const Vector2D & another){
    if(x == another.x && y == another.y){
        return true;
    }
    return false;
}

/// 2D vectors addition

Vector2D Vector2D::operator+(const Vector2D& another){
    return Vector2D(this->x+another.x, this->y+another.y);
}

/// add another vector2D to this

Vector2D & Vector2D::operator+=(const Vector2D& another){
    x += another.x;
    y += another.y;
    return * this;
}

/// set new values of coordinates

Vector2D & Vector2D::operator=(const Vector2D& another){
    x = another.x;
    y = another.y;
    return * this;
}