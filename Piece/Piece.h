//
// Created by gvisan on 24.11.2019.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "../Game/Board.h"
#include <string>

namespace Chess {
    class Board;

    enum PieceColor {
        white,
        black
    };
    enum PieceType {
        blackBishop,
        blackKing,
        blackKnight,
        blackPawn,
        blackQueen,
        blackRook,
        whiteBishop,
        whiteKing,
        whiteKnight,
        whitePawn,
        whiteQueen,
        whiteRook,
    };


    class Piece {
    public:


        void Move(Vector2 newposition, Board &board);

        PieceColor GetColor() const;

        PieceColor GetOpositeColor() const;

        bool HasMoved() const;

        Piece(Vector2 position, PieceColor color);

        virtual bool CanMove(Vector2 newposition, const Board &board) const = 0;

        virtual PieceType GetPieceType() const = 0;

        virtual int GetPieceValue() const = 0;

        Vector2 GetPosition() const;

    protected:
        Vector2 current_position;
        PieceColor piece_color;
        bool has_moved;


        friend class Game;

        friend class ChessSolver;

    };
}

#endif //CHESS_PIECE_H
