#pragma once
#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "ChessPiece.h"

class Queen : public ChessPiece {
    public:
    Queen(unsigned int Team, int x, int y);
    virtual bool isValidMove(int nx, int ny, const ChessBoard* board) const;
    virtual bool move(int nx, int ny, ChessBoard* board);
};
#endif