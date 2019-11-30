//
// Created by gvisan on 29.11.2019.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"


namespace Chess {

    class King : public Piece {
    public:
        King(Vector2 position, PieceColor color);

        bool CanMove(Vector2 newposition, const Board &board) const override;

        PieceType GetPieceType() const override;

        int GetPieceValue() const override;

    };
};


#endif //CHESS_KING_H
