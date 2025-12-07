#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "chessepiece.h"
#include <memory>

class PieceFactory {
public:
    static std::unique_ptr<ChessPiece> createPiece(PieceType type, PieceColor color);

private:
    // Конкретные классы фигур
    class King : public ChessPiece {
    public:
        King(PieceColor color);
        std::string getImageCode() const override;
        std::string getSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };

    class Queen : public ChessPiece {
    public:
        Queen(PieceColor color);
        std::string getImageCode() const override;
        std::string getSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };

    class Rook : public ChessPiece {
    public:
        Rook(PieceColor color);
        std::string getImageCode() const override;
        std::string getSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };

    class Bishop : public ChessPiece {
    public:
        Bishop(PieceColor color);
        std::string getImageCode() const override;
        std::string getSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };

    class Knight : public ChessPiece {
    public:
        Knight(PieceColor color);
        std::string getImageCode() const override;
        std::string getSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };

    class Pawn : public ChessPiece {
    public:
        Pawn(PieceColor color);
        std::string getImageCode() const override;
        std::string getSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };
};

#endif // PIECEFACTORY_H
