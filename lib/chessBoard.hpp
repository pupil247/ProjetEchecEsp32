#pragma once
#include <vector>
#include "chessPiece.hpp"
#include <Arduino.h>

// Class representing a ChessPiece
class ChessBoard {
public:

    ChessBoard(uint8_t boardSize, bool playerColor){

        this->chessBoard = new std::vector<std::vector<ChessPiece>>(boardSize, std::vector<ChessPiece>(boardSize));

        (*chessBoard)[0][0] = ChessPiece(ChessPieceType::ROOK, ChessPieceColor::WHITE);
        (*chessBoard)[1][0] = ChessPiece(ChessPieceType::KNIGHT, ChessPieceColor::WHITE);
        (*chessBoard)[2][0] = ChessPiece(ChessPieceType::BISHOP, ChessPieceColor::WHITE);
        (*chessBoard)[3][0] = ChessPiece(ChessPieceType::QUEEN, ChessPieceColor::WHITE);
        (*chessBoard)[4][0] = ChessPiece(ChessPieceType::KING, ChessPieceColor::WHITE);
        (*chessBoard)[5][0] = ChessPiece(ChessPieceType::BISHOP, ChessPieceColor::WHITE);
        (*chessBoard)[6][0] = ChessPiece(ChessPieceType::KNIGHT, ChessPieceColor::WHITE);
        (*chessBoard)[7][0] = ChessPiece(ChessPieceType::ROOK, ChessPieceColor::WHITE);
        for(int i = 0; i < 8; i++){
            (*chessBoard)[i][1] = ChessPiece(ChessPieceType::PAWN, ChessPieceColor::WHITE);
        }

        (*chessBoard)[0][7] = ChessPiece(ChessPieceType::ROOK, ChessPieceColor::BLACK);
        (*chessBoard)[1][7] = ChessPiece(ChessPieceType::KNIGHT, ChessPieceColor::BLACK);
        (*chessBoard)[2][7] = ChessPiece(ChessPieceType::BISHOP, ChessPieceColor::BLACK);
        (*chessBoard)[3][7] = ChessPiece(ChessPieceType::QUEEN, ChessPieceColor::BLACK);
        (*chessBoard)[4][7] = ChessPiece(ChessPieceType::KING, ChessPieceColor::BLACK);
        (*chessBoard)[5][7] = ChessPiece(ChessPieceType::BISHOP, ChessPieceColor::BLACK);
        (*chessBoard)[6][7] = ChessPiece(ChessPieceType::KNIGHT, ChessPieceColor::BLACK);
        (*chessBoard)[7][7] = ChessPiece(ChessPieceType::ROOK, ChessPieceColor::BLACK);
        for(int i = 0; i < 8; i++){
            (*chessBoard)[i][6] = ChessPiece(ChessPieceType::PAWN, ChessPieceColor::BLACK);
        }

    }
    void getPlayerColor();
    void movePlayerPiece();
    void moveOpponentPiece();

private:
    bool playerColor;
    bool currentTurn;
    std::vector<std::vector<ChessPiece>> * chessBoard;    
};