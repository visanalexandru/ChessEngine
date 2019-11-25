//
// Created by gvisan on 24.11.2019.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "../Piece/Pawn.h"
#include <vector>

namespace Chess {
    class Game {
    private:
        Board gameboard;
        std::vector<Chess::Piece *> pieces;

        void initialize_classic_board();

    public:
        Game();

        ~Game();

        Board &GetBoard();
    };
}


#endif //CHESS_GAME_H