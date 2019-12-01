//
// Created by gvisan on 01.12.2019.
//

#include "Move.h"


namespace Chess {
    Move::Move(Vector2 starting, Vector2 ending) : to_move(starting), where(ending) {

    }

    Vector2 Move::GetEnding() const {
        return where;
    }

    Vector2 Move::GetStarting() const {
        return to_move;
    }


}