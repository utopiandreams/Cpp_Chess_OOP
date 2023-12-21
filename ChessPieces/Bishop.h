#pragma once

#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "ChessPiece.h"
class Bishop : public ChessPiece {
    public:
    Bishop(unsigned int Team, int x, int y);
    virtual bool isValidMove(int nx, int ny, const ChessBoard* board) const;
    virtual bool move(int nx, int ny, ChessBoard* board);
};
#endif