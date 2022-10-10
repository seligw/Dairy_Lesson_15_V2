#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QLabel>
#include <QObject>
#include <QTableView>
#include <QWidget>

class Schedule : public QWidget
{
    Q_OBJECT
public:
    explicit Schedule(QWidget *parent = nullptr);
    QLabel* current_day_str;

private:
    QTableView* table_schedule;



signals:

};

#endif // SCHEDULE_H
