#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <vector>

enum class PieceColor {
    WHITE,
    BLACK
};

enum class PieceType {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN,
    EMPTY
};

class ChessPiece {
public:
    ChessPiece(PieceColor color, PieceType type);
    virtual ~ChessPiece() = default;

    PieceColor getColor() const;
    PieceType getType() const;

    virtual std::string getImageCode() const = 0;
    virtual std::string getSymbol() const = 0;
    virtual bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const = 0;

    static std::string colorToString(PieceColor color);
    static std::string typeToString(PieceType type);

    bool isSameColor(PieceColor otherColor) const;
    bool isEmpty() const;

protected:
    PieceColor color;
    PieceType type;
};

#endif // CHESSPIECE_H
