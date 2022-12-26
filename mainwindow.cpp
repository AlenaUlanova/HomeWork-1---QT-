#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_clicked()
{
    qint32 a = ui->lineEditA->text().toInt();
    qint32 b = ui->lineEditB->text().toInt();
    qint32 c = ui->lineEditC->text().toInt();
    qint32 x1,x2;

    qint32 d = (qPow(b,2)-4*a*c);

    if (a==0){
         ui->lineEditResult->setText("x="+QVariant(-c/b).toString());
    }
    else{
        if (d==0){
           x1 =-b/(2*a);
           ui->lineEditResult->setText("x="+QVariant(x1).toString());
        }
        else if (d<0){
            ui->lineEditResult->setText("Корней нет");
        }
        else {
            x1 = (-b+qSqrt(d))/(2*a);
            x2 = (-b-qSqrt(d))/(2*a);
            ui->lineEditResult->setText("x1="+QVariant(x1).toString()+"x2="+QVariant(x2).toString());
        }
    }
 }

