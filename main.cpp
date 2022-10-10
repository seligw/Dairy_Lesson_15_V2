#include "day.h"
#include "diary.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Diary w;
    w.show();
    Day d;
    d.show();

    return a.exec();
}
