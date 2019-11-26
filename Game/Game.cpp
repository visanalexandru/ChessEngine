//
// Created by gvisan on 24.11.2019.
//

#include "Game.h"

namespace Chess {

    void Game::initialize_classic_board() {
        //PAWNS
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


        //KNIGHTS

        Knight *black_knight1 = new Knight(Vector2(1, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(1, 0), black_knight1);
        pieces.push_back(black_knight1);


        Knight *black_knight2 = new Knight(Vector2(6, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(6, 0), black_knight2);
        pieces.push_back(black_knight2);

        Knight *white_knight1 = new Knight(Vector2(1, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(1, 7), white_knight1);
        pieces.push_back(white_knight1);

        Knight *white_knight2 = new Knight(Vector2(6, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(6, 7), white_knight2);
        pieces.push_back(white_knight2);


        //ROOKS
        Rook *black_rook1 = new Rook(Vector2(0, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(0, 0), black_rook1);
        pieces.push_back(black_rook1);


        Rook *black_rook2 = new Rook(Vector2(7, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(7, 0), black_rook2);
        pieces.push_back(black_rook2);

        Rook *white_rook1 = new Rook(Vector2(0, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(0, 7), white_rook1);
        pieces.push_back(white_rook1);

        Rook *white_rook2 = new Rook(Vector2(7, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(7, 7), white_rook2);
        pieces.push_back(white_rook2);

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