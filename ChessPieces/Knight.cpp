#include "Knight.h"
#include "ChessPiece.h"
#include "../ChessBoard.h"
#include "GlobalFunction.h"
#include <iostream>

Knight::Knight(unsigned int Team, int x, int y):ChessPiece(ChessPiece::Knight, Team, x, y){};

bool Knight::isValidMove(int nx, int ny, const ChessBoard* board) const {
    // 체스판을 벗어난 경우
    if(nx>=8||ny>=8||nx<0||ny<0) return false;

    // 있던 자리와 동일한 경우
    if(X == nx && Y == ny) return false;

    // 움직이려는 곳에 같은 편 말이 있는 경우 움직일 수 없음
    const ChessPiece* piece = board->getPiece(nx, ny);
    if(piece != nullptr){
        if(piece->Team == this->Team) return false;
    }

    int dx = abs(X-nx);
    int dy = abs(Y-ny);
    if(dx == 1 && dy == 2) return true;
    if(dx == 2 && dy == 1) return true;
    return false;
}

bool Knight::move(int nx, int ny, ChessBoard* chessBoard){
    if(!this->isValidMove(nx, ny, chessBoard)) return false;
    return ChessPiece::move(nx, ny, chessBoard);
}