#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money =0;

private slots:
    void on_ten_clicked();

    void on_fifty_clicked();

    void on_hundred_clicked();

    void on_tea_clicked();

    void on_exchange_clicked();

    void on_coke_clicked();

    void on_coffee_clicked();

    void change_money(int diff);

    void check_money();
private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
