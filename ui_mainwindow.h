/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon May 13 11:48:57 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actAddPdf;
    QAction *actAddPath;
    QAction *actRemovePath;
    QAction *actionAdd_Catagory;
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *textInput;
    QComboBox *categoryCombo;
    QTableWidget *resultWindow;
    QPushButton *quitButton;
    QMenuBar *menubar;
    QMenu *menuAdd;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(280, 301);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actAddPdf = new QAction(MainWindow);
        actAddPdf->setObjectName(QString::fromUtf8("actAddPdf"));
        actAddPath = new QAction(MainWindow);
        actAddPath->setObjectName(QString::fromUtf8("actAddPath"));
        actRemovePath = new QAction(MainWindow);
        actRemovePath->setObjectName(QString::fromUtf8("actRemovePath"));
        actionAdd_Catagory = new QAction(MainWindow);
        actionAdd_Catagory->setObjectName(QString::fromUtf8("actionAdd_Catagory"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 10, 258, 251));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label);

        textInput = new QLineEdit(widget);
        textInput->setObjectName(QString::fromUtf8("textInput"));

        horizontalLayout->addWidget(textInput);

        categoryCombo = new QComboBox(widget);
        categoryCombo->setObjectName(QString::fromUtf8("categoryCombo"));

        horizontalLayout->addWidget(categoryCombo);


        verticalLayout->addLayout(horizontalLayout);

        resultWindow = new QTableWidget(widget);
        resultWindow->setObjectName(QString::fromUtf8("resultWindow"));

        verticalLayout->addWidget(resultWindow);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 280, 21));
        menuAdd = new QMenu(menubar);
        menuAdd->setObjectName(QString::fromUtf8("menuAdd"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAdd->menuAction());
        menuAdd->addAction(actAddPdf);
        menuAdd->addAction(actionAdd_Catagory);
        menuAdd->addAction(actAddPath);
        menuAdd->addAction(actRemovePath);

        retranslateUi(MainWindow);
        QObject::connect(quitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actAddPdf->setText(QApplication::translate("MainWindow", "Add New PDF", 0, QApplication::UnicodeUTF8));
        actAddPath->setText(QApplication::translate("MainWindow", "Add Path", 0, QApplication::UnicodeUTF8));
        actRemovePath->setText(QApplication::translate("MainWindow", "Remove Path", 0, QApplication::UnicodeUTF8));
        actionAdd_Catagory->setText(QApplication::translate("MainWindow", "Add Catagory", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        menuAdd->setTitle(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
