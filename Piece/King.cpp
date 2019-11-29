//
// Created by gvisan on 29.11.2019.
//

#include "King.h"

namespace Chess {
    King::King(Vector2 position, Chess::PieceColor color) : Piece(position, color) {

    }

    bool King::CanMove(Vector2 newposition, const Chess::Board &board) const {
        if (!Board::IsInside(newposition))
            return false;

        Vector2 offset = newposition - current_position;

        Piece *threatening = board.GetPieceAt(newposition);

        return offset.GetLength() == 1 && (threatening == nullptr || threatening->GetColor() == GetOpositeColor());
    }


    PieceType King::GetPieceType() const {
        if (piece_color == PieceColor::white)
            return PieceType::whiteKing;
        return PieceType::blackKing;
    }
}