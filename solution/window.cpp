// COMP2811 Coursework 2 sample solution: main window

#include <QtWidgets>
#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "stats.hpp"
#include "water.hpp"
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QToolBox>
#include <QProgressBar>
#include <QFrame>
#include "dataset.hpp"
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "overviewPage.hpp"
#include <QMessageBox>

static const int MIN_WIDTH = 620;

WaterWindow::WaterWindow() : QMainWindow(), statsDialog(nullptr)
{
  createFileSelectors();
  createButtons();
  createToolBar();
  createStatusBar();
  addFileMenu();
  addHelpMenu();
  createPageBar();
  setMinimumWidth(MIN_WIDTH);
  setWindowTitle(tr("Water Tool"));
}

void WaterWindow::createDashboard()
{
  setCentralWidget(0);

  QWidget *dashboardWidget = new QWidget();
 
  QVBoxLayout *mainLayout = new QVBoxLayout(dashboardWidget);

  // Header
  QLabel *appTitle = new QLabel(tr("Water Quality Monitor"));
  appTitle->setAlignment(Qt::AlignCenter);
  appTitle->setStyleSheet("font-size: 24px; font-weight: bold;");

  // Cards for each page
  QGridLayout *cardLayout = new QGridLayout;

  QStringList categories = {tr("Pollutant Overview"), tr("Persistant Organic Pollutants (POPs)"), tr("Environmental Litter Indicators"), tr("Flourinated Compounds")};
  QStringList summaries = {tr("Detailed information on common pollutants like 1,1,2-Trichloroethane and Chloroform."), tr("Data on PCBs and other persistant organnic pollutants due to their long-lasting impact on the environment and health."), tr("Average levels of physical pollutants such as plsatic litter and other visible debris in water."), tr("Levels of PFAs and other fluorinated compounds, which are monitored for their environmental persistance.")};

  for (int i = 0; i < categories.size(); ++i) {
    QFrame *card = new QFrame;
    card->setFrameShape(QFrame::Box);
    card->setStyleSheet("border: 2px solid gray; border-radius: 5px;");

    QVBoxLayout *cardContent = new QVBoxLayout(card);

    QLabel *title = new QLabel(categories[i]);
    title->setStyleSheet("font-weight: bold; font-size: 18px;");

    QLabel *pageSummaries = new QLabel(summaries[i]);
    pageSummaries->setStyleSheet("font-size: 12px;");

    QPushButton *pageButton = new QPushButton(tr("View Page"));

    cardContent->addWidget(title);
    cardContent->addWidget(pageSummaries);
    cardContent->addWidget(pageButton);
    cardLayout->addWidget(card, i / 2, i % 2);

    if (categories[i] == "Pollutant Overview") {
      connect(pageButton, SIGNAL(clicked()), this, SLOT(createOverview()));
    } else if (categories[i] == "Persistant Organic Pollutants (POPs)") {
      connect(pageButton, SIGNAL(clicked()), this, SLOT(createPOPs()));
    } else if (categories[i] == "Environmental Litter Indicators") {
      connect(pageButton, SIGNAL(clicked()), this, SLOT(createLitter()));
    } else if (categories[i] == "Flourinated Compounds") {
      connect(pageButton, SIGNAL(clicked()), this, SLOT(createFlourinated()));
    }
  }

    // Filters
    QHBoxLayout *filterLayout = new QHBoxLayout;
    QLabel *filterLabel = new QLabel(tr("Filter By:"));
    QComboBox *timeFilter = new QComboBox();
    timeFilter->addItems({tr("Last Month"), tr("Last Year"), tr("Custom Range")});

    QComboBox *regionFilter = new QComboBox();
    regionFilter->addItems({tr("All Locations"), tr("Location 1"), tr("Location 2")});

    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(timeFilter);
    filterLayout->addWidget(regionFilter);

    // Footer
    QHBoxLayout *footerLayout = new QHBoxLayout;
    QPushButton *helpButton = new QPushButton(tr("Help and User Guide"));
    connect(helpButton, SIGNAL(clicked()), this, SLOT(createHelpButton()));
    QPushButton *creditsButton = new QPushButton(tr("Credits to Data Sources and More Information"));
    connect(creditsButton, SIGNAL(clicked()), this, SLOT(createCreditsButton()));

    footerLayout->addWidget(helpButton);
    footerLayout->addWidget(creditsButton);

    // Add alll layouts to main layout
    mainLayout->addWidget(appTitle);
    mainLayout->addLayout(cardLayout);
    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(footerLayout);

    setCentralWidget(dashboardWidget);

}

void WaterWindow::createTableAndModel()
{
  setCentralWidget(0);

  table = new QTableView();
  table->setModel(&model);

  QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
  table->setFont(tableFont);

}

void WaterWindow::showDataLoadedQuestion()
{
  //todo dhejhrfuws
  QMessageBox *msgBox = new QMessageBox(this);
  msgBox->setWindowTitle(tr("Question"));
  msgBox->setText(tr("Do you want to see the loaded data?"));
  msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox->setDefaultButton(QMessageBox::No);

  int ret = msgBox->exec();

  if (ret == QMessageBox::Yes)
  {
    // Handle Yes response
    setCentralWidget(table);
  }
}

void WaterWindow::createOverview()
{
  //todo make singolton? for some reasen breaks the code
  //if(!singoltenOverviewPage) {
  OverviewPage* page = new OverviewPage(this, &model);
  singoltenOverviewPage = page->createOverviewPage();
  //}
  //QVBoxLayout* layout = WaterOverviewPage::createOverviewPage();
  setCentralWidget(singoltenOverviewPage);
}

void WaterWindow::createPOPs()
{
  setCentralWidget(0);

  QWidget *popWidget = new QWidget();
  QVBoxLayout *layout = new QVBoxLayout();

  QLabel *pfaLabel = new QLabel("label");
  QLabel *locationLabel = new QLabel("location");
  QFrame *complianceBar = new QFrame();

  complianceBar->setFrameShape(QFrame::HLine);
  complianceBar->setFixedHeight(10);

  layout->addWidget(pfaLabel);
  layout->addWidget(locationLabel);
  layout->addWidget(complianceBar);

  POPChart *pchart = new POPChart();
  if (model.hasData())
  {
    pchart->loadDataset(model.getData());
  }

  // Create file selectors specific to this window

  updateFileSelector(pollutant, pchart->getDeterminands());
  updateFileSelector(location, pchart->getLocations(pollutant->currentText().toStdString()));

  // Create a chart and chart view
  pchart->loadDataset(model.getData());
  QChart *chart = new QChart();
  pchart->initChart(chart);
  formatChart(chart);
  std::cout << "chart created" << std::endl;
  QChartView *chartView = new QChartView(chart);
  layout->addWidget(chartView);

  // Connect selectors to a slot for updating the chart
  connect(pollutant, &QComboBox::currentTextChanged, this, [=]()
          { pchart->updateChart(chart, pollutant->currentText().toStdString());
            updateFileSelector(location, pchart->getLocations(pollutant->currentText().toStdString()));
            pchart->updateCompliance(pfaLabel, locationLabel, complianceBar, pollutant->currentText().toStdString(), 
                              location->currentText().toStdString()); });
  connect(location, &QComboBox::currentTextChanged, this, [=]()
          { pchart->updateCompliance(pfaLabel, locationLabel, complianceBar, pollutant->currentText().toStdString(),
                                     location->currentText().toStdString()); });
  chartView->setChart(chart);
  // Set the layout and widget as the central widget
  popWidget->setLayout(layout);
  setCentralWidget(popWidget);
}

void WaterWindow::createLitter()
{
  setCentralWidget(0);
  QStringList litterList = {tr("Bathing Water Profile : Other Litter (incl. plastics)"),
  tr("Sewage debris"), tr("Tarry residues")};
  QStringList locationList = {"BRIDLINGTON NORTH (08000)", "BRIDLINGTON SOUTH (08100)", "CAYTON BAY (07500)",
  "DANES DYKE - FLAMBOROUGH (07950)", "FILEY (07600)", "FLAMBOROUGH SOUTH LANDING (07900)", "FRAISTHORPE (08300)",
  "HORNSEA (08700)", "REIGHTON (07700)", "ROBIN HOODS BAY (07200)", "RUNSWICK BAY (06900)", "SANDSEND (07000)",
  "SCARBOROUGH NORTH BAY (07300)", "SCARBOROUGH SOUTH BAY (07400)", "WHITBY (07100)", "WILSTHORPE (08200)",
  "WITHERNSEA (08900)", "WHARFE AT WILDERNESS CAR PARK (08904)", "WHARFE AT CROMWHEEL - ILKLEY (08901)",
  "NIDD AT THE LIDO - KNARESBOROUGH (08903)"};

  updateFileSelector(pollutant, litterList);
  updateFileSelector(location, locationList);

  
  QBarSeries *litterSeries = new QBarSeries();
  QBarSet *set1 = new QBarSet(tr("Bathing Water Profile : Other Litter (incl. plastics)"));
  double set1List[] = {0.2, 0.625, 0, 0.26, 0.15, 0, 0.86, 0.16, 0.11, 0.17, 0.15, 0.5, 0.2, 0.37, 0.25, 0.48, 0.5, 1.73, 0.71, 0.65};
  for (int i = 0; i < 20; i++){
    set1->append(set1List[i]);
  }

  QBarSet *set2 = new QBarSet(tr("Sewage debris"));
  double set2List[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.05, 0, 0, 0, 0, 0};
  for (int i = 0; i < 20; i++){
    set2->append(set2List[i]);
  }

  QBarSet *set3 = new QBarSet(tr("Tarry residues"));
  double set3List[] = {0.14, 0.74, 0, 0, 0, 0.053, 0.4, 0.32, 0, 0, 0, 0.045, 0, 0, 0, 0.71, 0.053, 0, 0, 0};
  for (int i = 0; i < 20; i++){
    set3->append(set3List[i]);
  }

  litterSeries->append(set1);
  litterSeries->append(set2);
  litterSeries->append(set3);

  QChart *litterChart = new QChart;
  formatChart(litterChart);
  litterChart->addSeries(litterSeries);
  litterChart->setTitle(tr("Average presence of litters in various locations"));
  litterChart->setAnimationOptions(QChart::SeriesAnimations);

  QStringList locationName;
  for (int i = 0; i < 20; i++){
    locationName.append(locationList);
  }

  QLineSeries *redLine = new QLineSeries();
  redLine->append(0, 1.0);
  redLine->append(20, 1.0);
  QPen redPen(Qt::red);
  redPen.setWidth(3);
  redLine->setPen(redPen);
  litterChart->addSeries(redLine);
  
  QLineSeries *yellowLine = new QLineSeries();
  yellowLine->append(0, 0.5);
  yellowLine->append(20, 0.5);
  QPen yellowPen(Qt::yellow);
  yellowPen.setWidth(3);
  yellowLine->setPen(yellowPen);
  litterChart->addSeries(yellowLine);

  QLineSeries *greenLine = new QLineSeries();
  greenLine->append(0, 0.25);
  greenLine->append(20, 0.25);
  QPen greenPen(Qt::green);
  greenPen.setWidth(3);
  greenLine->setPen(greenPen);
  litterChart->addSeries(greenLine);

  QBarCategoryAxis *axisX = new QBarCategoryAxis();
  axisX->append(locationName);
  axisX->setTitleText(tr("Locations"));
  litterChart->addAxis(axisX, Qt::AlignBottom);
  litterSeries->attachAxis(axisX);

  QValueAxis *axisY = new QValueAxis();
  axisY->setRange(0, 2);
  axisY->setTitleText("garber c");
  litterChart->addAxis(axisY, Qt::AlignLeft);
  litterSeries->attachAxis(axisY);

  litterChart->legend()->setVisible(true);
  litterChart->legend()->setAlignment(Qt::AlignBottom);
  litterChart->legend()->markers(redLine)[0]->setLabel(tr("1.0 (Exceeding safe levels)"));
  litterChart->legend()->markers(yellowLine)[0]->setLabel(tr("0.5 (Levels for concern)"));
  litterChart->legend()->markers(greenLine)[0]->setLabel(tr("0.25 (Safe levels)"));
  litterChart->setVisible(true);

  redLine->attachAxis(axisX);
  redLine->attachAxis(axisY);

  yellowLine->attachAxis(axisX);
  yellowLine->attachAxis(axisY);
  
  greenLine->attachAxis(axisX);
  greenLine->attachAxis(axisY);
  
  
  litterSeries->setName(tr("Types of litter"));
  
  QChartView *litterChartView = new QChartView(litterChart);
  litterChartView->setRenderHint(QPainter::Antialiasing);
  litterChartView->setVisible(true);

  QVBoxLayout *litterLayout = new QVBoxLayout();
  litterLayout->addWidget(litterChartView);
  litter = new QWidget();
  litter->setLayout(litterLayout);
  setCentralWidget(litter);
}

void WaterWindow::createFlourinated()
{
  setCentralWidget(0);
  //  Create a container widget for this page
  QWidget *flourinatedWidget = new QWidget();
  QVBoxLayout *layout = new QVBoxLayout();

  QLabel *pfaLabel = new QLabel(tr("label"));
  QLabel *locationLabel = new QLabel(tr("location"));
  QFrame *complianceBar = new QFrame();

  complianceBar->setFrameShape(QFrame::HLine);
  complianceBar->setFixedHeight(10);

  layout->addWidget(pfaLabel);
  layout->addWidget(locationLabel);
  layout->addWidget(complianceBar);

  FlourineChart *fchart = new FlourineChart();
  if (model.hasData())
  {
    fchart->loadDataset(model.getData());
  }

  // Create file selectors specific to this window

  updateFileSelector(pollutant, fchart->getDeterminands());
  updateFileSelector(location, fchart->getLocations(pollutant->currentText().toStdString()));

  // Create a chart and chart view
  fchart->loadDataset(model.getData());
  QChart *chart = new QChart();
  fchart->initChart(chart);
  formatChart(chart);
  std::cout << "chart created" << std::endl;
  QChartView *chartView = new QChartView(chart);
  layout->addWidget(chartView);

  // Connect selectors to a slot for updating the chart
  connect(pollutant, &QComboBox::currentTextChanged, this, [=]()
          { fchart->updateChart(chart, pollutant->currentText().toStdString());
            updateFileSelector(location, fchart->getLocations(pollutant->currentText().toStdString()));
            fchart->updateCompliance(pfaLabel, locationLabel, complianceBar, pollutant->currentText().toStdString(), 
                              location->currentText().toStdString()); });
  connect(location, &QComboBox::currentTextChanged, this, [=]()
          { fchart->updateCompliance(pfaLabel, locationLabel, complianceBar, pollutant->currentText().toStdString(),
                                     location->currentText().toStdString()); });
  chartView->setChart(chart);
  // Set the layout and widget as the central widget
  flourinatedWidget->setLayout(layout);
  setCentralWidget(flourinatedWidget);
  
}


void WaterWindow::formatChart(QChart *chart) 
{
  chart->setBackgroundBrush(QBrush(QColor("#e0f7fa")));
  chart->setTitleBrush(QBrush(QColor("#00796b")));
  chart->setPlotAreaBackgroundBrush(QBrush(QColor("#fefefe")));
  chart->setPlotAreaBackgroundVisible(true);
}

void WaterWindow::createPageBar()
{
  QToolBar *pageBar = new QToolBar();
  pageBar->addWidget(dashboardButton);
  pageBar->addSeparator();
  pageBar->addWidget(overviewButton);
  pageBar->addWidget(popsButton);
  pageBar->addWidget(litterButton);
  pageBar->addWidget(flourinatedButton);
  QComboBox *languageSelector = new QComboBox();
  languageSelector->addItems({tr("English"), tr("French"), tr("Spanish"), tr("German")});
  pageBar->addSeparator();
  pageBar->addWidget(languageSelector);

  addToolBar(Qt::TopToolBarArea, pageBar);
}

// change this
void WaterWindow::createFileSelectors()
{
  QStringList pollutantOptions;
  pollutantOptions << tr("pollutants");
  pollutant = new QComboBox();
  pollutant->addItems(pollutantOptions);

  QStringList locationOptions;
  locationOptions << tr("locations");
  location = new QComboBox();
  location->addItems(locationOptions);
}

void WaterWindow::updateFileSelector(QComboBox *selector, QStringList options)
{
  selector->clear();
  selector->addItems(options);
}

void WaterWindow::createButtons()
{
  loadButton = new QPushButton(tr("Load"));
  statsButton = new QPushButton(tr("Stats"));
  dashboardButton = new QPushButton(tr("Dashboard"));
  overviewButton = new QPushButton(tr("Overview"));
  popsButton = new QPushButton(tr("POPs"));
  litterButton = new QPushButton(tr("Litter Indicators"));
  flourinatedButton = new QPushButton(tr("Flourinated compounds"));

  connect(loadButton, SIGNAL(clicked()), this, SLOT(openCSV()));
  connect(statsButton, SIGNAL(clicked()), this, SLOT(displayStats()));
  connect(dashboardButton, SIGNAL(clicked()), this, SLOT(createDashboard()));
  connect(overviewButton, SIGNAL(clicked()), this, SLOT(createOverview()));
  connect(popsButton, SIGNAL(clicked()), this, SLOT(createPOPs()));
  connect(litterButton, SIGNAL(clicked()), this, SLOT(createLitter()));
  connect(flourinatedButton, SIGNAL(clicked()), this, SLOT(createFlourinated()));
}

void WaterWindow::createToolBar()
{
  QToolBar *toolBar = new QToolBar();

  QLabel *pollutantLabel = new QLabel(tr("Pollutant"));
  pollutantLabel->setAlignment(Qt::AlignVCenter);
  toolBar->addWidget(pollutantLabel);
  toolBar->addWidget(pollutant);

  QLabel *locationLabel = new QLabel(tr("Location"));
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
  fileInfo = new QLabel(tr("Current file: <none>"));
  QStatusBar *status = statusBar();
  status->addWidget(fileInfo);
}

void WaterWindow::addFileMenu()
{
  QAction *locAction = new QAction(tr("Set Data &Location"), this);
  locAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
  connect(locAction, SIGNAL(triggered()), this, SLOT(setDataLocation()));

  QAction *closeAction = new QAction(tr("Quit"), this);
  closeAction->setShortcut(QKeySequence::Close);
  connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

  QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(locAction);
  fileMenu->addAction(closeAction);
}

void WaterWindow::addHelpMenu()
{
  QAction *aboutAction = new QAction(tr("&About"), this);
  connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

  QAction *aboutQtAction = new QAction(tr("About &Qt"), this);
  connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
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
  createTableAndModel();
  showDataLoadedQuestion();
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
    QMessageBox::critical(this, tr("CSV File Error"), error.what());
    return;
  }

  fileInfo->setText(QString(tr("Current file: <kbd>%1</kbd>")).arg(filename));
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

void WaterWindow::createHelpButton()
{
  QMessageBox *helpMessage = new QMessageBox();
  helpMessage->setWindowTitle(tr("Help & User Guide"));
  QString hMessage = "<p>Follow this link for general help as well as a user guide for the application.</p>"
                    "<p>-> <a href='https://www.google.com'>Help & User Guide</a></p>";
  helpMessage->setText(hMessage);
  helpMessage->setTextFormat(Qt::RichText);
  helpMessage->setTextInteractionFlags(Qt::TextBrowserInteraction);
  helpMessage->exec();
  
}

void WaterWindow::createCreditsButton()
{
  QMessageBox *creditMessage = new QMessageBox();
  creditMessage->setWindowTitle(tr("Credits For Data Sources"));
  QString cMessage = "<p>Follow this link to download the source of the data used in the application.<p>"
                    "<p>-> <a href='https://statics.teams.cdn.office.net/evergreen-assets/safelinks/1/atp-safelinks.html'>Water Dataset</a></p>"
                    "<p>Follow this link to see more information about the Water Dataset.</p>"
                    "<p>-> <a href='https://environment.data.gov.uk/water-quality/view/doc/reference'>More Information</a></p>";
  creditMessage->setText(cMessage);
  creditMessage->setTextFormat(Qt::RichText);
  creditMessage->setTextInteractionFlags(Qt::TextBrowserInteraction);
  creditMessage->exec();
  
}

