// COMP2811 Coursework 2 sample solution: main window

#include <QtWidgets>
#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "stats.hpp"
#include "water.hpp"
#include <QtCharts>
#include"dataset.hpp"
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;


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
  string popsList[] = {"PCB Con 028", "PCB Con 105", "PCB Con 052", "PCB Con 101",
  "PCB Con 138", "PCB Con 156", "PCB Con 118", "PCB Con 153", "PCB Con 180"};

  selectOptions(popsList, end(popsList) - begin(popsList));

  table = new QTableView();
  table->setModel(&model);
  QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
  table->setFont(tableFont);

  setCentralWidget(table);
}

void WaterWindow::createPOPs()
{
  string popsList[] = {"PCB Con 028", "PCB Con 105", "PCB Con 052", "PCB Con 101",
  "PCB Con 138", "PCB Con 156", "PCB Con 118", "PCB Con 153", "PCB Con 180"};

  selectOptions(popsList, end(popsList) - begin(popsList));

  string currentPollutant = pollutant->currentText().toStdString();
  string currentlocation = location->currentText().toStdString();
  vector<pair<string, double>> pollutantInfo = model.getDataset().getPollutants(currentPollutant, currentlocation);
  map<string, vector<double>> dateData;
  for (int i = 0; i < pollutantInfo.size(); i++) {
    //for(int j = 0; j < dateData.size(); j++) {
      //if (dateData.find(pollutantInfo[i].first) == date.end()) {
      //  dateData[]
      //}
    //}
    dateData[pollutantInfo[i].first].push_back(pollutantInfo[i].second);
  }

  auto *popsChart = new QChart;
  auto *popSeries = new QBarSeries();
  popSeries->setName("POPs Overview");
  
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

void WaterWindow::selectOptions(string pollutantList[], int size)
{
  vector<string> locations;
  bool exists = false;

  pollutant = new QComboBox();
  location = new QComboBox();  //TODO: MAKE A GETLOCATION FUNCTION FOR A GIVEN POLLUTANT
  for(int i = 0; i < size; i++) {
    pollutant->addItem(QString::fromStdString(pollutantList[i]));

    /*for(string j : locations) {
        if (pollutantList[i]==j) {
          exists = true;
        }
    }
    if (exists == false) {
      locations.push_back(pollutantList[i]);
      location->addItem(QString::fromStdString(pollutantList[i]));
    }
    exists = false;*/
  }
  connect(pollutant, SIGNAL(activated(int)), this, SLOT(updateLocations()));
}

void WaterWindow::updateLocations()
{
  location->clear();
  cout << "UPDATING LOCATION DROP-DOWN" << endl;
  vector<string> locations;
  bool exists = false;
  for (int i = 0; i < pollutant->count(); i++) {
    for (string j : (model.getDataset().getLocations(pollutant->itemText(i).toStdString()))) {
      for (string l : locations) {
        if (j == l) {
          exists = true;
        }
      }
      if (exists == false) {
        locations.push_back(j);
        location->addItem(QString::fromStdString(j));
        cout << location->itemText(location->count()-1).toStdString() << endl; //cout gives correct output but nothing appears on screen
      }
      exists = false;
    }
  }
  location->update();
  //toolBar->addWidget(location);
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
  //QStringList pollutantOptions;
  //pollutantOptions << "pollutants";
  /*std::vector<Water> pollutantsVector = model.dataset.getData();
  for (int i = 0; i < pollutantsVector.size(); i++) {
    pollutantOptions.append(pollutantsVector[i].getDeterminand().getLabel())
  }*/
  /*pollutant = new QComboBox();
  for(std::string i : model.dataset.getLabels()) {
    QMessageBox test;
    test.setText(QString::fromStdString(i));
    test.exec();
    pollutant->addItem(QString::fromStdString(i));
  }*/
  //pollutant->addItems(pollutantOptions);

  /*QStringList locationOptions;
  locationOptions << "hour" << "day" << "week" << "month";
  location = new QComboBox();
  location->addItems(locationOptions);*/
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
  toolBar = new QToolBar();

  QLabel *pollutantLabel = new QLabel("Pollutant");
  pollutantLabel->setAlignment(Qt::AlignVCenter);
  toolBar->addWidget(pollutantLabel);
  toolBar->addWidget(pollutant);

  QLabel *locationLabel = new QLabel("Location");
  locationLabel->setAlignment(Qt::AlignVCenter);
  toolBar->addWidget(locationLabel);
  toolBar->addWidget(location);

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
