#include <iostream>
#include "Pawn.h"
#include "ChessPiece.h"
#include "../ChessBoard.h"
#include "GlobalFunction.h"


Pawn::Pawn(unsigned int Team, int x, int y):ChessPiece(ChessPiece::Pawn, Team, x, y), firstMove(true){};

bool Pawn::isValidMove(int nx, int ny, const ChessBoard* board) const {
    // 체스판을 벗어난 경우
    if(nx>=8||ny>=8||nx<0||ny<0) return false;

    const ChessPiece* piece = board->getPiece(nx, ny);

    // 옮기려는 곳에 기물이 있는 경우
    if(piece != nullptr){
        if(piece->Team == this->Team) return false;
        else {
            if(this->Team == ChessPiece::Black){
                if(nx == X + 1 && (ny == Y - 1 || ny == Y + 1)) return true;
            } else {
                if(nx == X - 1 && (ny == Y - 1 || ny == Y + 1)) return true;
            }
        }

    // 기물이 없는 경우 
    } else {
        if(Y != ny) return false; // 횡 이동인 경우
        if(Team == ChessPiece::Black){
            if(nx == X + 1) return true;
            if(firstMove && nx == X + 2) return true;
        }
        else {
            if(nx == X - 1) return true;
            if(firstMove && nx == X - 2) return true;
        }
    }

    return false;
};

bool Pawn::move(int nx, int ny, ChessBoard* chessBoard){
    if(!this->isValidMove(nx, ny, chessBoard)) return false;
    ChessPiece::move(nx, ny, chessBoard);
    firstMove = false;
    return true;
};