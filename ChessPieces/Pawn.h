#pragma once
#ifndef _PAWN_H_
#define _PAWN_H_

#include "ChessPiece.h"

class Pawn : public ChessPiece {
    private:
    bool firstMove;

    public:
    Pawn(unsigned int Team, int x, int y);
    virtual bool isValidMove(int nx, int ny, const ChessBoard* board) const;
    virtual bool move(int nx, int ny, ChessBoard* board);
};
#endif
