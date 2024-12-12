#pragma once

#include <QAbstractTableModel>
#include "dataset.hpp"

// data vector of water objects
class WaterModel : public QAbstractTableModel
{
public:
  WaterModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {}
  void updateFromFile(const QString &);
  bool hasData() const { return dataset.size() > 0; }

  int rowCount(const QModelIndex &index) const { return dataset.size(); }
  int columnCount(const QModelIndex &index) const { return 17; }
  QVariant data(const QModelIndex &, int) const;
  QVariant headerData(int, Qt::Orientation, int) const;
  WaterDataset getData() const { return dataset; }

private:
  WaterDataset dataset;
};
