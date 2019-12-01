//
// Created by gvisan on 25.11.2019.
//

#ifndef CHESS_GUI_H
#define CHESS_GUI_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"

class GUI {
private:
    void initialize();//load sprites

    void load_all_textures();

    void poll_events();

    void draw_grid();

    void draw_pieces(const Chess::Board &board);

    void create_grid();

    std::vector<sf::Sprite> sprites;

    std::vector<sf::Texture *> textures;
    static const std::string names[12];

    sf::RenderWindow window;

    sf::VertexArray grid;

    const float square_size;

public:
    GUI(int window_size);

    ~GUI();

    Vector2 GetMousePosition() const;

    bool IsWindowOpened() const;

    bool IsMousePressed(int index) const;

    void DrawBoard(const Chess::Board &board);

    void HighlightSquare(Vector2 position,sf::Color color);

    void ClearHighlights();


};


#endif //CHESS_GUI_H
