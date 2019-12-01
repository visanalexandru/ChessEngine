#include <iostream>
#include "Game/Game.h"
#include "Game/GUI.h"


Chess::PieceColor GetOpposite(Chess::PieceColor color) {
    if (color == Chess::PieceColor::white)
        return Chess::PieceColor::black;
    return Chess::PieceColor::white;
}


int main() {
    Chess::Game game;
    GUI gui(500);


    Chess::Piece *controlling = nullptr;
    Chess::PieceColor side = Chess::PieceColor::white;

    while (gui.IsWindowOpened()) {
        gui.DrawBoard(game.GetBoard());

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

        if (side == Chess::PieceColor::white) {
            std::cout << "white moves" << " ";
        } else std::cout << "black moves" << " ";


        std::cout << "white in checkmate: " << game.Checkmate(Chess::PieceColor::white) << " "
                  << "black in checkmate: " << game.Checkmate(Chess::PieceColor::black) << std::endl;
    }
    return 0;
}