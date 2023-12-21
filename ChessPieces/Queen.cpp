#include "Queen.h"
#include "ChessPiece.h"
#include "../ChessBoard.h"
#include "GlobalFunction.h"
#include <iostream>


Queen::Queen(unsigned int Team, int x, int y):ChessPiece(ChessPiece::Queen, Team, x, y){};

bool Queen::isValidMove(int nx, int ny, const ChessBoard* board) const {
    // 체스판을 벗어난 경우
    if(nx>=8||ny>=8||nx<0||ny<0) return false;

    // 있던 자리와 동일한 경우
    if(X == nx && Y == ny) return false;

    // 움직이려는 곳에 같은 편 말이 있는 경우 움직일 수 없음
    const ChessPiece* piece = board->getPiece(nx, ny);
    if(piece != nullptr){
        if(piece->Team == this->Team) return false;
    }
    
    // 종으로 이동하는 경우
    if(X == nx){
        for(int i=(min(Y, ny)+1); i<(max(Y, ny)-1); i++){
            std::cout << i << std::endl;
            if(board->getPiece(X, i) != nullptr) return false;
        }
        return true;
    }

    // 횡으로 이동하는 경우
    if (Y == ny){
        for(int i=min(X, nx)+1; i<max(X, nx)-1; i++){
            std::cout << i << std::endl;
            if(board->getPiece(i, Y) != nullptr) return false;
        }
        return true;
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

bool Queen::move(int nx, int ny, ChessBoard* chessBoard){
    if(!this->isValidMove(nx, ny, chessBoard)) return false;
    return ChessPiece::move(nx, ny, chessBoard);
}