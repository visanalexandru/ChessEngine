//
// Created by gvisan on 25.11.2019.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"


namespace Chess {
    class Rook : public Piece {
    public:
        Rook(Vector2 position, PieceColor color);

        bool CanMove(Vector2 newposition, const Board &board) const override;

        PieceType GetPieceType() const override;

    };
}


#endif //CHESS_ROOK_H
