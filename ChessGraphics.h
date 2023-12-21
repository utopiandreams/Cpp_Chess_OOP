#pragma once
#include <string>

#ifndef _CHESS_GRAPHICS_H_
#define _CHESS_GRAPHICS_H_

class ChessBoard;
class ChessPiece;
class ChessGraphics {
    private:
    const ChessBoard* chessBoard;

    public:
    ChessGraphics(const ChessBoard* chessBoard);
    void Render(void);
    std::string ToChar(const ChessPiece* Piece) const;
};

#endif