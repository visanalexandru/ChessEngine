//
// Created by gvisan on 24.11.2019.
//

#include "Game.h"

namespace Chess {

    void Game::initialize_classic_board() {
        for (int i = 0; i < 8; i++) {
            Pawn *pawn = new Pawn(Vector2(i, 6), PieceColor::white);
            gameboard.SetPieceAt(Vector2(i, 6), pawn);
            pieces.push_back(pawn);


        }
        for (int i = 0; i < 8; i++) {
            Pawn *pawn = new Pawn(Vector2(i, 1), PieceColor::black);
            gameboard.SetPieceAt(Vector2(i, 1), pawn);
            pieces.push_back(pawn);
        }

    }

    Game::Game() {
        initialize_classic_board();
    }

    Game::~Game() {
        for (Chess::Piece *piece:pieces)
            delete piece;
    }

    Board &Game::GetBoard() {
        return gameboard;
    }
}