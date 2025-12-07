#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <string>
#include <QIcon>
#include <QPixmap>
#include <memory>

// Абстрактный класс фигуры
class ChessPiece
{
public:
    virtual ~ChessPiece() = default;
    virtual QIcon getIcon() const = 0;
    virtual std::string getCode() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getSymbol() const = 0;
    virtual bool isWhite() const = 0;
};

// Базовый класс для фигур с реализацией общих методов
class BaseChessPiece : public ChessPiece
{
protected:
    bool white;
    std::string pieceCode;
    std::string pieceName;
    std::string pieceSymbol;

public:
    BaseChessPiece(bool isWhite, const std::string& code,
                   const std::string& name, const std::string& symbol)
        : white(isWhite), pieceCode(code), pieceName(name), pieceSymbol(symbol) {}

    std::string getCode() const override { return pieceCode; }
    std::string getName() const override { return pieceName; }
    std::string getSymbol() const override { return pieceSymbol; }
    bool isWhite() const override { return white; }

protected:
    QIcon loadIcon(const QString& path) const
    {
        QPixmap pixmap(path);
        if (pixmap.isNull()) {
            // Fallback: создаем иконку с текстом символа
            QPixmap fallback(50, 50);
            fallback.fill(Qt::transparent);
            return QIcon(fallback);
        }
        return QIcon(pixmap);
    }
};

// Конкретные фигуры
class King : public BaseChessPiece
{
public:
    King(bool isWhite) : BaseChessPiece(isWhite, "K", "King", "♔") {}

    QIcon getIcon() const override
    {
        QString color = white ? "white" : "black";
        QString path = QString(":/images/%1_king.png").arg(color);
        return loadIcon(path);
    }
};

class Queen : public BaseChessPiece
{
public:
    Queen(bool isWhite) : BaseChessPiece(isWhite, "Q", "Queen", "♕") {}

    QIcon getIcon() const override
    {
        QString color = white ? "white" : "black";
        QString path = QString(":/images/%1_queen.png").arg(color);
        return loadIcon(path);
    }
};

class Rook : public BaseChessPiece
{
public:
    Rook(bool isWhite) : BaseChessPiece(isWhite, "R", "Rook", "♖") {}

    QIcon getIcon() const override
    {
        QString color = white ? "white" : "black";
        QString path = QString(":/images/%1_rook.png").arg(color);
        return loadIcon(path);
    }
};

class Bishop : public BaseChessPiece
{
public:
    Bishop(bool isWhite) : BaseChessPiece(isWhite, "B", "Bishop", "♗") {}

    QIcon getIcon() const override
    {
        QString color = white ? "white" : "black";
        QString path = QString(":/images/%1_bishop.png").arg(color);
        return loadIcon(path);
    }
};

class Knight : public BaseChessPiece
{
public:
    Knight(bool isWhite) : BaseChessPiece(isWhite, "N", "Knight", "♘") {}

    QIcon getIcon() const override
    {
        QString color = white ? "white" : "black";
        QString path = QString(":/images/%1_knight.png").arg(color);
        return loadIcon(path);
    }
};

class Pawn : public BaseChessPiece
{
public:
    Pawn(bool isWhite) : BaseChessPiece(isWhite, "P", "Pawn", "♙") {}

    QIcon getIcon() const override
    {
        QString color = white ? "white" : "black";
        QString path = QString(":/images/%1_pawn.png").arg(color);
        return loadIcon(path);
    }
};

#endif
