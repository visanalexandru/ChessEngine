//
// Created by gvisan on 01.12.2019.
//

#include "ChessSolver.h"

namespace Chess {
    ChessSolver::ChessSolver(Game &chess_game, PieceColor side_color, int depth) : game(chess_game),
                                                                                   side(side_color),
                                                                                   depth_of_search(
                                                                                           depth) {

    }


    int ChessSolver::random_between(int min, int max) {

        int randNum = rand() % (max - min + 1) + min;
        return randNum;

    }

    Move ChessSolver::GetBestMove() {
        std::pair<Move, int> best = minmax(0, side);

        Vector2 starting = best.first.GetStarting();
        Vector2 ending = best.first.GetEnding();
        return best.first;
    }

    std::pair<Move, int> ChessSolver::maximize(int current_depth, Chess::PieceColor turn_side) {
        int highest_score = -999999;
        Move to_return({0, 0}, {0, 0});
        std::vector<Move> possible_moves = game.GetAllLegalMovesFor(turn_side);


        for (Move &a:possible_moves) {
            Piece *to_move = game.GetBoard().GetPieceAt(a.GetStarting());
            Piece *aux = game.GetBoard().GetPieceAt(a.GetEnding());
            to_move->Move(a.GetEnding(), game.GetBoard());


            int move_consequence = minmax(current_depth + 1, Game::GetOpositeColor(turn_side)).second;


            to_move->Move(a.GetStarting(), game.GetBoard());
            game.GetBoard().SetPieceAt(a.GetEnding(), aux);
            to_move->has_moved = false;


            if (move_consequence > highest_score) {
                highest_score = move_consequence;
                to_return = a;
            }

        }
        if (highest_score == -999999)
            highest_score = 0;//stalemate

        return {to_return, highest_score};
    }


    std::pair<Move, int> ChessSolver::minimize(int current_depth, Chess::PieceColor turn_side) {
        int lowest_score = 999999;
        Move to_return({0, 0}, {0, 0});

        std::vector<Move> possible_moves = game.GetAllLegalMovesFor(turn_side);


        for (Move &a:possible_moves) {
            Piece *to_move = game.GetBoard().GetPieceAt(a.GetStarting());
            Piece *aux = game.GetBoard().GetPieceAt(a.GetEnding());
            to_move->Move(a.GetEnding(), game.GetBoard());


            int move_consequence = minmax(current_depth + 1, Game::GetOpositeColor(turn_side)).second;


            to_move->Move(a.GetStarting(), game.GetBoard());
            game.GetBoard().SetPieceAt(a.GetEnding(), aux);
            to_move->has_moved = false;


            if (move_consequence < lowest_score) {
                lowest_score = move_consequence;
                to_return = a;
            }
        }
        if (lowest_score == 999999)
            lowest_score = 0;//stalemate

        return {to_return, lowest_score};
    }

    int ChessSolver::get_score() {
        return game.GetScoreFor(side) - game.GetScoreFor(Game::GetOpositeColor(side));
    }

    std::pair<Move, int> ChessSolver::minmax(int current_depth, PieceColor turn_side) {
        Move empty_move(Vector2(0, 0), Vector2(0, 0));

        if (game.Checkmate(side)) {
            return {empty_move, -99999};
        }
        if (game.Checkmate(Game::GetOpositeColor(side)))
            return {empty_move, 99999};

        if (current_depth == depth_of_search) {
            return {empty_move, get_score()};
        }

        if (turn_side == side)
            return maximize(current_depth, turn_side);
        return minimize(current_depth, turn_side);

    }
}