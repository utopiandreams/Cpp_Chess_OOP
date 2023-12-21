#include "Rook.h"
#include "ChessPiece.h"
#include "../ChessBoard.h"
#include "GlobalFunction.h"
#include <iostream>

Rook::Rook(unsigned int Team, int x, int y):ChessPiece(ChessPiece::Rook, Team, x, y){};

bool Rook::isValidMove(int nx, int ny, const ChessBoard* board) const {
    // 체스판을 벗어난 경우
    if(nx>=8||ny>=8||nx<0||ny<0) return false;

    // 있던 자리와 동일한 경우
    if(X == nx && Y == ny) return false;

    // 움직이려는 곳에 같은 편 말이 있는 경우
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

    return false;
}

bool Rook::move(int nx, int ny, ChessBoard* chessBoard){
    if(!this->isValidMove(nx, ny, chessBoard)) return false;
    firstMove = false;
    return ChessPiece::move(nx, ny, chessBoard);
}