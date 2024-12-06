// COMP2811 Coursework 2 sample solution: dialog
// fred
#include <QtWidgets>
#include "stats.hpp"

StatsDialog::StatsDialog(QWidget *parent) : QDialog(parent)
{
  createWidgets();
  arrangeWidgets();
  setWindowTitle("Quake Stats");
}

// what is this
void StatsDialog::update(double dep, double mag)
{
  meanDepth->setText(QString::number(dep, 'f', 1));
  meanMagnitude->setText(QString::number(mag, 'f', 1));
}

// needs to be changed
void StatsDialog::createWidgets()
{
  meanDepth = new QLineEdit("?");
  meanDepth->setMaxLength(5);
  meanDepth->setReadOnly(true);

  meanMagnitude = new QLineEdit("?");
  meanMagnitude->setMaxLength(3);
  meanMagnitude->setReadOnly(true);

  closeButton = new QPushButton("Close");
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void StatsDialog::arrangeWidgets()
{
  QFormLayout *form = new QFormLayout();
  form->addRow("Mean depth (km):", meanDepth);
  form->addRow("Mean magnitude:", meanMagnitude);

  QVBoxLayout *box = new QVBoxLayout();
  box->addLayout(form);
  box->addWidget(closeButton);

  setLayout(box);
}