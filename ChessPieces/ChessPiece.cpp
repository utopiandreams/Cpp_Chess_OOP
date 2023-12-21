#include "ChessPiece.h"
#include "../ChessBoard.h"
#include <iostream>
#include <string>

ChessPiece::ChessPiece(unsigned int type, unsigned int team, int x, int y)
:type(type), team(team), x(x), y(y){};
ChessPiece::ChessPiece(const ChessPiece& piece):type(piece.Type), team(piece.Team), x(piece.x), y(piece.y){};

void ChessPiece::printInfo() const {
    std::cout << "position : (" << (char)('A'+x) << ", " << y+1 << ")" << std::endl;
    std::cout << "team : " << getTeamName() << ", type : " << getTypeName() << std::endl;
}

std::string ChessPiece::getTypeName() const {
    switch(this->type){
        case 0:
            return "킹";
        case 1:
            return "퀸";
        case 2:
            return "비솝";
        case 3:
            return "나이트";
        case 4:
            return "룩";
        case 5:
            return "폰";
        default:
            return "?";
    }
}

std::string ChessPiece::getTeamName() const {
    switch(this->Team){
        case 0:
            return "White";
        case 1:
            return "Black";
        default:
            return "?";
    }
}

bool ChessPiece::isValidMove(int nx, int ny, const ChessBoard* board) const{
    return true;
}

bool ChessPiece::move(int nx, int ny, ChessBoard* chessBoard){
    ChessPiece* thisPostion = chessBoard->getPiece(X, Y);
    ChessPiece* newPosition = chessBoard->getPiece(nx, ny);
    
    // 옮길 위치에 상대 기물이 있는 경우, 해당 기물을 삭제함
    if(newPosition != nullptr) {
        if(newPosition->Type == ChessPiece::King) chessBoard->win(thisPostion->Team);
        delete newPosition;
    }
    chessBoard->setPiece(nx, ny, thisPostion);
    chessBoard->setPiece(X, Y, nullptr);
    resignPosition(nx, ny);
    return true;
}

void ChessPiece::resignPosition(int nx, int ny){
    this->x = nx;
    this->y = ny;
}