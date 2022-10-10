#ifndef DAY_H
#define DAY_H

#include <QCalendarWidget>
#include <QDialog>
#include "schedule.h"

namespace Ui {
class Day;
}

class Day : public QDialog
{
    Q_OBJECT

public:
    explicit Day(QWidget *parent = nullptr);
    Schedule* table_view;
    QCalendarWidget* calendar;

    ~Day();

private:
    Ui::Day *ui;
};

#endif // DAY_H
