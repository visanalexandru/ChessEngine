//
// Created by gvisan on 24.11.2019.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "../Piece/Pawn.h"
#include "../Piece/Knight.h"
#include "../Piece/Rook.h"
#include "../Piece/Bishop.h"
#include "../Piece/Queen.h"
#include "../Piece/King.h"
#include <vector>

namespace Chess {
    class Game {
    private:
        Board gameboard;

        King *black_king_piece, *white_king_piece;

        std::vector<Chess::Piece *> pieces;

        void initialize_classic_board();

    public:
        Game();

        ~Game();

        bool is_in_check(PieceColor side) const;

        Board &GetBoard();
    };
}


#endif //CHESS_GAME_H
