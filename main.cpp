#include <iostream>
#include "Game/Game.h"
#include "Game/GUI.h"

int main() {
    Chess::Game game;
    GUI gui(500);
    Chess::Piece *controlling = game.GetBoard().GetPieceAt(Vector2(0, 1));


    while (gui.IsWindowOppened()) {
        gui.DrawBoard(game.GetBoard());

        if (gui.IsMousePressed()) {

            Vector2 pos = gui.GetMousePosition();
            if (controlling->CanMove(pos, game.GetBoard())) {
                controlling->Move(pos, game.GetBoard());
            }
            std::cout << gui.GetMousePosition().x << " " << gui.GetMousePosition().y << std::endl;

        }

    }
    return 0;
}