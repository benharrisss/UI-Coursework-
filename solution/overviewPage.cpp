#include "overviewPage.hpp"
#include <QMessageBox>
#include <iostream>
#include <string>

QPushButton* OverviewPage::createInfoButton()
{
    // Create the info button
    QPushButton* infoButton = new QPushButton(tr("Overview Info"), mainWindow);

    // Make the button small
    infoButton->setFixedSize(120, 40);  // You can adjust the size as needed

    // Style the button with a noticeable color (e.g., bright blue or green)
    infoButton->setStyleSheet("QPushButton {"
                              "background-color: #4CAF50;"  // Green background
                              "color: white;"               // White text color
                              "border-radius: 5px;"         // Rounded corners
                              "font-size: 14px;"            // Font size
                              "padding: 5px;"               // Padding around the text
                              "}"
                              "QPushButton:hover {"
                              "background-color: #45a049;"  // Darker green on hover
                              "}");

    // Connect the button to the show info slot
    connect(infoButton, SIGNAL(clicked()), this, SLOT(showOverviewPageExplanation()));

    return infoButton;
}

void OverviewPage::showOverviewPageExplanation()
{
    // Show the information pop-up when the button is clicked


    std::vector<std::string> pullutantNames = model->getData().getLabels();
    if(pullutantNames.empty()) {
        std::cout << "Overview of the page" << std::endl;
    }
    for (const auto& name : pullutantNames){
        std::cout << name << std::endl;

    }


    std::string print_info = "Overview Page Usage\n"
                             "Here you can find the overview of water data, including pollutants, "
                             "compliance, and trends. Use the controls to filter and analyze the data. "
                             "Search with the search bar to find any pollutant and get more info on it.\n";
    int index = 0;

    for (const auto& name : pullutantNames) {
        print_info += name + ", ";
        index++;
        if(index >10){
          break;
          }
    }

    // Remove trailing comma and space
    if (!pullutantNames.empty()) {
        print_info.pop_back();
        print_info.pop_back();

    }

    // Show the message box
    QMessageBox::information(
        mainWindow,
        tr("Overview Information"),
        QString::fromStdString(print_info)
    );
}

void OverviewPage::searchBarReturnPressed()
{
    // Logic to be executed when Enter is pressed in the search bar
    QString searchTerm = searchBar->text().trimmed();
    std::cout << "Search term: " << searchTerm.toStdString() << std::endl;

    // Get the pollutant data based on the search term
    std::vector<std::pair<std::string, double>> pollutantInfo = model->getData().getPollutants(searchTerm.toStdString(), mainWindow->curLocation()->currentText().toStdString());
    //todo continue writing this class
    std::cout << "Pollutant Info:" << std::endl;
    for (const auto& entry : pollutantInfo) {
        std::cout << "Pollutant: " << entry.first << ", Value: " << entry.second << std::endl;
    }
}

void OverviewPage::createSearchBar(QVBoxLayout* layout)
{
    searchBar = new QLineEdit();
    searchBar->setPlaceholderText(tr("Find pollutant..."));
    layout->addWidget(searchBar);

    // Connect the returnPressed signal to the slot
    connect(searchBar, SIGNAL(returnPressed()), this, SLOT(searchBarReturnPressed()));
}

QTableWidget* OverviewPage::createPollutantTabel(std::string pollutant)
{
    // Create a table for pollutant data
    QTableWidget* pollutantsTable = new QTableWidget();
    pollutantsTable->setRowCount(10);  // Placeholder, set based on actual data
    pollutantsTable->setColumnCount(3); // Columns: Pollutant, Value, Compliance
    pollutantsTable->setHorizontalHeaderLabels({tr("Pollutant"), tr("Value"), tr("Compliance")});
    return pollutantsTable;
}

QLabel* OverviewPage::createChart(std::string defaultPollutant)
{
    QLabel* chartPlaceholder = new QLabel(tr("Pollutant Trend Over Time (Chart Placeholder)"));
    chartPlaceholder->setAlignment(Qt::AlignCenter);
    chartPlaceholder->setStyleSheet("border: 1px solid gray; padding: 10px;");
    return chartPlaceholder;
}

QGroupBox* OverviewPage::createColordData(std::string defaultPollutant)
{
    QGroupBox* dataBox = new QGroupBox(tr("Advanced Data"));
    QVBoxLayout* dataBoxLayout = new QVBoxLayout();
    dataBoxLayout->addWidget(new QLabel(tr("Risks: High")));
    dataBoxLayout->addWidget(new QLabel(tr("Compliance: Within limits")));
    dataBoxLayout->addWidget(new QLabel(tr("Safety thresholds: 50 µg/m³")));
    dataBox->setLayout(dataBoxLayout);
    return dataBox;
}

QWidget* OverviewPage::createOverviewPage()
{
    // Main layout for the overview page
    QVBoxLayout* layout = new QVBoxLayout();

    // Create a layout for the info button
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* infoButton = createInfoButton();  // Create the button
    buttonLayout->addWidget(infoButton, 0, Qt::AlignLeft);  // Align the button to the left
    layout->addLayout(buttonLayout);  // Add button layout to main layout

    // Search bar at the top
    createSearchBar(layout);

    // Center section: table and right panels
    QHBoxLayout* centerLayout = new QHBoxLayout();

    // Default pollutant
    std::string defaultPollutant = "Chloroform";
    centerLayout->addWidget(createPollutantTabel(defaultPollutant));

    // Right-side layout for chart and data
    QVBoxLayout* rightPanelLayout = new QVBoxLayout();

    // Chart placeholder
    rightPanelLayout->addWidget(createChart(defaultPollutant));

    // Advanced data group box
    rightPanelLayout->addWidget(createColordData(defaultPollutant));

    // Add the right panel layout to the center layout
    centerLayout->addLayout(rightPanelLayout);

    // Add the center layout to the main layout
    layout->addLayout(centerLayout);

    // Set the main layout as the central widget
    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    return centralWidget;
}