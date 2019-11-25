//
// Created by gvisan on 25.11.2019.
//

#include "Knight.h"
#include <iostream>

namespace Chess {

    Vector2 Knight::offsets[8]{Vector2(1, -2), Vector2(2, -1), Vector2(2, 1), Vector2(1, 2), Vector2(-1, 2),
                               Vector2(-2, 1), Vector2(-2, -1), Vector2(-1, -2)};


    Knight::Knight(Vector2 position, Chess::PieceColor color) : Piece(position, color) {


    }

    bool Knight::CanMove(Vector2 newposition, const Chess::Board &board) const {

        bool found = false;
        for (int i = 0; i < 8; i++) {
            Vector2 move_there = current_position + offsets[i];
            if (move_there == newposition) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;

        //is in range
        std::cout<<"in range"<<std::endl;

        if (Board::IsInside(newposition)) {

            return board.GetPieceAt(newposition) == nullptr ||
                   (board.GetPieceAt(newposition)->GetColor() == GetOpositeColor());

        }
        return false;


    }

    PieceType Knight::GetPieceType() const {
        if (piece_color == PieceColor::white)
            return PieceType::whiteKnight;
        return PieceType::blackKnight;
    }


}