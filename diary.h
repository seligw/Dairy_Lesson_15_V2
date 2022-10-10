#ifndef DIARY_H
#define DIARY_H

#include "schedule.h"

#include <QDate>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QScrollBar>

namespace Ui {
class Diary;
}

class Diary : public QMainWindow
{
    Q_OBJECT

public:
    explicit Diary(QWidget *parent = nullptr);
    ~Diary();

    static const int d = 6;
    Schedule* table_schedule[d];
    QGridLayout* pgrdLayout = new QGridLayout;
    QWidget *dairy = new QWidget;
    int page_step = 1;  //шаг полосы прокрутки
    int val_changed; // принимает номер недели в Scrollbare
    QScrollBar *scroll_bar = new QScrollBar(Qt::Horizontal);
    QDate selected_day;

    QString Header(int k, int num_week);


public slots:
    void value_changed(int i_num_week);
    QDate selectedDateChanged(const QDate &date);

private:
    Ui::Diary *ui;
};

#endif // DIARY_H
