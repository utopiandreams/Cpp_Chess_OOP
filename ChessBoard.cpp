#include "ChessBoard.h"

#include "ChessPieces/Pawn.h"
#include "ChessPieces/King.h"
#include "ChessPieces/Queen.h"
#include "ChessPieces/Rook.h"
#include "ChessPieces/Bishop.h"
#include "ChessPieces/Knight.h"


ChessBoard::ChessBoard(bool bStd){
    winner = -1;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j] = 0;
        }
    }

    if(bStd){
        for(unsigned int i=0;i<8;i++){
            board[1][i] = new Pawn(1, 1, i);
            board[6][i] = new Pawn(0, 6, i);
        }
        board[0][3] = new King(1, 0, 3);
        board[7][3] = new King(0, 7, 3);

        board[0][4] = new Queen(1, 0, 4);
        board[7][4] = new Queen(0, 7, 4);

        board[0][0] = new Rook(1, 0, 0);
        board[0][7] = new Rook(1, 0, 7);
        board[7][0] = new Rook(0, 7, 0);
        board[7][7] = new Rook(0, 7, 7);

        board[0][1] = new Bishop(1, 0, 1);
        board[0][6] = new Bishop(1, 0, 6);
        board[7][1] = new Bishop(0, 7, 1);
        board[7][6] = new Bishop(0, 7, 6);

        board[0][2] = new Knight(1, 0, 2);
        board[0][5] = new Knight(1, 0, 5);
        board[7][2] = new Knight(0, 7, 2);
        board[7][5] = new Knight(0, 7, 5);
    }
}

ChessPiece* ChessBoard::getPiece(int x, int y){
    return board[x][y];
}
const ChessPiece* ChessBoard::getPiece(int x, int y) const{
    return board[x][y];
}
void ChessBoard::setPiece(unsigned int x, unsigned int y, ChessPiece* newPiece){
    this->board[x][y] = newPiece;
}
void ChessBoard::win(unsigned int winner){
    this->win(winner);
}