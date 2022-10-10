#include "calc.h"

Calc::Calc()
{

    // Установка первого и последнего дня учебного года и последнего дня календарного года
    first_day.setDate(year, 9, 1);
    last_day_year.setDate(year, 12, 31);
    last_day.setDate(year+1, 5, 31);

    current_date = QDate::currentDate();


    // Инициализация текущей даты и номера недели

}

QDate Calc::Init_current_date()
{

    if (current_date < first_day){
        current_date = first_day;
    }
    if (current_date > last_day_year) {
        current_date = last_day;
    }

    i_week=current_date.weekNumber();
    Calc_num_week(i_week);
    return current_date;
}

int Calc::Calc_num_week(int week)
{
    int tmp_week = week;
    int tmpFirstWeek = 0;
    int firstWeek = first_day.weekNumber();
    if (tmp_week - firstWeek >= 0) {tmp_week = tmp_week +1 - firstWeek;
    }
    else { tmpFirstWeek = last_day_year.weekNumber() - firstWeek;
        tmp_week = tmpFirstWeek + tmp_week + 1 ;
    }
    current_week = tmp_week;
    qDebug() << " Calc current week" << current_week ;
    return current_week;
}

// Вычисление даты понедельника
QDate Calc::Day_mon_week()
{
int num_day_of_week = current_date.dayOfWeek();
day_mon_week = current_date.addDays(1-num_day_of_week);
return day_mon_week;
}

//Обработка сигнала из календаря
void Calc::DateChanged(const QDate &date){

current_date = date;
i_week = date.weekNumber();
Calc_num_week(i_week);
//str_day = current_date.toString(Qt::TextDate);

}
