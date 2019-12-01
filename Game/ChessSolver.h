//
// Created by gvisan on 01.12.2019.
//

#ifndef CHESS_CHESSSOLVER_H
#define CHESS_CHESSSOLVER_H

#include "Game.h"

namespace Chess {
    class ChessSolver {
    private:
        struct MoveData {
            Move move;
            int score;
            int depth_of_move;

        };
        Game &game;
        const int depth_of_search;
        const PieceColor side;

        static int random_between(int min, int max);

        MoveData minmax(int current_depth, PieceColor turn_side);

        MoveData maximize(int current_depth, PieceColor turn_side);

        MoveData minimize(int current_depth, PieceColor turn_side);

        int get_score();

    public:
        ChessSolver(Game &chess_game, PieceColor side_color, int depth);

        Chess::Move GetBestMove();

    };
}

#endif //CHESS_CHESSSOLVER_H
