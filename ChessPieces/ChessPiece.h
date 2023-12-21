#pragma once

#ifndef _CHESS_PIECE_H_
#define _CHESS_PIECE_H_
#include <string>

class ChessBoard;
class ChessPiece {
    private:
    unsigned int type;
    unsigned int team;
    int x;
    int y;

    public:
    enum {
        King = 0,
        Queen = 1,
        Bishop = 2,
        Knight = 3,
        Rook = 4,
        Pawn = 5
    };
    enum {
        Black = 1,
        White = 0
    };

    public:
    ChessPiece(unsigned int type, unsigned int team, int x, int y);
    ChessPiece(const ChessPiece& ChessPiece);
    const unsigned int &Type = type;
    const unsigned int &Team = team;
    const int &X = x;
    const int &Y = y;
    void resignPosition(int nx, int ny);
    void printInfo() const;
    std::string getTypeName() const;
    std::string getTeamName() const;       
    virtual bool isValidMove(int nx, int ny, const ChessBoard* Board) const;
    virtual bool move(int nx, int ny, ChessBoard* Board);                                                                                                        
};
#endif