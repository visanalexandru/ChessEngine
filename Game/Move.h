//
// Created by gvisan on 01.12.2019.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "../Vector2.h"

namespace Chess {


    class Move {
    public:
        Move(Vector2 starting, Vector2 ending);

        Vector2 GetStarting() const;

        Vector2 GetEnding() const;

    private:
        Vector2 to_move;
        Vector2 where;


    };

}


#endif //CHESS_MOVE_H
