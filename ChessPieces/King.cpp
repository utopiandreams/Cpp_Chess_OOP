#include "King.h"
#include "ChessPiece.h"
#include "../ChessBoard.h"
#include "GlobalFunction.h"
#include <iostream>

King::King(unsigned int Team, int x, int y):ChessPiece(ChessPiece::King, Team, x, y), firstMove(true){};

bool King::isValidMove(int nx, int ny, const ChessBoard* board) const {
    // 체스판을 벗어난 경우
    if(nx>=8||ny>=8||nx<0||ny<0) return false;

    const ChessPiece* piece = board->getPiece(nx, ny);

    if(piece != nullptr){
        if(piece->Team == this->Team) return false;
    }

    else {
        std::cout << abs(X-nx) << std::endl;
        std::cout << abs(Y-ny) << std::endl;
        if((abs(X-nx) == 1 && Y == ny) || (abs(Y-ny) == 1 && X == nx)) return true;
        if(abs(X-nx) == 1 && abs(Y-ny) == 1) return true;
    }
    return false;
}

bool King::move(int nx, int ny, ChessBoard* chessBoard){
    if(!this->isValidMove(nx, ny, chessBoard)) return false;
    ChessPiece::move(nx, ny, chessBoard);
    firstMove = false;
    return true;
}