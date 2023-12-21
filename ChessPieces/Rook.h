#pragma once

#ifndef _ROOK_H_
#define _ROOK_H_

#include "ChessPiece.h"
class Rook : public ChessPiece {
    private:
    bool firstMove;

    public:
    Rook(unsigned int Team, int x, int y);
    virtual bool isValidMove(int nx, int ny, const ChessBoard* board) const;
    virtual bool move(int nx, int ny, ChessBoard* board);
};
#endif