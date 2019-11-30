//
// Created by gvisan on 25.11.2019.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"

namespace Chess {

    class Knight : public Piece {
    private:
        static Vector2 offsets[8];

    public:
        Knight(Vector2 position, PieceColor color);

        bool CanMove(Vector2 newposition, const Board &board) const override;

        PieceType GetPieceType() const override;

        int GetPieceValue() const override;

    };
}


#endif //CHESS_KNIGHT_H
