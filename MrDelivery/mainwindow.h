#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deliveryapp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool x;
    DeliveryApp *app;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_caminoOp_clicked(bool checked);

    void on_acArtista_clicked();

    void on_acVertice_clicked();

    void on_recorridoAnch_clicked(bool checked);

    void on_costosDesde_clicked(bool checked);

    void on_avanzar_clicked();

    void on_hayCamino_clicked();

    void on_caminoOp_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
