#include "widget.h"
#include "./ui_widget.h"
#include <qmessagebox.h>
#include <string>


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->coffee->setDisabled(true);
    ui->coke->setDisabled(true);
    ui->tea->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::change_money(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
}

void Widget::check_money()
{
    if(money >= 100)
    {
        ui->coke->setDisabled(false);
        ui->coffee->setDisabled(false);
        ui->tea->setDisabled(false);
    }
    else if(money <100 &&money>= 50)
    {
        ui->coke->setDisabled(false);
        ui->coffee->setDisabled(false);
        ui->tea->setDisabled(true);
    }
    else if(money>=10 &&money<50)
    {
        ui->coke->setDisabled(false);
        ui->coffee->setDisabled(true);
        ui->tea->setDisabled(true);
    }
    else
    {
        ui->coke->setDisabled(true);
        ui->coffee->setDisabled(true);
        ui->tea->setDisabled(true);
    }
}

void Widget::on_ten_clicked()
{
    change_money(10);
    check_money();
}


void Widget::on_fifty_clicked()
{
    change_money(50);
    check_money();
}


void Widget::on_hundred_clicked()
{
    change_money(100);
    check_money();
}


void Widget::on_tea_clicked()
{
    change_money(-100);
    check_money();
}


void Widget::on_exchange_clicked()
{
    int hundred=money/100;
    int fifty = (money%100)/50;
    int ten = (money%100)%50/10;
    QString resultText = QString("100: %1 50: %2 10: %3").arg(hundred).arg(fifty).arg(ten);
    QMessageBox mb;
    mb.information(nullptr,"exchange",resultText);
    QApplication::quit();

}


void Widget::on_coke_clicked()
{
    change_money(-10);
    check_money();
}


void Widget::on_coffee_clicked()
{
    change_money(-50);
    check_money();
}

