#include "ChessGraphics.h"
#include "ChessPieces/ChessPiece.h"
#include <string>

std::string ChessGraphics::ToChar(const ChessPiece* chessPiece) const {
    std::string type;
    if(chessPiece == 0){
        return "..";
    } else {
        switch(chessPiece->Type){
            case ChessPiece::King:
            type = "킹";
            break;

            case ChessPiece::Queen:
            type = "퀸";
            break;

            case ChessPiece::Bishop:
            type = "빗";
            break; 

            case ChessPiece::Knight:
            type = "낱";
            break;

            case ChessPiece::Rook:
            type = "룩";
            break;

            case ChessPiece::Pawn:
            type = "폰";
            break;

            default:
            return 0;
        }
    }
    if(chessPiece->Team == ChessPiece::Black){
        return "\033[1;31m" + type + "\033[0m";
    } else return type;
};