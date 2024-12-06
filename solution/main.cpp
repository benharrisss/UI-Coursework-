// COMP2811 Coursework 2: application entry point
// fred
#include <QtWidgets>
#include "window.hpp"
#include <QtCharts>

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  WaterWindow window;
  window.show();

  return app.exec();
}