#include "second_window.h"
#include "ui_second_window.h"
#include <QIcon>
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <ctime>
#include <cstdlib>

Second_window::Second_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Second_window)
{
    ui->setupUi(this);

    // Инициализируем доску нулевыми указателями
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }

    setupBoard();
    setupPieces();
}

Second_window::~Second_window()
{
    // Очищаем память от фигур
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete board[i][j];
        }
    }

    delete ui;
}

void Second_window::setupBoard()
{


    squares[0][0] = ui->pushButton_a8;
    squares[0][1] = ui->pushButton_b8;
    squares[0][2] = ui->pushButton_c8;
    squares[0][3] = ui->pushButton_d8;
    squares[0][4] = ui->pushButton_e8;
    squares[0][5] = ui->pushButton_f8;
    squares[0][6] = ui->pushButton_g8;
    squares[0][7] = ui->pushButton_h8;

    squares[1][0] = ui->pushButton_a7;
    squares[1][1] = ui->pushButton_b7;
    squares[1][2] = ui->pushButton_c7;
    squares[1][3] = ui->pushButton_d7;
    squares[1][4] = ui->pushButton_e7;
    squares[1][5] = ui->pushButton_f7;
    squares[1][6] = ui->pushButton_g7;
    squares[1][7] = ui->pushButton_h7;

    squares[2][0] = ui->pushButton_a6;
    squares[2][1] = ui->pushButton_b6;
    squares[2][2] = ui->pushButton_c6;
    squares[2][3] = ui->pushButton_d6;
    squares[2][4] = ui->pushButton_e6;
    squares[2][5] = ui->pushButton_f6;
    squares[2][6] = ui->pushButton_g6;
    squares[2][7] = ui->pushButton_h6;

    squares[3][0] = ui->pushButton_a5;
    squares[3][1] = ui->pushButton_b5;
    squares[3][2] = ui->pushButton_c5;
    squares[3][3] = ui->pushButton_d5;
    squares[3][4] = ui->pushButton_e5;
    squares[3][5] = ui->pushButton_f5;
    squares[3][6] = ui->pushButton_g5;
    squares[3][7] = ui->pushButton_h5;

    squares[4][0] = ui->pushButton_a4;
    squares[4][1] = ui->pushButton_b4;
    squares[4][2] = ui->pushButton_c4;
    squares[4][3] = ui->pushButton_d4;
    squares[4][4] = ui->pushButton_e4;
    squares[4][5] = ui->pushButton_f4;
    squares[4][6] = ui->pushButton_g4;
    squares[4][7] = ui->pushButton_h4;

    squares[5][0] = ui->pushButton_a3;
    squares[5][1] = ui->pushButton_b3;
    squares[5][2] = ui->pushButton_c3;
    squares[5][3] = ui->pushButton_d3;
    squares[5][4] = ui->pushButton_e3;
    squares[5][5] = ui->pushButton_f3;
    squares[5][6] = ui->pushButton_g3;
    squares[5][7] = ui->pushButton_h3;

    squares[6][0] = ui->pushButton_a2;
    squares[6][1] = ui->pushButton_b2;
    squares[6][2] = ui->pushButton_c2;
    squares[6][3] = ui->pushButton_d2;
    squares[6][4] = ui->pushButton_e2;
    squares[6][5] = ui->pushButton_f2;
    squares[6][6] = ui->pushButton_g2;
    squares[6][7] = ui->pushButton_h2;

    squares[7][0] = ui->pushButton_a1;
    squares[7][1] = ui->pushButton_b1;
    squares[7][2] = ui->pushButton_c1;
    squares[7][3] = ui->pushButton_d1;
    squares[7][4] = ui->pushButton_e1;
    squares[7][5] = ui->pushButton_f1;
    squares[7][6] = ui->pushButton_g1;
    squares[7][7] = ui->pushButton_h1;

    // Устанавливаем размер кнопок и начальные цвета
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (squares[row][col]) {
                squares[row][col]->setFixedSize(80, 80);

                // Устанавливаем цвет клетки
                if ((row + col) % 2 == 0) {
                    squares[row][col]->setStyleSheet("background-color: rgb(200, 143, 104); padding: 0px; border: none;");
                } else {
                    squares[row][col]->setStyleSheet("background-color: rgb(135, 68, 0); padding: 0px; border: none;");
                }
            }
        }
    }

    // Соединяем все кнопки с обработчиком
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (squares[row][col]) {
                connect(squares[row][col], &QPushButton::clicked, this, &Second_window::onCellClicked);
                squares[row][col]->setProperty("row", row);
                squares[row][col]->setProperty("col", col);
            }
        }
    }
}

void Second_window::setupPieces()
{
    // Очищаем доску
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            delete board[i][j];
            board[i][j] = nullptr;
            squares[i][j]->setIcon(QIcon());
            squares[i][j]->setText("");
        }
    }

    // Генерируем позицию Chess960
    chess960.generatePosition();

    // Черные фигуры (ряд 0 - a8-h8)
    for (int col = 0; col < 8; col++) {
        std::string pieceCode = chess960.getPieceCode(col);
        if (!pieceCode.empty()) {
            PieceType type;
            if (pieceCode == "K") type = PieceType::KING;
            else if (pieceCode == "Q") type = PieceType::QUEEN;
            else if (pieceCode == "R") type = PieceType::ROOK;
            else if (pieceCode == "B") type = PieceType::BISHOP;
            else if (pieceCode == "N") type = PieceType::KNIGHT;
            else continue;


            // установка с помощью Factory метода
            auto piece = PieceFactory::createPiece(type, PieceColor::BLACK);
            setPiece(0, col, std::move(piece));
        }
    }

    // Черные пешки (ряд 1 - a7-h7)
    for (int col = 0; col < 8; col++) {
        auto pawn = PieceFactory::createPiece(PieceType::PAWN, PieceColor::BLACK);
        setPiece(1, col, std::move(pawn));
    }

    // Белые фигуры (ряд 7 - a1-h1)
    for (int col = 0; col < 8; col++) {
        std::string pieceCode = chess960.getPieceCode(col);
        if (!pieceCode.empty()) {
            PieceType type;
            if (pieceCode == "K") type = PieceType::KING;
            else if (pieceCode == "Q") type = PieceType::QUEEN;
            else if (pieceCode == "R") type = PieceType::ROOK;
            else if (pieceCode == "B") type = PieceType::BISHOP;
            else if (pieceCode == "N") type = PieceType::KNIGHT;
            else continue;

            auto piece = PieceFactory::createPiece(type, PieceColor::WHITE);
            setPiece(7, col, std::move(piece));
        }
    }

    // Белые пешки (ряд 6 - a2-h2)
    for (int col = 0; col < 8; col++) {
        auto pawn = PieceFactory::createPiece(PieceType::PAWN, PieceColor::WHITE);
        setPiece(6, col, std::move(pawn));
    }
}

void Second_window::setPiece(int row, int col, std::unique_ptr<ChessPiece> piece)
{
    // Удаляем старую фигуру, если есть
    delete board[row][col];

    // Сохраняем новую фигуру
    board[row][col] = piece.release();

    // Сохраняем оригинальный цвет фона
    QString originalStyle = "";
    if ((row + col) % 2 == 0) {
        originalStyle = "background-color: rgb(200, 143, 104);";
    } else {
        originalStyle = "background-color: rgb(135, 68, 0);";
    }

    // Обновляем отображение
    if (board[row][col]) {
        // Формируем путь к изображению
        QString imagePath = QString(":/icon/%1.png").arg(QString::fromStdString(board[row][col]->getImageCode()));
        QPixmap pixmap(imagePath);

        if (!pixmap.isNull()) {
            QIcon icon(pixmap);
            squares[row][col]->setIcon(icon);
            squares[row][col]->setIconSize(QSize(60, 60));
            squares[row][col]->setText("");
            squares[row][col]->setStyleSheet(originalStyle + " padding: 0px; border: none;");
        } else {
            // Альтернатива: используем символ
            squares[row][col]->setIcon(QIcon());
            squares[row][col]->setText(QString::fromStdString(board[row][col]->getSymbol()));

            if (board[row][col]->getColor() == PieceColor::WHITE) {
                squares[row][col]->setStyleSheet(originalStyle + " color: white; font-size: 30px; font-weight: bold; padding: 0px; border: none;");
            } else {
                squares[row][col]->setStyleSheet(originalStyle + " color: black; font-size: 30px; font-weight: bold; padding: 0px; border: none;");
            }
        }
    } else {
        squares[row][col]->setIcon(QIcon());
        squares[row][col]->setText("");
        squares[row][col]->setStyleSheet(originalStyle);
    }
}

void Second_window::onCellClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();

    std::cout << "Clicked: " << row << ", " << col << std::endl;

    // Если фигура не выбрана
    if (selectedRow == -1 || selectedCol == -1) {
        // Проверяем, есть ли фигура в клетке
        if (board[row][col]) {
            selectedRow = row;
            selectedCol = col;
            clickedButton->setStyleSheet("background-color: yellow; border: 2px solid red;");
        }
    } else {
        // Пытаемся сделать ход
        movePiece(selectedRow, selectedCol, row, col);
        clearSelection();
    }
}

void Second_window::movePiece(int fromRow, int fromCol, int toRow, int toCol)
{
    if (!board[fromRow][fromCol]) {
        std::cout << "No piece to move!" << std::endl;
        return;
    }

    // Проверяем валидность хода (базовая проверка без учета других фигур)
    if (board[fromRow][fromCol]->isValidMove(fromRow, fromCol, toRow, toCol)) {
        std::cout << "Move is valid!" << std::endl;

        // Удаляем фигуру на целевой клетке, если есть
        delete board[toRow][toCol];

        // Перемещаем фигуру
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = nullptr;

        // Обновляем отображение
        setPiece(fromRow, fromCol, nullptr);
        setPiece(toRow, toCol, std::unique_ptr<ChessPiece>(board[toRow][toCol]));

    } else {
        std::cout << "Invalid move!" << std::endl;
        QMessageBox::warning(this, "Invalid Move", "This move is not valid!");
    }
}

void Second_window::clearSelection()
{
    if (selectedRow != -1 && selectedCol != -1) {
        // Восстанавливаем цвет и стиль клетки
        setPiece(selectedRow, selectedCol, std::unique_ptr<ChessPiece>(board[selectedRow][selectedCol]));

        selectedRow = -1;
        selectedCol = -1;
    }
}
