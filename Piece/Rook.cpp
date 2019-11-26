//
// Created by gvisan on 25.11.2019.
//

#include "Rook.h"
#include <iostream>

namespace Chess {

    Rook::Rook(Vector2 position, PieceColor color) : Piece(position, color) {

    }


    bool Rook::CanMove(Vector2 newposition, const Chess::Board &board) const {
        if (!Board::IsInside(newposition))
            return false;
        if (newposition == current_position)
            return false;


        Vector2 offset = newposition - current_position;

        if (offset.x == 0 || offset.y == 0) {
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


    PieceType Rook::GetPieceType() const {
        if (piece_color == PieceColor::black)
            return PieceType::blackRook;
        return PieceType::whiteRook;
    }


}