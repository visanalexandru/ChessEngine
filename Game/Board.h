//
// Created by gvisan on 24.11.2019.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H


#include "../Vector2.h"

namespace Chess {
    class Piece;

    class Board {
    private:
        Piece *board[8][8];
    public:
        Piece *GetPieceAt(Vector2 position) const;

        void SetPieceAt(Vector2 position, Piece *to_set);

        static bool IsInside(Vector2 position);

        Piece *CastRay(Vector2 starting, Vector2 ending, Vector2 offset) const;

        Board();
    };
}


#endif //CHESS_BOARD_H
