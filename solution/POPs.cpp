#include <QtWidgets>
#include "window.hpp"

VolumeControl::VolumeControl()
{
  createWidgets();
  arrangeWidgets();
  setWindowTitle("Volume Control");
}

void VolumeControl::createWidgets()
{
  number = new QLCDNumber(3);
  number->display(50);

  dial = new QDial();
  dial->setRange(0, 100);
  dial->setValue(50);
  dial->setNotchesVisible(true);
}

void VolumeControl::arrangeWidgets()
{
  QGridLayout* layout = new QGridLayout();

  layout->addWidget(number, 0, 0);
  layout->addWidget(dial, 1, 0);
  layout->setRowMinimumHeight(0, 75);

  setLayout(layout);
}

// Implement makeConnections method here