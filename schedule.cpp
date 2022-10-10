#include "calc.h"
#include "model.h"
#include "schedule.h"

#include <QAbstractTableModel>
#include <QBoxLayout>
#include <QDate>
#include <QLocale>

  Calc Calc;

Schedule::Schedule(QWidget *parent)
    : QWidget{parent}
{


    current_day_str = new QLabel;
    current_day_str -> setAlignment(Qt::AlignCenter);

    ScheduleTableModel *model = new ScheduleTableModel(8, 4, this);
    model -> headerData(0, Qt::Horizontal, Qt::DisplayRole);

    table_schedule = new QTableView;
    table_schedule -> setModel(model);
    table_schedule -> setColumnWidth( 0, 150);
    table_schedule -> setColumnWidth( 1, 400);
    table_schedule -> setColumnWidth( 2, 50);
//    table_schedule -> setSelectionBehavior(QAbstractItemView::SelectRows);
//    table_schedule -> setSelectionMode(QAbstractItemView::SingleSelection);
//    table_schedule -> setEditTriggers(QAbstractItemView::NoEditTriggers);

    QVBoxLayout *pbvLayout = new QVBoxLayout();
    pbvLayout -> addWidget(current_day_str);
    pbvLayout -> addWidget(current_day_str);
    pbvLayout -> addWidget(table_schedule);

    QWidget::setLayout(pbvLayout);
}


