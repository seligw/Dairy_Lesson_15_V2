#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QObject>

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Model(int rows, int cols, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Fetch data dynamically:
//    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

//    bool canFetchMore(const QModelIndex &parent) const override;
//    void fetchMore(const QModelIndex &parent) override;

    QVariant data(const QModelIndex &index, int role ) const override ;

    // Editable
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

public:
    QString model_data;

private:
    const int row_count = 8;
    const int col_count = 5;
    QStringList list = {"Предмет", "Домашнее задание", "Оценка", "Примечание"};


protected:
    QHash <QModelIndex, QVariant> cell_data;
};

class ScheduleTableModel : public Model
{
    Q_OBJECT

public:
    ScheduleTableModel(int rows, int cols, QObject *parent = nullptr);
    void setLessons(int row, int col, QString note);

};

#endif // MODEL_H
