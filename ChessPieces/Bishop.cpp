#include "Bishop.h"
#include "ChessPiece.h"
#include "../ChessBoard.h"
#include "GlobalFunction.h"
#include <iostream>


Bishop::Bishop(unsigned int Team, int x, int y):ChessPiece(ChessPiece::Bishop, Team, x, y){};

bool Bishop::isValidMove(int nx, int ny, const ChessBoard* board) const {
    // 체스판을 벗어난 경우
    if(nx>=8||ny>=8||nx<0||ny<0) return false;

    // 있던 자리와 동일한 경우
    if(X == nx && Y == ny) return false;

    // 움직이려는 곳에 같은 편 말이 있는 경우 움직일 수 없음
    const ChessPiece* piece = board->getPiece(nx, ny);
    if(piece != nullptr){
        if(piece->Team == this->Team) return false;
    }

    // 대각선으로 이동하는 경우
    int dx = abs(X-nx);
    int dy = abs(Y-ny);
    if(dx != dy) return false;
    if(min(X, nx) == nx){
        if(min(Y, ny) == ny){
            for(int i=1;i<dx-1;i++){
                if(board->getPiece(nx+i, ny+i) != nullptr) return false;
            }
            return true;
        } else {
            for(int i=1;i<dx-1;i++){
                if(board->getPiece(nx+i, ny-i) != nullptr) return false;
            }
            return true;
        }
    } else {
        if(min(Y, ny) == ny){
            for(int i=1;i<dx-1;i++){
                if(board->getPiece(nx-i, ny+i) != nullptr) return false;
            }
            return true;
        } else {
            for(int i=1;i<dx-1;i++){
                if(board->getPiece(nx-i, ny-i) != nullptr) return false;
            }
            return true;
        }
    }
    return false;
}

bool Bishop::move(int nx, int ny, ChessBoard* chessBoard){
    if(!this->isValidMove(nx, ny, chessBoard)) return false;
    return ChessPiece::move(nx, ny, chessBoard);
}