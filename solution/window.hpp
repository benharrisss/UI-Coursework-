// COMP2811 Coursework 2 sample solution: main window

#pragma once

#include <QMainWindow>
#include "model.hpp"
#include "water.hpp"
#include<QtCharts>
#include<QtWidgets>


class QString;
class QComboBox;
class QLabel;
class QPushButton;
class QTableView;
class StatsDialog;

class WaterWindow : public QMainWindow
{
  Q_OBJECT

public:
  WaterWindow();

private:
  void createFileSelectors();
  void createButtons();
  void createToolBar();
  void createPageBar();
  void createStatusBar();
  void addFileMenu();
  void addHelpMenu();
  void addPOPMenu();




  WaterModel model;         // data model used by table
  QString dataLocation;     // location of CSV data files
  QComboBox *pollutant;     // selector for quake feed significance level
  QComboBox *period;        // selector for quake feed time period
  QPushButton *loadButton;  // button to load a new CSV file
  QPushButton *statsButton; // button to display dataset stats
  QPushButton *overviewButton;
  QPushButton *popsButton;
  QPushButton *litterButton;
  QPushButton *flourinatedButton;
  QPushButton *complianceButton;

  QTableView *table;        // table of quake data
  QLabel *fileInfo;         // status bar info on current file
  StatsDialog *statsDialog; // dialog to display stats

  QLabel *pollutantName;

  QWidget *pops;
  QChart *popChart;
  QChartView *popsChartView;
  QScatterSeries *popSeries;
  QVBoxLayout *popsLayout;

private slots:
  void setDataLocation();
  void openCSV();
  void displayStats();
  void about();
  void createPOPs();
  void createTest();
};