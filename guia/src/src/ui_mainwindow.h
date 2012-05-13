/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 7 15:39:01 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *textLayout;
    QTreeView *treeView;
    QGridLayout *gridLayout;
    QPushButton *inicioBtn;
    QPushButton *accessPointBtn;
    QPushButton *informeHtmlBtn;
    QPushButton *resetBtn;
    QPushButton *salirBtn;
    QPushButton *informePdfBtn;
    QPushButton *channelBtn;
    QProgressBar *barraProg;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *imageLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textLayout = new QVBoxLayout();
        textLayout->setSpacing(6);
        textLayout->setObjectName(QString::fromUtf8("textLayout"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        treeView->setAlternatingRowColors(true);
        treeView->setSortingEnabled(true);
        treeView->header()->setHighlightSections(true);

        textLayout->addWidget(treeView);


        verticalLayout_3->addLayout(textLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        inicioBtn = new QPushButton(centralWidget);
        inicioBtn->setObjectName(QString::fromUtf8("inicioBtn"));
        inicioBtn->setEnabled(true);

        gridLayout->addWidget(inicioBtn, 0, 1, 1, 1);

        accessPointBtn = new QPushButton(centralWidget);
        accessPointBtn->setObjectName(QString::fromUtf8("accessPointBtn"));
        accessPointBtn->setCheckable(true);
        accessPointBtn->setChecked(true);
        accessPointBtn->setAutoExclusive(true);

        gridLayout->addWidget(accessPointBtn, 0, 3, 1, 1);

        informeHtmlBtn = new QPushButton(centralWidget);
        informeHtmlBtn->setObjectName(QString::fromUtf8("informeHtmlBtn"));

        gridLayout->addWidget(informeHtmlBtn, 0, 5, 1, 1);

        resetBtn = new QPushButton(centralWidget);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));

        gridLayout->addWidget(resetBtn, 0, 7, 1, 1);

        salirBtn = new QPushButton(centralWidget);
        salirBtn->setObjectName(QString::fromUtf8("salirBtn"));

        gridLayout->addWidget(salirBtn, 1, 7, 1, 1);

        informePdfBtn = new QPushButton(centralWidget);
        informePdfBtn->setObjectName(QString::fromUtf8("informePdfBtn"));

        gridLayout->addWidget(informePdfBtn, 1, 5, 1, 1);

        channelBtn = new QPushButton(centralWidget);
        channelBtn->setObjectName(QString::fromUtf8("channelBtn"));
        channelBtn->setCheckable(true);
        channelBtn->setAutoExclusive(true);

        gridLayout->addWidget(channelBtn, 1, 3, 1, 1);

        barraProg = new QProgressBar(centralWidget);
        barraProg->setObjectName(QString::fromUtf8("barraProg"));
        barraProg->setValue(24);

        gridLayout->addWidget(barraProg, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 6, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 8, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 8, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        imageLayout = new QVBoxLayout();
        imageLayout->setSpacing(6);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));
        imageLayout->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout_3->addLayout(imageLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        inicioBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        accessPointBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        informeHtmlBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        resetBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        salirBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        informePdfBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        channelBtn->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
