/********************************************************************************
** Form generated from reading UI file 'first_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_WINDOW_H
#define UI_FIRST_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_First_window
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;

    void setupUi(QDialog *First_window)
    {
        if (First_window->objectName().isEmpty())
            First_window->setObjectName("First_window");
        First_window->resize(800, 800);
        verticalLayoutWidget = new QWidget(First_window);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 300, 391, 378));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font.setPointSize(20);
        font.setBold(true);
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font);

        verticalLayout->addWidget(pushButton_4);

        label = new QLabel(First_window);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 90, 381, 161));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font1.setPointSize(48);
        font1.setBold(false);
        label->setFont(font1);
        label_4 = new QLabel(First_window);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, 40, 191, 201));
        label_4->setPixmap(QPixmap(QString::fromUtf8("C:/Users/egorr/Downloads/new(1).png")));
        label_2 = new QLabel(First_window);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 40, 191, 201));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/egorr/Downloads/newnwe.png")));

        retranslateUi(First_window);

        QMetaObject::connectSlotsByName(First_window);
    } // setupUi

    void retranslateUi(QDialog *First_window)
    {
        First_window->setWindowTitle(QCoreApplication::translate("First_window", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("First_window", "\320\230\320\263\321\200\320\260 \321\201 \320\221\320\276\321\202\320\276\320\274 ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("First_window", "\320\230\320\263\321\200\320\260 \320\277\320\276 \321\201\320\265\321\202\320\270", nullptr));
        pushButton_3->setText(QCoreApplication::translate("First_window", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260 \320\270\320\263\321\200\321\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("First_window", "\320\222\321\213\321\205\320\276\320\264 ", nullptr));
        label->setText(QCoreApplication::translate("First_window", "Chess-960", nullptr));
        label_4->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class First_window: public Ui_First_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_WINDOW_H
