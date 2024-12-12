#include "overviewPage.hpp"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>

QPushButton* OverviewPage::createInfoButton()
{
    // Create the info button
    QPushButton* infoButton = new QPushButton(tr("Overview Info"), mainWindow);

    // Connect the button to the show info slot
    connect(infoButton, SIGNAL(clicked()), this, SLOT(showOverviewPageExplanation()));

    return infoButton;
}

void OverviewPage::showOverviewPageExplanation()
{
    std::vector<std::string> pullutantNames = model->getData().getLabels();

    std::string print_info = "Overview Page Usage\n"
                             "Here you can find the overview of water data, including pollutants, "
                             "compliance, and trends. Use the controls to filter and analyze the data. "
                             "Search with the search bar to find any pollutant and get more info on it.";
    int index = 0;

    // Show the message box
    QMessageBox::information(
        mainWindow,
        tr("Overview Information"),
        QString::fromStdString(print_info)
    );
}


// Function to convert date string to tm struct
std::tm OverviewPage::TMstringToDate(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return tm;
}
QDate OverviewPage::stringToDate(const std::string& dateStr) {
    // Use QDate's fromString function to convert a date string to QDate
    return QDate::fromString(QString::fromStdString(dateStr), "yyyy-MM-dd");
}

// Comparison function for sorting by date
bool OverviewPage::compareByDate(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
    std::tm dateA = TMstringToDate(a.first);
    std::tm dateB = TMstringToDate(b.first);
    return std::mktime(&dateA) < std::mktime(&dateB);
}

QLineSeries* OverviewPage::createPollutantChart(const std::vector<std::pair<std::string, double>>& pollutantInfo) {
    // Create a new QLineSeries to hold the data
    QLineSeries* series = new QLineSeries();

    // Add data points to the series
    for (const auto& entry : pollutantInfo) {
        QDate date = stringToDate(entry.first);
        series->append(date.toJulianDay(), entry.second);  // Use Julian Day for X-axis
    }

    return series;
}
void OverviewPage::searchBarReturnPressed()
{
    centerLayout->removeWidget(chartView);

    QString searchTerm = searchBar->text().trimmed();
    if (searchTerm.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Search term cannot be empty.");
        centerLayout->addWidget(chartView);
        return;
    }
    // Check if searchTerm exists in possiblePollutantNames
    std::vector<std::string> possiblePollutantNames = model->getData().getLabels();
    if (std::find(possiblePollutantNames.begin(), possiblePollutantNames.end(), searchTerm.toStdString()) == possiblePollutantNames.end()) {
        QMessageBox::warning(this, "Warning",
                        QString("Search a pollutant name under the given data.\n'%1' isn't a correct name.")
                        .arg(QString::fromStdString(searchTerm.toStdString())));

        centerLayout->addWidget(chartView);
        return;
    }
    std::cout << "Search term: " << searchTerm.toStdString() << std::endl;


     chartView = createPollutantTabel(searchTerm.toStdString());
     centerLayout->addWidget(chartView);

}

void OverviewPage::createSearchBar(QVBoxLayout* layout)
{
    searchBar = new QLineEdit();
    searchBar->setPlaceholderText(tr("Find pollutant..."));
    layout->addWidget(searchBar);

    // Connect the returnPressed signal to the slot
    connect(searchBar, SIGNAL(returnPressed()), this, SLOT(searchBarReturnPressed()));
}

QChartView* OverviewPage::createPollutantTabel(std::string pollutant)
{
    std::vector<std::pair<std::string, double>> pollutantInfo;
        auto pollutants = model->getData().getPollutants(pollutant);

        // Add each pair in pollutants to pollutantInfo
        for (const auto& pollutant : pollutants) {
            pollutantInfo.push_back(pollutant);
        }

    std::sort(pollutantInfo.begin(), pollutantInfo.end(), compareByDate);

    QLineSeries* line =createPollutantChart(pollutantInfo);


    QLineSeries* series = createPollutantChart(pollutantInfo);
    // Create a QChart object and add the series to it
    QChart* chart = new QChart();
    chart->setBackgroundBrush(QBrush(QColor("#e0f7fa")));
    chart->setTitleBrush(QBrush(QColor("#00796b")));
    chart->setPlotAreaBackgroundBrush(QBrush(QColor("#fefefe")));
    chart->setPlotAreaBackgroundVisible(true);
    chart->addSeries(series);
    chart->setTitle("Pollutant Levels Over Time");

    // Configure the X-axis (Time)
    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Time");

    // Configure the Y-axis (µg/L)
    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("µg/L");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Create a QChartView to display the chart
    QChartView* curChartView = new QChartView(chart);
    curChartView->setRenderHint(QPainter::Antialiasing);
    return curChartView;
}

QWidget* OverviewPage::createOverviewPage()
{
    centerLayout = new QVBoxLayout();

    // Create a layout for the info button
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* infoButton = createInfoButton();
    buttonLayout->addWidget(infoButton, 0, Qt::AlignLeft);
    centerLayout->addLayout(buttonLayout);

    // Search bar at the top
    createSearchBar(centerLayout);

    // Default pollutant
    std::string defaultPollutant = "Chloroform";
    chartView = createPollutantTabel(defaultPollutant);
    centerLayout->addWidget(chartView);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(centerLayout);
    return centralWidget;
}