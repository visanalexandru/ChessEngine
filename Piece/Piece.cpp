//
// Created by gvisan on 24.11.2019.
//

#include "Piece.h"

namespace Chess {

    Piece::Piece(Vector2 position, PieceColor color) : current_position(position),
                                                       piece_color(color), has_moved(false) {

    }

    PieceColor Piece::GetColor() const {
        return piece_color;
    }

    PieceColor Piece::GetOpositeColor() const {

        if (piece_color == PieceColor::white) {
            return PieceColor::black;
        }
        return PieceColor::white;
    }

    Vector2 Piece::GetPosition() const {
        return current_position;
    }


    void Piece::Move(Vector2 newposition, Board &board) {
        board.SetPieceAt(current_position, nullptr);
        board.SetPieceAt(newposition, this);
        has_moved = true;
        current_position = newposition;
    }


    bool Piece::HasMoved() const {
        return has_moved;
    }
}