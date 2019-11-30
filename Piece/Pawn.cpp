//
// Created by gvisan on 24.11.2019.
//

#include "Pawn.h"

namespace Chess {

    Pawn::Pawn(Vector2 position, PieceColor color) : Piece(position, color) {


    }

    bool Pawn::CanMove(Vector2 newposition, const Board &board) const {

        if (!Board::IsInside(newposition))
            return false;

        int offset;
        if (piece_color == PieceColor::white) {
            offset = -1;
        } else {
            offset = 1;
        }

        if (!has_moved && newposition.y == current_position.y + offset * 2 && newposition.x == current_position.x) {
            return board.GetPieceAt(current_position + Vector2(0, offset)) == nullptr &&
                   board.GetPieceAt(newposition) == nullptr;
        }


        if (newposition.y == current_position.y + offset) {

            Piece *attacking = board.GetPieceAt(newposition);

            if (newposition.x == current_position.x) {

                return attacking == nullptr;
            } else if (abs(newposition.x - current_position.x) == 1) {

                return attacking != nullptr && attacking->GetColor() == GetOpositeColor();
            }

            return false;

        }
        return false;
    }

    PieceType Pawn::GetPieceType() const {
        if (piece_color == PieceColor::white) {
            return PieceType::whitePawn;
        }
        return PieceType::blackPawn;
    }

    int Pawn::GetPieceValue() const {
        return 1;
    }

}