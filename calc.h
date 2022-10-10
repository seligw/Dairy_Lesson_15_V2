#ifndef CALC_H
#define CALC_H

#include <QDate>



class Calc
{
public:
    Calc();

    const int year = 2022;
    QDate first_day;
    QDate last_day;
    QDate last_day_year;
    int current_week;
    QDate current_date;
    int number_week;
    //int calc_week;
    int i_week;
    QDate day_mon_week;
    int last_week;

    QDate Init_current_date();
    int Calc_num_week(int week);
    QDate Day_mon_week();
    void DateChanged(const QDate &date);
};





#endif // CALC_H
