#include "model.hpp"

void WaterModel::updateFromFile(const QString &filename)
{
  beginResetModel();
  dataset.loadData(filename.toStdString());
  endResetModel();
}

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
    return QString(tr("id"));
  case 1:
    return QString(tr("result"));
  case 2:
    return QString(tr("resultQualifier"));
  case 3:
    return QString(tr("resultInterpretation"));
  case 4:
    return QString(tr("samplePointNotation"));
  case 5:
    return QString(tr("samplePointEasting"));
  case 6:
    return QString(tr("samplePointNorthing"));
  case 7:
    return QString(tr("samplePointLabel"));
  case 8:
    return QString(tr("samplePurpose"));
  case 9:
    return QString(tr("sampleMaterialType"));
  case 10:
    return QString(tr("sampleDateTime"));
  case 11:
    return QString(tr("sampleIsCompliance"));
  case 12:
    return QString(tr("determinandLabel"));
  case 13:
    return QString(tr("determinandDefinition"));
  case 14:
    return QString(tr("determinandNotation"));
  case 15:
    return QString(tr("determinandUnit"));
  default:
    return QVariant();
  }
}
