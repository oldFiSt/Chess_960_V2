QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chess960_logic.cpp \
    chess_factory.cpp \
    chess_piece.cpp \
    chessboard.cpp \
    first_window.cpp \
    main.cpp \
    mainwindow.cpp \
    second_window.cpp

HEADERS += \
    chess960_logic.h \
    chess_factory.h \
    chess_piece.h \
    chessboard.h \
    first_window.h \
    mainwindow.h \
    second_window.h

FORMS += \
    first_window.ui \
    mainwindow.ui \
    second_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    chesse.qrc
