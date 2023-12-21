#pragma once

#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "ChessPiece.h"

class Knight : public ChessPiece {
    public:
    Knight(unsigned int Team, int x, int y);
    virtual bool isValidMove(int nx, int ny, const ChessBoard* board) const;
    virtual bool move(int nx, int ny, ChessBoard* board);
};
#endif