// COMP2811 Coursework 2 sample solution: dialog

#pragma once

#include <QDialog>

class QLineEdit;
class QPushButton;

class StatsDialog: public QDialog
{
  public:
    StatsDialog(QWidget*);
    void update(double, double);

  private:
    QLineEdit* meanDepth;
    QLineEdit* meanMagnitude;
    QPushButton* closeButton;
    void createWidgets();
    void arrangeWidgets();
};
