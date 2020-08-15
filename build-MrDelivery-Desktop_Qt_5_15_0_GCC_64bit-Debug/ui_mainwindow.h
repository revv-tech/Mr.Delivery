/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title;
    QTextEdit *GraphManagerScreen;
    QTextEdit *GraphScreen;
    QPushButton *verGrafo;
    QPushButton *costosDesde;
    QPushButton *todosCaminos;
    QPushButton *hayCamino;
    QPushButton *caminoOp;
    QPushButton *recorridoProf;
    QPushButton *recorridoAnch;
    QPushButton *arbolExpMin;
    QPushButton *acArtista;
    QPushButton *acVertice;
    QPushButton *avanzar;
    QTextEdit *GraphScreen_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *V1;
    QTextEdit *V2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1397, 968);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Title = new QLabel(centralwidget);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(410, 10, 781, 121));
        Title->setPixmap(QPixmap(QString::fromUtf8("../ImagenesGUI/title.png")));
        GraphManagerScreen = new QTextEdit(centralwidget);
        GraphManagerScreen->setObjectName(QString::fromUtf8("GraphManagerScreen"));
        GraphManagerScreen->setGeometry(QRect(1080, 150, 381, 301));
        GraphScreen = new QTextEdit(centralwidget);
        GraphScreen->setObjectName(QString::fromUtf8("GraphScreen"));
        GraphScreen->setGeometry(QRect(560, 150, 381, 301));
        verGrafo = new QPushButton(centralwidget);
        verGrafo->setObjectName(QString::fromUtf8("verGrafo"));
        verGrafo->setGeometry(QRect(300, 150, 111, 61));
        costosDesde = new QPushButton(centralwidget);
        costosDesde->setObjectName(QString::fromUtf8("costosDesde"));
        costosDesde->setGeometry(QRect(300, 240, 111, 61));
        todosCaminos = new QPushButton(centralwidget);
        todosCaminos->setObjectName(QString::fromUtf8("todosCaminos"));
        todosCaminos->setGeometry(QRect(290, 320, 131, 71));
        hayCamino = new QPushButton(centralwidget);
        hayCamino->setObjectName(QString::fromUtf8("hayCamino"));
        hayCamino->setGeometry(QRect(300, 410, 111, 61));
        caminoOp = new QPushButton(centralwidget);
        caminoOp->setObjectName(QString::fromUtf8("caminoOp"));
        caminoOp->setGeometry(QRect(300, 500, 111, 61));
        recorridoProf = new QPushButton(centralwidget);
        recorridoProf->setObjectName(QString::fromUtf8("recorridoProf"));
        recorridoProf->setGeometry(QRect(270, 580, 171, 61));
        recorridoAnch = new QPushButton(centralwidget);
        recorridoAnch->setObjectName(QString::fromUtf8("recorridoAnch"));
        recorridoAnch->setGeometry(QRect(270, 670, 171, 61));
        arbolExpMin = new QPushButton(centralwidget);
        arbolExpMin->setObjectName(QString::fromUtf8("arbolExpMin"));
        arbolExpMin->setGeometry(QRect(270, 760, 171, 61));
        acArtista = new QPushButton(centralwidget);
        acArtista->setObjectName(QString::fromUtf8("acArtista"));
        acArtista->setGeometry(QRect(1220, 490, 171, 61));
        acVertice = new QPushButton(centralwidget);
        acVertice->setObjectName(QString::fromUtf8("acVertice"));
        acVertice->setGeometry(QRect(1210, 570, 181, 61));
        avanzar = new QPushButton(centralwidget);
        avanzar->setObjectName(QString::fromUtf8("avanzar"));
        avanzar->setGeometry(QRect(670, 470, 171, 61));
        GraphScreen_2 = new QTextEdit(centralwidget);
        GraphScreen_2->setObjectName(QString::fromUtf8("GraphScreen_2"));
        GraphScreen_2->setGeometry(QRect(570, 560, 381, 301));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 330, 141, 111));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 470, 111, 111));
        V1 = new QTextEdit(centralwidget);
        V1->setObjectName(QString::fromUtf8("V1"));
        V1->setGeometry(QRect(1100, 700, 121, 71));
        V2 = new QTextEdit(centralwidget);
        V2->setObjectName(QString::fromUtf8("V2"));
        V2->setGeometry(QRect(1100, 780, 121, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1397, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Title->setText(QString());
        verGrafo->setText(QCoreApplication::translate("MainWindow", "Ver grafo", nullptr));
        costosDesde->setText(QCoreApplication::translate("MainWindow", "Costos Desde", nullptr));
        todosCaminos->setText(QCoreApplication::translate("MainWindow", "Todos los caminos", nullptr));
        hayCamino->setText(QCoreApplication::translate("MainWindow", "Hay camino?", nullptr));
        caminoOp->setText(QCoreApplication::translate("MainWindow", "Camino Optimo", nullptr));
        recorridoProf->setText(QCoreApplication::translate("MainWindow", "Recorrido Profundidad", nullptr));
        recorridoAnch->setText(QCoreApplication::translate("MainWindow", "Recorrido Anchura", nullptr));
        arbolExpMin->setText(QCoreApplication::translate("MainWindow", "Arbol Expansion Minima", nullptr));
        acArtista->setText(QCoreApplication::translate("MainWindow", "Activar / Inactivar Arista", nullptr));
        acVertice->setText(QCoreApplication::translate("MainWindow", "Activar / Inactivar Vertice", nullptr));
        avanzar->setText(QCoreApplication::translate("MainWindow", "Avanzar", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start Graph", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
