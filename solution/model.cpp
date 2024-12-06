// COMP2811 Coursework 2: data model
// fred
#include "model.hpp"
// this is fine don't change
void WaterModel::updateFromFile(const QString &filename)
{
  beginResetModel();
  dataset.loadData(filename.toStdString());
  endResetModel();
}

// all the attributes (rows) from the dataset need to fix case 2 and 3
QVariant WaterModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
  {
    return QVariant();
  }

  if (role == Qt::TextAlignmentRole)
  {
    return int(Qt::AlignRight | Qt::AlignVCenter);
  }
  else if (role == Qt::DisplayRole)
  {
    Water w = dataset[index.row()];
    switch (index.column())
    {
    case 0:
      return QVariant(w.getId().c_str());
    case 1:
      return QVariant(w.getResult());
    case 2:
      return QVariant(w.getResultQualifier().c_str());
    case 3:
      return QVariant(w.getResultInterpretation().c_str());
    case 4:
      return QVariant(w.getSample().getSamplingPoint().getNotation().c_str());
    case 5:
      return QVariant(w.getSample().getSamplingPoint().getEasting());
    case 6:
      return QVariant(w.getSample().getSamplingPoint().getNorthing());
    case 7:
      return QVariant(w.getSample().getSamplingPoint().getLabel().c_str());
    case 8:
      return QVariant(w.getSample().getPurpose().c_str());
    case 9:
      return QVariant(w.getSample().getMaterialType().c_str());
    case 10:
      return QVariant(w.getSample().getDateTime().c_str());
    case 11:
      return QVariant(w.getSample().getIsCompliance());
    case 12:
      return QVariant(w.getDeterminand().getLabel().c_str());
    case 13:
      return QVariant(w.getDeterminand().getDefinition().c_str());
    case 14:
      return QVariant(w.getDeterminand().getNotation().c_str());
    case 15:
      return QVariant(w.getDeterminand().getUnit().c_str());
    default:
      return QVariant();
    }
  }

  return QVariant();
}

// nees to show all the data
QVariant WaterModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
  {
    return QVariant();
  }

  if (orientation == Qt::Vertical)
  {
    return QVariant(section + 1);
  }

  switch (section)
  {
  case 0:
    return QString("id");
  case 1:
    return QString("result");
  case 2:
    return QString("resultQualifier");
  case 3:
    return QString("resultInterpretation");
  case 4:
    return QString("samplePointNotation");
  case 5:
    return QString("samplePointEasting");
  case 6:
    return QString("samplePointNorthing");
  case 7:
    return QString("samplePointLabel");
  case 8:
    return QString("samplePurpose");
  case 9:
    return QString("sampleMaterialType");
  case 10:
    return QString("sampleDateTime");
  case 11:
    return QString("sampleIsCompliance");
  case 12:
    return QString("determinandLabel");
  case 13:
    return QString("determinandDefinition");
  case 14:
    return QString("determinandNotation");
  case 15:
    return QString("determinandUnit");
  default:
    return QVariant();
  }
}