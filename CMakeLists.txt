cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Game/Board.cpp Game/Board.h Piece/Piece.cpp Piece/Piece.h Vector2.cpp Vector2.h Piece/Pawn.cpp Piece/Pawn.h Game/Game.cpp Game/Game.h Game/GUI.cpp Game/GUI.h Piece/Knight.cpp Piece/Knight.h Piece/Rook.cpp Piece/Rook.h Piece/Bishop.cpp Piece/Bishop.h Piece/Queen.cpp Piece/Queen.h Piece/King.cpp Piece/King.h)
target_link_libraries(Chess sfml-window sfml-system sfml-graphics)