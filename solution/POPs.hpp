#pragma once

#include <QWidget>

class QLCDNumber;
class QDial;

class VolumeControl: public QWidget
{
  public:
    VolumeControl();

  private:
    void createWidgets();
    void arrangeWidgets();
    // declare makeConnections method here

    QLCDNumber* number;
    QDial* dial;
};