/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 50, 160, 160));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(370, 50, 131, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 50, 63, 28));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(520, 50, 191, 28));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 280, 201, 141));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "HEX:     #", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1. RGB \342\206\224 LAB \342\206\224 CMYK", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2. RGB \342\206\224 CMYK \342\206\224 HLS", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3. RGB \342\206\224 XYZ \342\206\224 LAB", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4. RGB \342\206\224 HSV \342\206\224 LAB", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "5. CMYK \342\206\224 LAB \342\206\224 HSV", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "6. CMYK \342\206\224 RGB \342\206\224 HLS", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "7. CMYK \342\206\224 RGB \342\206\224 HSV", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "8. RGB \342\206\224 XYZ \342\206\224 HSV", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "9. HSV \342\206\224 XYZ \342\206\224 LAB", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "10. CMYK \342\206\224 LAB \342\206\224 RGB", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "11. XYZ \342\206\224 LAB \342\206\224 HLS", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "12. RGB \342\206\224 XYZ \342\206\224 HLS", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "13. RGB \342\206\224 XYZ \342\206\224 CMYK", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "14. CMYK \342\206\224 LAB \342\206\224 XYZ", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "15. RGB \342\206\224 CMYK \342\206\224 HSV", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "16. CMYK \342\206\224 HLS \342\206\224 XYZ", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "17. RGB \342\206\224 HLS \342\206\224 LAB", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "18. CMYK \342\206\224 XYZ \342\206\224 RG", nullptr));

        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
