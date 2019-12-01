//
// Created by gvisan on 01.12.2019.
//

#ifndef CHESS_CHESSSOLVER_H
#define CHESS_CHESSSOLVER_H

#include "Game.h"

class ChessSolver {
private:
    Chess::Game &game;
    const int depth_of_search;
    const Chess::PieceColor side;

    static int random_between(int min, int max);


public:
    ChessSolver(Chess::Game &chess_game, Chess::PieceColor side_color, int depth);

    Chess::Move GetBestMove();

};


#endif //CHESS_CHESSSOLVER_H
