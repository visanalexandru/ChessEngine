//
// Created by gvisan on 29.11.2019.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"


namespace Chess {
    class Queen : public Piece {
    public:
        Queen(Vector2 position, PieceColor color);

        bool CanMove(Vector2 newposition, const Board &board) const override;

        PieceType GetPieceType() const override;
    };

}


#endif //CHESS_QUEEN_H
