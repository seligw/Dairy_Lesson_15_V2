#include "model.h"

#include <QString>
#include <QObject>
#include <QString>

Model:: Model(int rows, int cols, QObject *parent)
    : QAbstractTableModel{parent}, row_count(rows), col_count(cols)
{

}


QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
             return QVariant();
         if (orientation == Qt::Horizontal)
             return QString(list[section]);
        else
             return QString("%1").arg(section+1);
}

int Model::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return row_count;
}

int Model::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.count();
}

//bool Model::hasChildren(const QModelIndex &parent) const
//{
//    // FIXME: Implement me!
//}

//bool Model::canFetchMore(const QModelIndex &parent) const
//{
//    // FIXME: Implement me!
//    return false;
//}

//void Model::fetchMore(const QModelIndex &parent)
//{
//    // FIXME: Implement me!
//}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        return QVariant();
    }
    if (role == Qt::DisplayRole || role == Qt::EditRole){
        qDebug() << "cell data"<< cell_data;
        return cell_data.value(index, QVariant());
    }    
    return QVariant();
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        emit dataChanged(index, index, {role});
        cell_data.insert(index, value);
        qDebug() << "cell"<<  value;
        return true;
    }
    return false;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

ScheduleTableModel::ScheduleTableModel(int rows, int cols, QObject *parent): Model (rows, cols, parent)
{

}

void ScheduleTableModel::setLessons(int row, int col, QString note)
{
    setData(index(row, col), note, Qt::EditRole);
}
