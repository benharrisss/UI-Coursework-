// COMP2811 Coursework 2: application entry point
// fred
#include <QtWidgets>
#include "window.hpp"
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QTranslator translator;
  if (translator.load(QLocale::system(), "myapp", "_", ":/i18n")) {
    app.installTranslator(&translator);
  }

    app.setStyleSheet("QWidget {"
                    "background-color: #89bde8;"
                    "font-size: 20px;"
                    "font: arial;"
                    "}"
                    "QPushButton {"
                    "background-color: #4181BF;"
                    "border-radius: 15px;"
                    "padding: 8px;"
                    "font-weight: 600;"
                    "}"
                    
                    "QPushButton:hover {"
                    "background-color: #498BCD;"
                    "}"
                    "QPushButton#LoadButton {"
                    "height: 100px;"
                    "}"
                    "QComboBox {"
                    "background-color: #4181BF;"
                    "}"
                    "QToolBar {"
                    "background-color: #89bde8;"
                    "}"
                    "QLabel {"
                    "font-weight: 600;"
                    "}"
                    );


  WaterWindow window;
  window.resize(1080, 800);
  window.show();

  return app.exec();
}
