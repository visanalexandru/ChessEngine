//
// Created by gvisan on 24.11.2019.
//

#include "Vector2.h"


Vector2::Vector2(int xpos, int ypos) : y(ypos), x(xpos) {

}

bool Vector2::operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2 &other) const {

    return (other.x != x) || (other.y != y);
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);

}

int Vector2::GetLength() const {
    return sqrt(x * x + y * y);
}