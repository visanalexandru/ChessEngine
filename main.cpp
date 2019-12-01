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
            }


        } else if (gui.IsMousePressed(1)) {
            controlling = game.GetBoard().GetPieceAt(gui.GetMousePosition());
        }

        if (side == Chess::PieceColor::white) {
            std::cout << "white moves" << std::endl;
        } else std::cout << "black moves" << std::endl;

    }
    return 0;
}