#pragma once

enum class ChessPieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

// Enum to represent chess piece colors
enum class ChessPieceColor {
    WHITE,
    BLACK
};

// Class representing a ChessPiece
class ChessPiece {
public:
    ChessPiece(ChessPieceType type, ChessPieceColor color)
        : type(type), color(color) {}

    void move() const {
        //std::cout << "Moving the chess piece." << std::endl;
    }


private:
    ChessPieceType type;
    ChessPieceColor color;
};
