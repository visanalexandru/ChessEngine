//
// Created by gvisan on 29.11.2019.
//

#include "Queen.h"

namespace Chess {
    Queen::Queen(Vector2 position, Chess::PieceColor color) : Piece(position, color) {


    }


    bool Queen::CanMove(Vector2 newposition, const Chess::Board &board) const {
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

        else if (offset.x == 0 || offset.y == 0) {

            Piece *hit;
            int normalized_offset;

            if (offset.x == 0) {
                normalized_offset = offset.y / (abs(offset.y));
                hit = board.CastRay(current_position, newposition, Vector2(0, normalized_offset));
            } else {
                normalized_offset = offset.x / (abs(offset.x));
                hit = board.CastRay(current_position, newposition, Vector2(normalized_offset, 0));
            }
            return hit == nullptr || (hit->GetPosition() == newposition && hit->GetColor() == GetOpositeColor());

        }
        return false;


    }

    PieceType Queen::GetPieceType() const {
        if (piece_color == PieceColor::white) {
            return PieceType::whiteQueen;
        }
        return PieceType::blackQueen;
    }


}
