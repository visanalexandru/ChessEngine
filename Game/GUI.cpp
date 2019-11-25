//
// Created by gvisan on 25.11.2019.
//

#include "GUI.h"
#include "../Piece/Piece.h"

GUI::GUI(int window_size) : square_size((float) window_size / 8.0f),
                            window(sf::VideoMode(window_size, window_size), "Chess") {
    initialize();
}


GUI::~GUI() {
    for (sf::Texture *texture:textures)
        delete texture;
}

const std::string GUI::names[12]{"blackBishop", "blackKing", "blackKnight", "blackPawn",
                                 "blackQueen", "blackRook", "whiteBishop", "whiteKing",
                                 "whiteKnight", "whitePawn", "whiteQueen", "whiteRook"};

void GUI::load_all_textures() {

    for (const std::string &path:names) {
        sf::Texture *newtexture = new sf::Texture();
        newtexture->loadFromFile("Sprites/" + path + ".png");
        textures.push_back(newtexture);

        sf::Sprite newsprite;
        newsprite.setTexture(*newtexture);
        sprites.push_back(newsprite);
    }


}


void GUI::initialize() {
    load_all_textures();
}


void GUI::poll_events() {

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void GUI::draw_grid() {
    sf::VertexArray quad(sf::Quads, 4);

    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            quad[0].position = sf::Vector2f((float) k * square_size, (float) i * square_size);
            quad[1].position = sf::Vector2f((float) (k + 1) * square_size, (float) i * square_size);
            quad[2].position = sf::Vector2f((float) (k + 1) * square_size, (float) (i + 1) * square_size);
            quad[3].position = sf::Vector2f((float) k * square_size, (float) (i + 1) * square_size);

            for (int p = 0; p < 4; p++) {
                if ((k + i) % 2) {
                    quad[p].color = sf::Color(102, 51, 1);
                } else quad[p].color = sf::Color::White;
            }
            window.draw(quad);
        }
    }
}

void GUI::draw_pieces(const Chess::Board &board) {

    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            Chess::Piece *piece = board.GetPieceAt(Vector2(k, i));

            if (piece != nullptr) {
                Chess::PieceType type = piece->GetPieceType();
                sf::Sprite sprite_piece = sprites[(int) type];
                sprite_piece.setPosition((float) k * square_size, (float) i * square_size);

                sprite_piece.setScale(sf::Vector2f(square_size / 50.f, square_size / 50.f));

                window.draw(sprite_piece);

            }
        }
    }

}

void GUI::DrawBoard(const Chess::Board &board) {

    window.clear();
    poll_events();
    draw_grid();
    draw_pieces(board);

    window.display();

}

Vector2 GUI::GetMousePosition() const {
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    return Vector2(pos.x / square_size, pos.y / square_size);

}

bool GUI::IsWindowOppened() const {
    return window.isOpen();
}

bool GUI::IsMousePressed() const {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}