// COMP2811 Coursework 2: data model
// fred
#pragma once

#include <QAbstractTableModel>
#include "dataset.hpp"

// this is the model class for the Water data
// has a dataset object to store the data
// Qvariant data is the header data for the table

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
  WaterDataset getDataset() const { return dataset; }
  /*
  double meanDepth() const { return dataset.meanDepth(); }
  double meanMagnitude() const { return dataset.meanMagnitude(); }
  */

//private:
  WaterDataset dataset;
};
