#pragma once

#include <QMainWindow>
#include "model.hpp"
#include "water.hpp"
#include<QtCharts>
#include<QtWidgets>
#include <string>
#include <vector>



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
  void selectOptions(std::string pollutantList[], int size);



  WaterModel model;         // data model used by table
  QString dataLocation;     // location of CSV data files
  QComboBox *pollutant;     // selector for quake feed significance level
  QComboBox *location;        // selector for quake feed time period
  QPushButton *loadButton;  // button to load a new CSV file
  QPushButton *statsButton; // button to display dataset stats
  QPushButton *overviewButton;
  QPushButton *popsButton;
  QPushButton *litterButton;
  QPushButton *flourinatedButton;
  QPushButton *complianceButton;
  QToolBar *toolBar;

  QTableView *table;        // table of quake data
  QLabel *fileInfo;         // status bar info on current file
  StatsDialog *statsDialog; // dialog to display stats

  QLabel *pollutantName;
  
  //vector<pair<string, double>> pollutantInfo;

  QStringList *locationOptions;
  QStringList *pollutantOptions;

  QWidget *pops;
  QChart *popChart;
  QChartView *popsChartView;
  QScatterSeries *popSeries;
  QVBoxLayout *popsLayout;


  QMessageBox test;

public slots:
  void setDataLocation();
  void openCSV();
  void displayStats();
  void about();
  void createPOPs();
  void createTest();
  void updateLocations();
};
