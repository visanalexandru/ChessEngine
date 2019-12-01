//
// Created by gvisan on 01.12.2019.
//

#include "ChessSolver.h"


ChessSolver::ChessSolver(Chess::Game &chess_game, Chess::PieceColor side_color, int depth) : game(chess_game), side(side_color),
                                                                                             depth_of_search(depth) {

}


int ChessSolver::random_between(int min, int max) {

    int randNum = rand() % (max - min + 1) + min;
    return randNum;

}

Chess::Move ChessSolver::GetBestMove() {
    std::vector<Chess::Move> all_moves = game.GetAllLegalMovesFor(side);
    return all_moves[random_between(0, all_moves.size() - 1)];
}