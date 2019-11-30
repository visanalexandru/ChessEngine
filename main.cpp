#include <iostream>
#include "Game/Game.h"
#include "Game/GUI.h"

int main() {
    Chess::Game game;
    GUI gui(500);
    Chess::Piece *controlling = game.GetBoard().GetPieceAt(Vector2(1, 0));


    while (gui.IsWindowOpened()) {
        gui.DrawBoard(game.GetBoard());

        if (gui.IsMousePressed(0)) {

            Vector2 pos = gui.GetMousePosition();
            if (controlling->CanMove(pos, game.GetBoard())) {
                controlling->Move(pos, game.GetBoard());
            }
            std::cout << gui.GetMousePosition().x << " " << gui.GetMousePosition().y << std::endl;

        } else if (gui.IsMousePressed(1)) {
            if (game.GetBoard().GetPieceAt(gui.GetMousePosition()) != nullptr)
                controlling = game.GetBoard().GetPieceAt(gui.GetMousePosition());
        }
        std::cout << "white in check: " << game.is_in_check(Chess::PieceColor::white) << " black in check "
                  << game.is_in_check(Chess::PieceColor::black) << std::endl;

    }
    return 0;
}