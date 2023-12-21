#pragma once

#ifndef _CHESS_CONSOLE_H_
#define _CHESS_CONSOLE_H_

#include "ChessBoard.h"
#include "ChessGraphics.h"
#include "ChessPieces/ChessPiece.h"

class ChessConsole {
    private:
    ChessBoard board;
    ChessGraphics graphics;
    bool isBlackTurn = true;

    public:
    ChessConsole();
    int run(void);
    ChessPiece* selectPiece();
    void movePiece(ChessPiece* selectedPiece);
    void gameOver();
};
#endif