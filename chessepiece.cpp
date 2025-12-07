#include "chessepiece.h"
#include <stdexcept>
#include <algorithm>

// ==================== ChessPiece Base Class ====================

ChessPiece::ChessPiece(PieceColor color, PieceType type)
    : color(color), type(type) {}

PieceColor ChessPiece::getColor() const {
    return color;
}

PieceType ChessPiece::getType() const {
    return type;
}

std::string ChessPiece::colorToString(PieceColor color) {
    return color == PieceColor::WHITE ? "w" : "b";
}

std::string ChessPiece::typeToString(PieceType type) {
    switch(type) {
    case PieceType::KING: return "k";
    case PieceType::QUEEN: return "q";
    case PieceType::ROOK: return "r";
    case PieceType::BISHOP: return "b";
    case PieceType::KNIGHT: return "n";
    case PieceType::PAWN: return "p";
    case PieceType::EMPTY: return "";
    }
    return "";
}

bool ChessPiece::isSameColor(PieceColor otherColor) const {
    return color == otherColor;
}

bool ChessPiece::isEmpty() const {
    return type == PieceType::EMPTY;
}
