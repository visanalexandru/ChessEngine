//
// Created by gvisan on 26.11.2019.
//

#include "Bishop.h"


namespace Chess {
    Bishop::Bishop(Vector2 position, Chess::PieceColor color) : Piece(position, color) {

    }

    bool Bishop::CanMove(Vector2 newposition, const Chess::Board &board) const {
        if (!Board::IsInside(newposition))
            return false;
        if (newposition == current_position)
            return false;

        Vector2 offset = newposition - current_position;


        if (abs(offset.x) == abs(offset.y)) {
            int normalized_offset_x = offset.x / abs(offset.x);
            int normalized_offset_y = offset.y / abs(offset.y);

            Piece *threatening = board.CastRay(current_position, newposition,
                                               Vector2(normalized_offset_x, normalized_offset_y));

            return threatening == nullptr ||
                   (threatening->GetPosition() == newposition && threatening->GetColor() == GetOpositeColor());

        }

        return false;

    }


    PieceType Bishop::GetPieceType() const {
        if (piece_color == PieceColor::white)
            return PieceType::whiteBishop;
        return PieceType::blackBishop;
    }

    int Bishop::GetPieceValue() const {
        return 3;
    }
}