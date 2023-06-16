#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QLabel* labels[10];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->setVisible(false);
     ui->tableWidget->setVisible(false);

     for(int i=0;i<8;i++) labels[i] = new QLabel;

     for(int i=0;i<8;i++) for(int j=0;j<4;j++) ui->tableWidget->setItem(i,j,new QTableWidgetItem);
     ui->tableWidget->item(1,1)->setText(" ");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login =ui ->login ->text();
    QString password =ui ->pass ->text();

    if (login == "admin" && password == "admin2"){
        QMessageBox::information(this,"Авторизация", "Вы успешно авторизовались");
        ui->statusbar->showMessage("Добро пожаловать!");
        ui->pushButton->hide();
        ui->login->hide();
        ui->pass->hide();
        ui->pushButton->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_5->setVisible(true);
        ui->tableWidget->setVisible(true);

    }
    else {
        QMessageBox::warning(this,"Ошибка", "Ошибка авторизации");
    }
}






void MainWindow::on_pushButton_2_clicked()
{
    QString filename = "Data.txt";
    QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            for(int i=0;i<8;i++) for(int j=0;j<4;j++){
            stream << ui->tableWidget -> item(i,j)-> text() << endl;
            }
           file.close();

        }
}

