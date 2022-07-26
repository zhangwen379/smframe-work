/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mvariantslist.h"
#include "qballwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QBallWidget *widget;
    QVBoxLayout *verticalLayout;
    MVariantsList *tableWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_ReadConfig;
    QPushButton *pushButton_WriteConfig;
    QPushButton *pushButton_WriteFile;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Pause;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_ReadFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(868, 615);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QBallWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"border:1px;"));

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new MVariantsList(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_ReadConfig = new QPushButton(centralWidget);
        pushButton_ReadConfig->setObjectName(QStringLiteral("pushButton_ReadConfig"));

        gridLayout->addWidget(pushButton_ReadConfig, 0, 0, 1, 2);

        pushButton_WriteConfig = new QPushButton(centralWidget);
        pushButton_WriteConfig->setObjectName(QStringLiteral("pushButton_WriteConfig"));

        gridLayout->addWidget(pushButton_WriteConfig, 0, 2, 1, 2);

        pushButton_WriteFile = new QPushButton(centralWidget);
        pushButton_WriteFile->setObjectName(QStringLiteral("pushButton_WriteFile"));

        gridLayout->addWidget(pushButton_WriteFile, 1, 2, 1, 2);

        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));

        gridLayout->addWidget(pushButton_Start, 2, 0, 1, 1);

        pushButton_Pause = new QPushButton(centralWidget);
        pushButton_Pause->setObjectName(QStringLiteral("pushButton_Pause"));

        gridLayout->addWidget(pushButton_Pause, 2, 1, 1, 2);

        pushButton_Stop = new QPushButton(centralWidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));

        gridLayout->addWidget(pushButton_Stop, 2, 3, 1, 1);

        pushButton_ReadFile = new QPushButton(centralWidget);
        pushButton_ReadFile->setObjectName(QStringLiteral("pushButton_ReadFile"));

        gridLayout->addWidget(pushButton_ReadFile, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_ReadConfig->setText(QApplication::translate("MainWindow", "Read Config", 0));
        pushButton_WriteConfig->setText(QApplication::translate("MainWindow", "Write Config", 0));
        pushButton_WriteFile->setText(QApplication::translate("MainWindow", "Write File", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButton_Pause->setText(QApplication::translate("MainWindow", "Pause", 0));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "Stop", 0));
        pushButton_ReadFile->setText(QApplication::translate("MainWindow", "Read File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
