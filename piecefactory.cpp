#include "piecefactory.h"
#include <stdexcept>
#include <iostream>


// создание с помощью фабричного метода
std::unique_ptr<ChessPiece> PieceFactory::createPiece(PieceType type, PieceColor color) {
    switch(type) {
    case PieceType::KING:
        return std::unique_ptr<ChessPiece>(new King(color));
    case PieceType::QUEEN:
        return std::unique_ptr<ChessPiece>(new Queen(color));
    case PieceType::ROOK:
        return std::unique_ptr<ChessPiece>(new Rook(color));
    case PieceType::BISHOP:
        return std::unique_ptr<ChessPiece>(new Bishop(color));
    case PieceType::KNIGHT:
        return std::unique_ptr<ChessPiece>(new Knight(color));
    case PieceType::PAWN:
        return std::unique_ptr<ChessPiece>(new Pawn(color));
    case PieceType::EMPTY:
        return nullptr;
    }
    throw std::invalid_argument("Unknown piece type");
}



PieceFactory::King::King(PieceColor color) : ChessPiece(color, PieceType::KING) {}

std::string PieceFactory::King::getImageCode() const {
    return ChessPiece::colorToString(color) + "k";
}

std::string PieceFactory::King::getSymbol() const {
    return color == PieceColor::WHITE ? "♔" : "♚";
}

bool PieceFactory::King::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    int rowDiff = std::abs(toRow - fromRow);
    int colDiff = std::abs(toCol - fromCol);

    // Король ходит на одну клетку в любом направлении
    return (rowDiff <= 1 && colDiff <= 1) && (rowDiff != 0 || colDiff != 0);
}

// ==================== Queen ====================

PieceFactory::Queen::Queen(PieceColor color) : ChessPiece(color, PieceType::QUEEN) {}

std::string PieceFactory::Queen::getImageCode() const {
    return ChessPiece::colorToString(color) + "q";
}

std::string PieceFactory::Queen::getSymbol() const {
    return color == PieceColor::WHITE ? "♕" : "♛";
}

bool PieceFactory::Queen::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    int rowDiff = std::abs(toRow - fromRow);
    int colDiff = std::abs(toCol - fromCol);

    // Ферзь ходит как слон или ладья
    bool isDiagonal = (rowDiff == colDiff);
    bool isStraight = (rowDiff == 0 && colDiff > 0) || (colDiff == 0 && rowDiff > 0);

    return isDiagonal || isStraight;
}

// ==================== Rook ====================

PieceFactory::Rook::Rook(PieceColor color) : ChessPiece(color, PieceType::ROOK) {}

std::string PieceFactory::Rook::getImageCode() const {
    return ChessPiece::colorToString(color) + "r";
}

std::string PieceFactory::Rook::getSymbol() const {
    return color == PieceColor::WHITE ? "♖" : "♜";
}

bool PieceFactory::Rook::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    // Ладья ходит только по горизонтали или вертикали
    return (fromRow == toRow && fromCol != toCol) || (fromCol == toCol && fromRow != toRow);
}

// ==================== Bishop ====================

PieceFactory::Bishop::Bishop(PieceColor color) : ChessPiece(color, PieceType::BISHOP) {}

std::string PieceFactory::Bishop::getImageCode() const {
    return ChessPiece::colorToString(color) + "b";
}

std::string PieceFactory::Bishop::getSymbol() const {
    return color == PieceColor::WHITE ? "♗" : "♝";
}

bool PieceFactory::Bishop::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    // Слон ходит только по диагонали
    return std::abs(toRow - fromRow) == std::abs(toCol - fromCol);
}

// ==================== Knight ====================

PieceFactory::Knight::Knight(PieceColor color) : ChessPiece(color, PieceType::KNIGHT) {}

std::string PieceFactory::Knight::getImageCode() const {
    return ChessPiece::colorToString(color) + "n";
}

std::string PieceFactory::Knight::getSymbol() const {
    return color == PieceColor::WHITE ? "♘" : "♞";
}

bool PieceFactory::Knight::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    int rowDiff = std::abs(toRow - fromRow);
    int colDiff = std::abs(toCol - fromCol);

    // Конь ходит буквой "Г"
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

// ==================== Pawn ====================

PieceFactory::Pawn::Pawn(PieceColor color) : ChessPiece(color, PieceType::PAWN) {}

std::string PieceFactory::Pawn::getImageCode() const {
    return ChessPiece::colorToString(color) + "p";
}

std::string PieceFactory::Pawn::getSymbol() const {
    return color == PieceColor::WHITE ? "♙" : "♟";
}

bool PieceFactory::Pawn::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    int direction = (color == PieceColor::WHITE) ? -1 : 1;
    int startRow = (color == PieceColor::WHITE) ? 6 : 1;

    // Обычный ход на одну клетку вперед
    if (fromCol == toCol && toRow == fromRow + direction) {
        return true;
    }

    // Первый ход на две клетки вперед
    if (fromCol == toCol && fromRow == startRow && toRow == fromRow + 2 * direction) {
        return true;
    }

    // Взятие по диагонали
    if (std::abs(toCol - fromCol) == 1 && toRow == fromRow + direction) {
        return true;
    }

    return false;
}
