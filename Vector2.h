//
// Created by gvisan on 24.11.2019.
//

#ifndef CHESS_VECTOR2_H
#define CHESS_VECTOR2_H

#include <string>

class Vector2 {
public:
    int x, y;

    Vector2(int xpos, int ypos);

    bool operator==(const Vector2 &other);

    bool operator!=(const Vector2 &other);

    Vector2 operator-(const Vector2 &other);

    Vector2 operator+(const Vector2 &other);

};


#endif //CHESS_VECTOR2_H
