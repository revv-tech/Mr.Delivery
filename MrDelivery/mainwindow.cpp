#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    x = true;

    ui->setupUi(this);
    //PALETTES------------------------------------------------------------------
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    //BACKGROUND----------------------------------------------------------------
    resize(QDesktopWidget().availableGeometry(this).size() * 0.80);
    QPixmap bgnd("/home/rev/Documents/GitHub/Mr.Delivery/ImagenesGUI/bk.jpeg");
    bgnd = bgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bgnd);
    this->setPalette(palette);
    //TEXT BOX----------------------------------------------------------------
    ui->GraphScreen->setReadOnly(true);
    ui->GraphManagerScreen->setReadOnly(true);
    ui->GraphScreen_2->setReadOnly(true);
    ui->recorridoAnch->setCheckable(true);
    ui->costosDesde->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    app->changeGraph();
    QString msg = app->tmpOriginal->printGrafo();
    ui->GraphScreen->setText(msg);
    QString msg2 = app->tmpOriginal->printGrafo();
    ui->GraphManagerScreen->setText(msg2);
}


void MainWindow::on_pushButton_2_clicked()
{
    app = new DeliveryApp();
    app->preStart("/home/rev/Documents/GitHub/Mr.Delivery");
    app->start();
}

void MainWindow::on_caminoOp_clicked(bool checked)
{
    if (!x){
        if (checked){
            QString v1 = ui->V1->toPlainText();
            QString v2 = ui->V2->toPlainText();
            //QString msg = app->tmp->
        }
    }
}

void MainWindow::on_acArtista_clicked()
{
   QString v1 = ui->V1->toPlainText();
   QString v2 = ui->V2->toPlainText();
   app->tmp->desacAristas(v1,v2);
   QString msg2 = app->tmpOriginal->printGrafo();
   ui->GraphManagerScreen->setText(msg2);
}



void MainWindow::on_acVertice_clicked()
{
    QString v2 = ui->V1->toPlainText();
    app->tmp->desacVertices(v2);
    QString msg2 = app->tmpOriginal->printGrafo();
    ui->GraphManagerScreen->setText(msg2);
}

void MainWindow::on_recorridoAnch_clicked(bool checked)
{
    if (x){
        if (checked){
            ui->GraphScreen_2->clear();
            QString v1 = ui->V1->toPlainText();
            QString msg = app->tmp->recorridoAnchura(v1);
            ui->GraphScreen_2->setText(msg);
        }
    }
}

void MainWindow::on_costosDesde_clicked(bool checked)
{
    if (x){
        if (checked){
            ui->GraphScreen_2->clear();
            QString v1 = ui->V1->toPlainText();
            QString msg = app->tmp->CostosHacia(v1);
            ui->GraphScreen_2->setText(msg);
        }
    }
}
