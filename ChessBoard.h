#pragma once
#ifndef _CHESS_BOARD_H_
#define _CHESS_BOARD_H_

class ChessPiece;
class ChessBoard {
    private:
    ChessPiece* board[8][8];
    int winner = -1;

    public:
    ChessBoard(bool bStd = true);
    // void movePiece(ChessPiece* piece, int nx, int ny);
    ChessPiece* getPiece(int x, int y);
    const ChessPiece* getPiece(int x, int y) const;
    void setPiece(unsigned int x, unsigned int y, ChessPiece* newPiece);
    void win(unsigned int winner);

    friend class ChessConsole;
};

#endif