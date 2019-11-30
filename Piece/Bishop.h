//
// Created by gvisan on 26.11.2019.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"


namespace Chess {
    class Bishop : public Piece {
    public:
        Bishop(Vector2 position, PieceColor color);

        bool CanMove(Vector2 newposition, const Board &board) const override;

        PieceType GetPieceType() const override;

        int GetPieceValue() const override;
    };
}


#endif //CHESS_BISHOP_H
