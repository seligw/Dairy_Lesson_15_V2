#include <QCalendarWidget>
#include<QDate>
#include <QPushButton>
#include <QVBoxLayout>

#include "day.h"
#include "model.h"
#include "schedule.h"
#include "ui_day.h"

Day::Day(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Day)
{
    ui->setupUi(this);

    table_view = new Schedule(this);

    // Создание заголовка виджета, размера и фона
    QWidget::setWindowTitle("Расписание на день");
    QWidget::resize(1200, 330);
    QPalette pal1;
    pal1.setColor(this->backgroundRole(), Qt::gray);
    this->setPalette(pal1);
    this-> setAutoFillBackground(true);

    //Создание календаря и сигнала из него
    calendar = new QCalendarWidget;
    calendar -> setMinimumDate(QDate(2022, 9, 1));
    calendar -> setMaximumDate(QDate(2023, 5, 31));
    calendar -> setGridVisible(true);
    calendar-> setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendar -> setMaximumSize(400,250);

    // Создание и вывод слоев (таблица и дата, календарь) , кнопки
    QPushButton* save = new QPushButton("Save");
    QPushButton* cancel = new QPushButton("Cancel");

    QHBoxLayout *pbhLayoutButt = new QHBoxLayout();
    pbhLayoutButt->addWidget(save);
    pbhLayoutButt->addWidget(cancel);
    pbhLayoutButt->setSpacing(100);

    QVBoxLayout *pbvLayout = new QVBoxLayout();
    pbvLayout->addWidget(calendar);
    pbvLayout->addLayout(pbhLayoutButt);

    QHBoxLayout *pbhLayout = new QHBoxLayout();
    pbhLayout -> addWidget(table_view);
    pbhLayout->addLayout(pbvLayout);

    this->setLayout(pbhLayout);




    QWidget::setLayout(pbvLayout);
}

Day::~Day()
{
    delete ui;
}
