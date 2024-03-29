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


        //BISHOPS
        Bishop *black_bishop1 = new Bishop(Vector2(2, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(2, 0), black_bishop1);
        pieces.push_back(black_bishop1);

        Bishop *black_bishop2 = new Bishop(Vector2(5, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(5, 0), black_bishop2);
        pieces.push_back(black_bishop2);

        Bishop *white_bishop1 = new Bishop(Vector2(2, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(2, 7), white_bishop1);
        pieces.push_back(white_bishop1);

        Bishop *white_bishop2 = new Bishop(Vector2(5, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(5, 7), white_bishop2);
        pieces.push_back(white_bishop2);


        //QUEENS
        Queen *black_queen = new Queen(Vector2(3, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(3, 0), black_queen);
        pieces.push_back(black_queen);

        Queen *white_queen = new Queen(Vector2(3, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(3, 7), white_queen);
        pieces.push_back(white_queen);

        //KINGS
        King *black_king = new King(Vector2(4, 0), PieceColor::black);
        gameboard.SetPieceAt(Vector2(4, 0), black_king);
        pieces.push_back(black_king);
        black_king_piece = black_king;

        King *white_king = new King(Vector2(4, 7), PieceColor::white);
        gameboard.SetPieceAt(Vector2(4, 7), white_king);
        pieces.push_back(white_king);
        white_king_piece = white_king;

    }

    bool Game::is_in_check(Chess::PieceColor side) const {
        PieceColor other_side;
        King *to_check;

        if (side == PieceColor::white) {
            other_side = PieceColor::black;
            to_check = white_king_piece;
        } else {
            other_side = PieceColor::white;
            to_check = black_king_piece;
        }

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                Piece *pointing = gameboard.GetPieceAt(Vector2(i, k));


                if (pointing != nullptr && pointing->GetColor() == other_side &&
                    pointing->CanMove(to_check->GetPosition(), gameboard))
                    return true;
            }
        }

        return false;

    }


    bool Game::IsMoveLegal(Move move, Chess::PieceColor side) {

        Vector2 starting = move.GetStarting();
        Vector2 ending = move.GetEnding();

        if (!Board::IsInside(starting) || !Board::IsInside(ending))
            return false;

        Piece *selected = gameboard.GetPieceAt(starting);
        if (selected == nullptr || selected->GetColor() != side || !selected->CanMove(ending, gameboard))
            return false;

        gameboard.SetPieceAt(starting, nullptr);
        Piece *aux = gameboard.GetPieceAt(ending);
        gameboard.SetPieceAt(ending, selected);
        selected->current_position = ending;

        bool is_legal = true;
        if (is_in_check(side)) {
            is_legal = false;

        }

        gameboard.SetPieceAt(starting, selected);
        selected->current_position = starting;
        gameboard.SetPieceAt(ending, aux);

        return is_legal;

    }

    std::vector<Move> Game::GetLegalMovesFor(Chess::Piece *piece) {
        std::vector<Move> to_return;
        Vector2 initial = piece->GetPosition();

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                Vector2 destination(i, k);
                Move to_check(initial, destination);
                if (IsMoveLegal(to_check, piece->GetColor())) {
                    to_return.push_back(to_check);
                }
            }
        }
        return to_return;
    }


    std::vector<Move> Game::GetAllLegalMovesFor(Chess::PieceColor side) {
        std::vector<Move> to_return;

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                Piece *there = gameboard.GetPieceAt(Vector2(i, k));
                if (there != nullptr && there->GetColor() == side) {
                    std::vector<Move> piece_moves = GetLegalMovesFor(there);
                    to_return.insert(to_return.end(), piece_moves.begin(), piece_moves.end());
                }
            }
        }
        return to_return;
    }

    void Game::MakeMove(Chess::Move move) {//this should be called after checking for legal move

        Piece *to_move = gameboard.GetPieceAt(move.GetStarting());
        to_move->Move(move.GetEnding(), gameboard);
    }

    int Game::GetScoreFor(Chess::PieceColor side) const {
        int result = 0;

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                Piece *pointing = gameboard.GetPieceAt(Vector2(i, k));
                if (pointing != nullptr && pointing->GetColor() == side) {
                    result += pointing->GetPieceValue();
                }
            }
        }
        return result;

    }

    bool Game::Checkmate(Chess::PieceColor side) {

        int number_of_legal_moves = GetAllLegalMovesFor(side).size();

        return is_in_check(side) && number_of_legal_moves == 0;
    }

    Game::Game() {
        initialize_classic_board();
    }

    Game::~Game() {
        for (Chess::Piece *piece:pieces)
            delete piece;
    }

    PieceColor Game::GetOpositeColor(Chess::PieceColor color) {
        if (color == Chess::PieceColor::white)
            return Chess::PieceColor::black;
        return Chess::PieceColor::white;
    }

    Board &Game::GetBoard() {
        return gameboard;
    }
}