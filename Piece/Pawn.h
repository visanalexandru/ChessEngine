//
// Created by gvisan on 24.11.2019.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

namespace Chess {

    class Pawn : public Piece {
    public:
        Pawn(Vector2 position, PieceColor color);

        bool CanMove(Vector2 newposition, const Board &board) const override;

        PieceType GetPieceType() const override;

        int GetPieceValue() const override;

    };
}


#endif //CHESS_PAWN_H
