#include "calc.h"
#include "diary.h"
#include "schedule.h"
#include "ui_diary.h"

Calc CalcDiary;

Diary::Diary(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Diary)
{
    ui->setupUi(this);

    //  Инициализация ScrollBar
    int last_week = CalcDiary.Calc_num_week(CalcDiary.last_day.weekNumber());
    scroll_bar->setMinimum (1);
    scroll_bar->setMaximum (last_week);
    scroll_bar->setPageStep (page_step);

    //  Инициализация текущей даты
    CalcDiary.Init_current_date();
    scroll_bar->setValue(CalcDiary.current_week);
    int diary_current_week = CalcDiary.current_week;
    qDebug() <<" diary current week" << CalcDiary.current_week;

    //  Создание таблиц расписания и упаковка в GridLayout
    resize(1500,980);
    int k = 0;
    for (int i = 0 ; i < 2; i++ )
        for (int j = 0; j < 3; j++){
            table_schedule[k] = new Schedule(this);
            table_schedule[k] -> current_day_str -> setText(Header(k, diary_current_week));
            pgrdLayout -> addWidget(table_schedule[k], j, i);
            k++;
        }

    //  Сигнал изменение значения ползунка в ScroolBar
    connect (scroll_bar, &QScrollBar::valueChanged, this, &Diary::value_changed);

    //  Вывод таблиц расписания и Scollbar на экран
    pgrdLayout->setEnabled(false);
    QVBoxLayout *pbvLayout = new QVBoxLayout();
    dairy->setLayout(pbvLayout);
    pbvLayout->addLayout(pgrdLayout);
    pbvLayout->addWidget(scroll_bar);
    this->setCentralWidget(dairy);
}

Diary::~Diary()
{
    delete ui;
}
    //  Функция вывода дня и номера недели
QString Diary::Header(int k, int num_week)
{
    QLocale locale  = QLocale(QLocale::Russian, QLocale::Russia);
    QDate tmp_mon = CalcDiary.Day_mon_week().addDays(k);
    QString russian_date = locale.toString(tmp_mon, "dddd, d MMMM yyyy");
    QString header = russian_date + "    Неделя №" + QString::number(num_week);
    return header;
}

    // Положение ползунка в scrollBar
QDate Diary::selectedDateChanged(const QDate &date)
{
    CalcDiary.DateChanged(date);
    scroll_bar->setValue(CalcDiary.current_week);
    return selected_day = date;
}

    //Слот для изменения дат и номера недели из scrollBar
void Diary::value_changed(int inum_week)
{
    QDate first_sept = CalcDiary.first_day;
    QDate date;
    date = first_sept.addDays((inum_week-1) * 7);
    qDebug() << "scroolbar date" << date;
    qDebug() << "inum week" << inum_week;
    CalcDiary.current_date = date;
    int k = 0;
    for (int i = 0 ; i < 2; i++ )
        for (int j = 0; j < 3; j++){
            table_schedule[k] -> current_day_str -> setText(Header(k, inum_week));
            k++;
        }
}
