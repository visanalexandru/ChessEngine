#include <iostream>
#include "Game/Game.h"
#include "Game/GUI.h"
#include "Game/ChessSolver.h"

using namespace Chess;

Piece *controlling = nullptr;
PieceColor side = PieceColor::white;
Game game;

void PlayerInput(GUI &gui) {

    if (gui.IsMousePressed(0) && controlling != nullptr) {

        Vector2 pos = gui.GetMousePosition();
        if (game.IsMoveLegal(Move(controlling->GetPosition(), pos), side)) {
            controlling->Move(pos, game.GetBoard());
            side = Game::GetOpositeColor(side);
            controlling = nullptr;
            gui.ClearHighlights();
        }
    } else if (gui.IsMousePressed(1)) {
        controlling = game.GetBoard().GetPieceAt(gui.GetMousePosition());
        gui.ClearHighlights();

        if (controlling != nullptr) {
            std::vector<Move> moves = game.GetLegalMovesFor(controlling);

            for (Move &move :moves) {
                gui.HighlightSquare(move.GetEnding(), sf::Color::Blue);
            }
            gui.HighlightSquare(controlling->GetPosition(), sf::Color::Red);
        }
    }
}

int main() {

    GUI gui(500);
    PieceColor player_side = PieceColor::white;
    ChessSolver ai(game, Game::GetOpositeColor(player_side), 3);


    while (gui.IsWindowOpened()) {
        gui.DrawBoard(game.GetBoard());

        if (side == player_side)
            PlayerInput(gui);
        else {
            game.MakeMove(ai.GetBestMove());
            side = Game::GetOpositeColor(side);
        }

        if (game.Checkmate(PieceColor::white)) {
            std::cout << "black wins" << std::endl;
            break;
        }
        if (game.Checkmate(PieceColor::black)) {
            std::cout << "white wins" << std::endl;
            break;
        }
        if (game.GetAllLegalMovesFor(PieceColor::white).size() == 0 ||
            game.GetAllLegalMovesFor(PieceColor::black).size() == 0) {
            std::cout << "stalemate" << std::endl;
            break;
        }
    }
    return 0;
}