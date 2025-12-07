#ifndef CHESS_FACTORY_H
#define CHESS_FACTORY_H

#include "chess_piece.h"
#include <memory>
#include <map>
#include <functional>

class ChessFactory
{
public:
    virtual ~ChessFactory() = default;

    // Методы для создания конкретных фигур
    virtual std::unique_ptr<ChessPiece> createKing(bool isWhite) = 0;
    virtual std::unique_ptr<ChessPiece> createQueen(bool isWhite) = 0;
    virtual std::unique_ptr<ChessPiece> createRook(bool isWhite) = 0;
    virtual std::unique_ptr<ChessPiece> createBishop(bool isWhite) = 0;
    virtual std::unique_ptr<ChessPiece> createKnight(bool isWhite) = 0;
    virtual std::unique_ptr<ChessPiece> createPawn(bool isWhite) = 0;

    // Фабричный метод для создания фигуры по коду
    virtual std::unique_ptr<ChessPiece> createPieceByCode(const std::string& code, bool isWhite) = 0;

    // Получение символа для отображения текста
    virtual std::string getPieceSymbol(const std::string& code) const = 0;
};

// Фабрика для стандартных шахмат
class StandardChessFactory : public ChessFactory
{
private:
    std::map<std::string, std::function<std::unique_ptr<ChessPiece>(bool)>> pieceCreators;

public:
    StandardChessFactory()
    {
        // Регистрируем создателей фигур
        pieceCreators["K"] = [this](bool white) { return createKing(white); };
        pieceCreators["Q"] = [this](bool white) { return createQueen(white); };
        pieceCreators["R"] = [this](bool white) { return createRook(white); };
        pieceCreators["B"] = [this](bool white) { return createBishop(white); };
        pieceCreators["N"] = [this](bool white) { return createKnight(white); };
        pieceCreators["P"] = [this](bool white) { return createPawn(white); };
    }

    std::unique_ptr<ChessPiece> createKing(bool isWhite) override
    {
        return std::make_unique<King>(isWhite);
    }

    std::unique_ptr<ChessPiece> createQueen(bool isWhite) override
    {
        return std::make_unique<Queen>(isWhite);
    }

    std::unique_ptr<ChessPiece> createRook(bool isWhite) override
    {
        return std::make_unique<Rook>(isWhite);
    }

    std::unique_ptr<ChessPiece> createBishop(bool isWhite) override
    {
        return std::make_unique<Bishop>(isWhite);
    }

    std::unique_ptr<ChessPiece> createKnight(bool isWhite) override
    {
        return std::make_unique<Knight>(isWhite);
    }

    std::unique_ptr<ChessPiece> createPawn(bool isWhite) override
    {
        return std::make_unique<Pawn>(isWhite);
    }

    std::unique_ptr<ChessPiece> createPieceByCode(const std::string& code, bool isWhite) override
    {
        auto it = pieceCreators.find(code);
        if (it != pieceCreators.end()) {
            return it->second(isWhite);
        }
        return nullptr;
    }

    std::string getPieceSymbol(const std::string& code) const override
    {
        // В стандартных шахматах используем обычные символы
        static std::map<std::string, std::string> symbols = {
            {"K", "♔"}, {"Q", "♕"}, {"R", "♖"},
            {"B", "♗"}, {"N", "♘"}, {"P", "♙"},
            {"k", "♚"}, {"q", "♛"}, {"r", "♜"},
            {"b", "♝"}, {"n", "♞"}, {"p", "♟"}
        };

        auto it = symbols.find(code);
        return it != symbols.end() ? it->second : "";
    }
};

// Фабрика для Chess960 (может иметь свою специфику)
class Chess960Factory : public StandardChessFactory
{
public:
    Chess960Factory() : StandardChessFactory()
    {
        // Можно переопределить создание некоторых фигур, если нужно
    }

    // В Chess960 те же фигуры, что и в стандартных шахматах
    // но логика расстановки другая, которая уже есть в Chess960Logic
    std::string getPieceSymbol(const std::string& code) const override
    {
        // Можно использовать другие символы или стили для Chess960
        return StandardChessFactory::getPieceSymbol(code);
    }
};

#endif // CHESS_FACTORY_H
