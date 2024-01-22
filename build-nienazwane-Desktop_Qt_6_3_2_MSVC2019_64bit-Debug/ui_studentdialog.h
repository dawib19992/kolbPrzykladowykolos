/********************************************************************************
** Form generated from reading UI file 'studentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDIALOG_H
#define UI_STUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentdialog
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *studentdialog)
    {
        if (studentdialog->objectName().isEmpty())
            studentdialog->setObjectName(QString::fromUtf8("studentdialog"));
        studentdialog->resize(800, 600);
        centralwidget = new QWidget(studentdialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        studentdialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(studentdialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        studentdialog->setMenuBar(menubar);
        statusbar = new QStatusBar(studentdialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        studentdialog->setStatusBar(statusbar);

        retranslateUi(studentdialog);

        QMetaObject::connectSlotsByName(studentdialog);
    } // setupUi

    void retranslateUi(QMainWindow *studentdialog)
    {
        studentdialog->setWindowTitle(QCoreApplication::translate("studentdialog", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentdialog: public Ui_studentdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
