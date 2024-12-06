// COMP2811 Coursework 2 sample solution: main window

#include <QtWidgets>
#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "stats.hpp"
#include "water.hpp"
#include<QtCharts>


static const int MIN_WIDTH = 620;

WaterWindow::WaterWindow() : QMainWindow(), statsDialog(nullptr)
{
  createTest();
  createFileSelectors();
  createButtons();
  createToolBar();
  createStatusBar();
  addFileMenu();
  addHelpMenu();

  createPageBar();

  createPOPs();

  setMinimumWidth(MIN_WIDTH);
  setWindowTitle("Water Tool");
}


void WaterWindow::createTest()
{
  table = new QTableView();
  table->setModel(&model);

  QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
  table->setFont(tableFont);

  setCentralWidget(table);
}

void WaterWindow::createPOPs()
{
  auto popsChart = new QChart;

  auto popSeries = new QScatterSeries();
  popSeries->setName("POPs Overview");
  popSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);
  popSeries->setMarkerSize(15.0);
  popSeries->append(0, 6);
  popSeries->append(2, 4);
  popSeries->append(3, 8);
  popSeries->append(7, 4);
  popSeries->append(10, 5);
  
  popsChart->addSeries(popSeries);
  popsChart->setTitle("POPs Overview");
  popsChart->createDefaultAxes();
  
  auto popsChartView = new QChartView(popsChart);

  auto popsLayout = new QVBoxLayout();
  popsLayout->addWidget(popsChartView);
  pops = new QWidget();
  pops->setLayout(popsLayout);
  //pops->addWidget(popsChart);
  
  setCentralWidget(pops);
}

void WaterWindow::createPageBar()
{
  QToolBar *pageBar = new QToolBar();

  pageBar->addWidget(overviewButton);
  pageBar->addWidget(popsButton);
  pageBar->addWidget(litterButton);
  pageBar->addWidget(flourinatedButton);
  pageBar->addWidget(complianceButton);


  addToolBar(Qt::TopToolBarArea, pageBar);
}


// change this
void WaterWindow::createFileSelectors()
{
  QStringList pollutantOptions;
  pollutantOptions << "pollutants";
  pollutant = new QComboBox();
  pollutant->addItems(pollutantOptions);

  QStringList periodOptions;
  periodOptions << "hour" << "day" << "week" << "month";
  period = new QComboBox();
  period->addItems(periodOptions);
}

void WaterWindow::createButtons()
{
  loadButton = new QPushButton("Load");
  statsButton = new QPushButton("Stats");
  overviewButton = new QPushButton("Overview");
  popsButton = new QPushButton("POPs");
  litterButton = new QPushButton("Litter Indicators");
  flourinatedButton = new QPushButton("Flourinated compounds");
  complianceButton = new QPushButton("Compliance Dashboard");


  connect(loadButton, SIGNAL(clicked()), this, SLOT(openCSV()));
  connect(statsButton, SIGNAL(clicked()), this, SLOT(displayStats()));
  connect(overviewButton, SIGNAL(clicked()), this, SLOT(createTest()));
  connect(popsButton, SIGNAL(clicked()), this, SLOT(createPOPs()));
  connect(litterButton, SIGNAL(clicked()), this, SLOT(createLitter()));
  connect(flourinatedButton, SIGNAL(clicked()), this, SLOT(createFlourinated()));
  connect(complianceButton, SIGNAL(clicked()), this, SLOT(createCompliance()));
}

void WaterWindow::createToolBar()
{
  QToolBar *toolBar = new QToolBar();

  QLabel *pollutantLabel = new QLabel("Pollutant");
  pollutantLabel->setAlignment(Qt::AlignVCenter);
  toolBar->addWidget(pollutantLabel);
  toolBar->addWidget(pollutant);

  QLabel *periodLabel = new QLabel("Period");
  periodLabel->setAlignment(Qt::AlignVCenter);
  toolBar->addWidget(periodLabel);
  toolBar->addWidget(period);

  toolBar->addSeparator();

  toolBar->addWidget(loadButton);
  toolBar->addWidget(statsButton);

  addToolBar(Qt::LeftToolBarArea, toolBar);
}

void WaterWindow::createStatusBar()
{
  fileInfo = new QLabel("Current file: <none>");
  QStatusBar *status = statusBar();
  status->addWidget(fileInfo);
}

void WaterWindow::addFileMenu()
{
  QAction *locAction = new QAction("Set Data &Location", this);
  locAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
  connect(locAction, SIGNAL(triggered()), this, SLOT(setDataLocation()));

  QAction *closeAction = new QAction("Quit", this);
  closeAction->setShortcut(QKeySequence::Close);
  connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

  QMenu *fileMenu = menuBar()->addMenu("&File");
  fileMenu->addAction(locAction);
  fileMenu->addAction(closeAction);
}

void WaterWindow::addHelpMenu()
{
  QAction *aboutAction = new QAction("&About", this);
  connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

  QAction *aboutQtAction = new QAction("About &Qt", this);
  connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  QMenu *helpMenu = menuBar()->addMenu("&Help");
  helpMenu->addAction(aboutAction);
  helpMenu->addAction(aboutQtAction);
}


void WaterWindow::setDataLocation()
{
  QString directory = QFileDialog::getExistingDirectory(
      this, "Data Location", ".",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if (directory.length() > 0)
  {
    dataLocation = directory;
  }
}

void WaterWindow::openCSV()
{
  if (dataLocation == "")
  {
    QMessageBox::critical(this, "Data Location Error",
                          "Data location has not been set!\n\n"
                          "You can specify this via the File menu.");
    return;
  }

  auto filename = QString("Y-2024.csv");

  auto path = dataLocation + "/" + filename;
  std::cout << path.toStdString() << std::endl;
  try
  {
    model.updateFromFile(path);
  }
  catch (const std::exception &error)
  {
    QMessageBox::critical(this, "CSV File Error", error.what());
    return;
  }

  fileInfo->setText(QString("Current file: <kbd>%1</kbd>").arg(filename));
  table->resizeColumnsToContents();

  if (statsDialog != nullptr)
  {
    statsDialog->hide();
  }
}

// this is the function for the table view
// needs to be updated to view from water using stats dialouge

void WaterWindow::displayStats()
{
  if (model.hasData())
  {
    if (statsDialog == nullptr)
    {
      statsDialog = new StatsDialog(this);
    }

    // statsDialog->update(model.meanDepth(), model.meanMagnitude());

    statsDialog->show();
    statsDialog->raise();
    statsDialog->activateWindow();
  }
}


void WaterWindow::about()
{
  QMessageBox::about(this, "About Quake Tool",
                     "Quake Tool displays and analyzes earthquake data loaded from"
                     "a CSV file produced by the USGS Earthquake Hazards Program.\n\n"
                     "(c) 2024 Nick Efford");
}