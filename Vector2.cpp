//
// Created by gvisan on 24.11.2019.
//

#include "Vector2.h"


Vector2::Vector2(int xpos, int ypos) : y(ypos), x(xpos) {

}

bool Vector2::operator==(const Vector2 &other) {
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2 &other) {

    return (other.x != x) || (other.y != y);
}

Vector2 Vector2::operator-(const Vector2 &other) {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator+(const Vector2 &other) {
    return Vector2(x + other.x, y + other.y);

}