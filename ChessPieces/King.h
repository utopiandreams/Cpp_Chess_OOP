#pragma once

#ifndef _KING_H_
#define _KING_H_

#include "ChessPiece.h"

class King : public ChessPiece {
    private:
    bool firstMove = true;
    
    public:
    King(unsigned int Team, int x, int y);
    virtual bool isValidMove(int nx, int ny, const ChessBoard* board) const;
    virtual bool move(int nx, int ny, ChessBoard* board);
};
#endif