//
// Created by gvisan on 01.12.2019.
//

#ifndef CHESS_CHESSSOLVER_H
#define CHESS_CHESSSOLVER_H

#include "Game.h"

namespace Chess {
    class ChessSolver {
    private:
        Game &game;
        const int depth_of_search;
        const PieceColor side;

        static int random_between(int min, int max);

        std::pair<Move, int> minmax(int current_depth, PieceColor turn_side);

        std::pair<Move, int> maximize(int current_depth, PieceColor turn_side);

        std::pair<Move, int> minimize(int current_depth, PieceColor turn_side);

        int get_score();

    public:
        ChessSolver(Game &chess_game, PieceColor side_color, int depth);

        Chess::Move GetBestMove();

    };
}

#endif //CHESS_CHESSSOLVER_H
