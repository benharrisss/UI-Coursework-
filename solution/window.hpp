#pragma once

#include <QMainWindow>
#include "model.hpp"
#include "water.hpp"
#include "fchart.hpp"
#include "pchart.hpp"
#include <QtCharts>
#include <QtWidgets>
#include <QLineSeries>
#include <string>
#include <vector>
#include "overviewPage.hpp"

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
  QComboBox* curLocation(){
    return location;
  }

private:
  void showDataLoadedQuestion();
  void createTableAndModel();
  void createFileSelectors();
  void createButtons();
  void createToolBar();
  void createPageBar();
  void createStatusBar();
  void addFileMenu();
  void addHelpMenu();
  void addPOPMenu();
  void updateFileSelector(QComboBox *selector, QStringList options);
  void formatChart(QChart *chart);

  QWidget* singoltenOverviewPage = nullptr;
  WaterModel model;         // data model used by table
  QString dataLocation;     // location of CSV data files
  QComboBox *pollutant;     // selector for quake feed significance level
  QComboBox *location;      // selector for quake feed time period
  QPushButton *loadButton;  // button to load a new CSV file
  QPushButton *dashboardButton;
  QPushButton *overviewButton;
  QPushButton *popsButton;
  QPushButton *litterButton;
  QPushButton *flourinatedButton;
  QToolBar *toolBar;        // toolbar for file and data controls
  QTableView *table;        // table of quake data
  QLabel *fileInfo;         // status bar info on current file
  StatsDialog *statsDialog; // dialog to display stats
  QLabel *pollutantName;
  QHBoxLayout *mainLayout;
  QLabel *appTitle;
  QHBoxLayout *headerLayout;
  QComboBox *languageSelector;
  QGridLayout *cardLayout;
  QFrame *card;
  QVBoxLayout *cardContent;
  QLabel *title;
  QLabel *pageSummaries;
  QLabel *pageButtons;
  QHBoxLayout *filterLayout;
  QLabel *filterLabel;
  QComboBox *timeFilter;
  QComboBox *regionFilter;
  QHBoxLayout *footerLayout;
  QPushButton *helpButton;
  QPushButton *creditsButton;
  QLabel *helpLink;
  QMessageBox *helpMessage;
  QWidget *popWidget;
  QVBoxLayout *layout;
  QLabel *pfaLabel;
  QLabel *locationLabel;
  QFrame *complianceBar;
  POPChart *pchart;
  QChartView *chartView;
  QBarSeries *litterSeries;
  QBarSet *set1;
  QBarSet *set2;
  QBarSet *set3;
  QBarCategoryAxis *axisX;
  QChart *chart;
  QLineSeries *lineView;
  QChart *litterChart;
  QValueAxis *axisY;
  QChartView *litterChartView;
  QVBoxLayout *litterLayout;
  QWidget *litter;

private slots:
  void setDataLocation();
  void openCSV();
  void displayStats();
  void about();
  void createDashboard();
  void createOverview();
  void createPOPs();
  void createLitter();
  void createFlourinated();
  void createHelpButton();
  void createCreditsButton();
};
