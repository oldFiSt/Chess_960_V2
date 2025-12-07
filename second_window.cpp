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
    ui(new Ui::Second_window),
    selectedCell(nullptr)
{
    ui->setupUi(this);

    // Инициализируем массив состояний доски
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            chessBoardState[i][j] = "Empty";
        }
    }

    setupBoard();
    setupPieces();
}

Second_window::~Second_window()
{
    delete ui;
}

void Second_window::setupBoard()
{
    // Связываем кнопки с координатами шахматной доски
    // РЯД 0: a8, b8, c8, d8, e8, f8, g8, h8 (черные фигуры)
    squares[0][0] = ui->pushButton_a8;
    squares[0][1] = ui->pushButton_b8;
    squares[0][2] = ui->pushButton_c8;
    squares[0][3] = ui->pushButton_d8;
    squares[0][4] = ui->pushButton_e8;
    squares[0][5] = ui->pushButton_f8;
    squares[0][6] = ui->pushButton_g8;
    squares[0][7] = ui->pushButton_h8;

    // РЯД 1: a7, b7, c7, d7, e7, f7, g7, h7 (черные пешки)
    squares[1][0] = ui->pushButton_a7;
    squares[1][1] = ui->pushButton_b7;
    squares[1][2] = ui->pushButton_c7;
    squares[1][3] = ui->pushButton_d7;
    squares[1][4] = ui->pushButton_e7;
    squares[1][5] = ui->pushButton_f7;
    squares[1][6] = ui->pushButton_g7;
    squares[1][7] = ui->pushButton_h7;

    // РЯД 2: a6, b6, c6, d6, e6, f6, g6, h6
    squares[2][0] = ui->pushButton_a6;
    squares[2][1] = ui->pushButton_b6;
    squares[2][2] = ui->pushButton_c6;
    squares[2][3] = ui->pushButton_d6;
    squares[2][4] = ui->pushButton_e6;
    squares[2][5] = ui->pushButton_f6;
    squares[2][6] = ui->pushButton_g6;
    squares[2][7] = ui->pushButton_h6;

    // РЯД 3: a5, b5, c5, d5, e5, f5, g5, h5
    squares[3][0] = ui->pushButton_a5;
    squares[3][1] = ui->pushButton_b5;
    squares[3][2] = ui->pushButton_c5;
    squares[3][3] = ui->pushButton_d5;
    squares[3][4] = ui->pushButton_e5;
    squares[3][5] = ui->pushButton_f5;
    squares[3][6] = ui->pushButton_g5;
    squares[3][7] = ui->pushButton_h5;

    // РЯД 4: a4, b4, c4, d4, e4, f4, g4, h4
    squares[4][0] = ui->pushButton_a4;
    squares[4][1] = ui->pushButton_b4;
    squares[4][2] = ui->pushButton_c4;
    squares[4][3] = ui->pushButton_d4;
    squares[4][4] = ui->pushButton_e4;
    squares[4][5] = ui->pushButton_f4;
    squares[4][6] = ui->pushButton_g4;
    squares[4][7] = ui->pushButton_h4;

    // РЯД 5: a3, b3, c3, d3, e3, f3, g3, h3
    squares[5][0] = ui->pushButton_a3;
    squares[5][1] = ui->pushButton_b3;
    squares[5][2] = ui->pushButton_c3;
    squares[5][3] = ui->pushButton_d3;
    squares[5][4] = ui->pushButton_e3;
    squares[5][5] = ui->pushButton_f3;
    squares[5][6] = ui->pushButton_g3;
    squares[5][7] = ui->pushButton_h3;

    // РЯД 6: a2, b2, c2, d2, e2, f2, g2, h2 (белые пешки)
    squares[6][0] = ui->pushButton_a2;
    squares[6][1] = ui->pushButton_b2;
    squares[6][2] = ui->pushButton_c2;
    squares[6][3] = ui->pushButton_d2;
    squares[6][4] = ui->pushButton_e2;
    squares[6][5] = ui->pushButton_f2;
    squares[6][6] = ui->pushButton_g2;
    squares[6][7] = ui->pushButton_h2;

    // РЯД 7: a1, b1, c1, d1, e1, f1, g1, h1 (белые фигуры)
    squares[7][0] = ui->pushButton_a1;
    squares[7][1] = ui->pushButton_b1;
    squares[7][2] = ui->pushButton_c1;
    squares[7][3] = ui->pushButton_d1;
    squares[7][4] = ui->pushButton_e1;
    squares[7][5] = ui->pushButton_f1;
    squares[7][6] = ui->pushButton_g1;
    squares[7][7] = ui->pushButton_h1;

    // Устанавливаем размер кнопок
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
            chessBoardState[i][j] = "Empty";
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
            // Преобразуем код фигуры в формат для изображений
            std::string imageCode = "b" + pieceCode;
            // Корректировка имен файлов:
            // K -> k (король)
            // Q -> q (ферзь)
            // R -> r (ладья)
            // B -> b (слон)
            // N -> n (конь)
            std::transform(imageCode.begin(), imageCode.end(), imageCode.begin(), ::tolower);
            chessBoardState[0][col] = imageCode;
            setPiece(0, col, imageCode);
        }
    }

    // Черные пешки (ряд 1 - a7-h7)
    for (int col = 0; col < 8; col++) {
        chessBoardState[1][col] = "bp";
        setPiece(1, col, "bp");
    }

    // Белые фигуры (ряд 7 - a1-h1)
    for (int col = 0; col < 8; col++) {
        std::string pieceCode = chess960.getPieceCode(col);
        if (!pieceCode.empty()) {
            // Преобразуем код фигуры в формат для изображений
            std::string imageCode = "w" + pieceCode;
            std::transform(imageCode.begin(), imageCode.end(), imageCode.begin(), ::tolower);
            chessBoardState[7][col] = imageCode;
            setPiece(7, col, imageCode);
        }
    }

    // Белые пешки (ряд 6 - a2-h2)
    for (int col = 0; col < 8; col++) {
        chessBoardState[6][col] = "wp";
        setPiece(6, col, "wp");
    }
}

void Second_window::setPiece(int row, int col, const std::string& pieceCode)
{
    // Сохраняем оригинальный цвет фона
    QString originalStyle = "";
    if ((row + col) % 2 == 0) {
        originalStyle = "background-color: rgb(200, 143, 104);";
    } else {
        originalStyle = "background-color: rgb(135, 68, 0);";
    }

    if (pieceCode == "Empty" || pieceCode.empty()) {
        squares[row][col]->setIcon(QIcon());
        squares[row][col]->setText("");
        squares[row][col]->setStyleSheet(originalStyle);
        return;
    }

    // Формируем путь к изображению
    QString imagePath = QString(":/icon/%1.png").arg(QString::fromStdString(pieceCode));
    QPixmap pixmap(imagePath);

    if (!pixmap.isNull()) {
        QIcon icon(pixmap);
        squares[row][col]->setIcon(icon);
        squares[row][col]->setIconSize(QSize(60, 60));
        squares[row][col]->setText("");

        // Устанавливаем оригинальный стиль и добавляем padding для иконки
        squares[row][col]->setStyleSheet(originalStyle + "padding: 0px; border: none;");
    } else {
        // Альтернатива: используем текст если изображения нет
        std::cout << "Image not found: " << pieceCode << ".png" << std::endl;
        squares[row][col]->setIcon(QIcon());
        squares[row][col]->setText(QString::fromStdString(getPieceSymbol(pieceCode)));

        // Устанавливаем стиль с цветом текста и оригинальным фоном
        if (pieceCode.find("b") == 0) {
            squares[row][col]->setStyleSheet(originalStyle + "color: black; font-size: 30px; font-weight: bold; padding: 0px; border: none;");
        } else {
            squares[row][col]->setStyleSheet(originalStyle + "color: white; font-size: 30px; font-weight: bold; padding: 0px; border: none;");
        }
    }
}

void Second_window::onCellClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();

    std::cout << "Clicked: " << row << ", " << col << " - " << chessBoardState[row][col] << std::endl;

    // Логика выбора и перемещения фигур
    if (selectedCell == nullptr) {
        // Первый клик - выбираем фигуру
        if (chessBoardState[row][col] != "Empty") {
            selectedCell = clickedButton;
            selectedRow = row;
            selectedCol = col;
            clickedButton->setStyleSheet("background-color: yellow; border: 2px solid red;");
        }
    } else {
        // Второй клик - перемещаем фигуру
        std::string piece = chessBoardState[selectedRow][selectedCol];

        // Удаляем фигуру с предыдущей клетки
        chessBoardState[selectedRow][selectedCol] = "Empty";
        setPiece(selectedRow, selectedCol, "Empty");

        // Ставим фигуру на новую клетку
        chessBoardState[row][col] = piece;
        setPiece(row, col, piece);

        selectedCell = nullptr;
    }
}

std::string Second_window::getPieceSymbol(const std::string& pieceCode)
{
    if (pieceCode == "bk") return "♔";
    else if (pieceCode == "bq") return "♕";
    else if (pieceCode == "br") return "♖";
    else if (pieceCode == "bb") return "♗";
    else if (pieceCode == "bn") return "♘";
    else if (pieceCode == "bp") return "♙";
    else if (pieceCode == "wk") return "♔";
    else if (pieceCode == "wq") return "♕";
    else if (pieceCode == "wr") return "♖";
    else if (pieceCode == "wb") return "♗";
    else if (pieceCode == "wn") return "♘";
    else if (pieceCode == "wp") return "♙";
    return "";
}

