#include <iostream>
#include "Game/Game.h"
#include "Game/GUI.h"
#include "Game/ChessSolver.h"

Chess::PieceColor GetOpposite(Chess::PieceColor color) {
    if (color == Chess::PieceColor::white)
        return Chess::PieceColor::black;
    return Chess::PieceColor::white;
}

Chess::Piece *controlling = nullptr;
Chess::PieceColor side = Chess::PieceColor::white;
Chess::Game game;

void PlayerInput(GUI &gui) {

    if (gui.IsMousePressed(0) && controlling != nullptr) {

        Vector2 pos = gui.GetMousePosition();
        if (game.IsMoveLegal(Chess::Move(controlling->GetPosition(), pos), side)) {
            controlling->Move(pos, game.GetBoard());
            side = GetOpposite(side);
            controlling = nullptr;
            gui.ClearHighlights();
        }
    } else if (gui.IsMousePressed(1)) {
        controlling = game.GetBoard().GetPieceAt(gui.GetMousePosition());
        gui.ClearHighlights();

        if (controlling != nullptr) {
            std::vector<Chess::Move> moves = game.GetLegalMovesFor(controlling);

            for (Chess::Move &move :moves) {
                gui.HighlightSquare(move.GetEnding(), sf::Color::Blue);
            }
            gui.HighlightSquare(controlling->GetPosition(), sf::Color::Red);
        }
    }
}

int main() {

    GUI gui(500);
    Chess::PieceColor player_side = Chess::PieceColor::white;
    ChessSolver ai(game, GetOpposite(player_side), 2);


    while (gui.IsWindowOpened()) {
        gui.DrawBoard(game.GetBoard());

        if (side == player_side)
            PlayerInput(gui);
        else {
            game.MakeMove(ai.GetBestMove());
            side = GetOpposite(side);
        }

        if (game.Checkmate(Chess::PieceColor::white)) {
            std::cout << "black wins" << std::endl;
            break;
        }
        if (game.Checkmate(Chess::PieceColor::black)) {
            std::cout << "white wins" << std::endl;
            break;
        }
        if (game.GetAllLegalMovesFor(Chess::PieceColor::white).size() == 0 ||
            game.GetAllLegalMovesFor(Chess::PieceColor::black).size() == 0) {
            std::cout << "stalemate" << std::endl;
            break;
        }
    }
    return 0;
}