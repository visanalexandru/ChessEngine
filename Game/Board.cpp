//
// Created by gvisan on 24.11.2019.
//

#include "Board.h"

namespace Chess {

    bool Board::IsInside(Vector2 position) {

        return position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8;
    }

    Piece *Board::GetPieceAt(Vector2 position) const {
        if (!IsInside(position))
            return nullptr;
        return board[position.y][position.x];
    }


    void Board::SetPieceAt(Vector2 position, Piece *to_set) {
        if (!IsInside(position))
            return;
        board[position.y][position.x] = to_set;
    }

    Piece *Board::CastRay(Vector2 starting, Vector2 ending, Vector2 offset) const {
        if (!IsInside(starting) || !IsInside(ending))
            return nullptr;

        if (starting == ending)
            return GetPieceAt(starting);


        Piece *here;
        Vector2 position_here = starting;
        do {
            position_here = position_here + offset;
            here = GetPieceAt(position_here);
        } while (here == nullptr && position_here != ending);

        return here;

    }


    Board::Board() {
        for (int i = 0; i < 8; i++)
            for (int k = 0; k < 8; k++)
                board[i][k] = nullptr;
    }
}