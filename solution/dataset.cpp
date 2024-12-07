// COMP2811 Coursework 1 sample solution: QuakeDataset class
// fred
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include "dataset.hpp"
#include "csv.hpp"
#include "water.hpp"

#include <iostream>
#include <string>

using namespace std;

// complete reading the csv into the data set
void WaterDataset::loadData(const string &filename)
{
  csv::CSVReader reader(filename);

  data.clear();
  for (const auto &row : reader)
  {

    SamplingPoint samplingPoint{
        row["sample.samplingPoint.notation"].get<string>(),
        row["sample.samplingPoint.easting"].get<float>(),
        row["sample.samplingPoint.northing"].get<float>(),
        row["sample.samplingPoint.label"].get<string>(),
    };
    Determinand determinand{
        row["determinand.label"].get<string>(),
        row["determinand.definition"].get<string>(),
        row["determinand.notation"].get<string>(),
        row["determinand.unit.label"].get<string>(),
    };

    bool isCompliance = row["sample.isComplianceSample"].get<string>() == "true";
    auto search = std::find(pollutants.begin(), pollutants.end(), determinand.getLabel());
    if (search == pollutants.end())
    {
      pollutants.push_back(determinand.getLabel());
    }
    /*if (isCompliance)
    {
      std::cout << "Compliance" << endl;
    }*/
    Sample sample{
        samplingPoint,
        row["sample.purpose.label"].get<string>(),
        row["sample.sampledMaterialType.label"].get<string>(),
        row["sample.sampleDateTime"].get<string>(),
        isCompliance,
    };

    Water water{
        row["@id"].get<string>(),
        row["result"].get<float>(),
        row["resultQualifier.notation"].get<string>(),
        row["codedResultInterpretation.interpretation"].get<string>(),
        sample,
        determinand,
    };

    //PollutantResults pollutantResults{

    //}

    data.push_back(water);
  }
}

vector<pair<string, double>> WaterDataset::getPollutants(const string& pollutantName, const string& location) {
  vector<pair<string, double>> pollutantInfo;
  for (auto i : data) {
    if (i.getDeterminand().getLabel() == pollutantName &&
    i.getSample().getSamplingPoint().getLabel() == location) {
      string date = i.getSample().getDateTime().substr(0, 10);
      double value = i.getResult();
      pollutantInfo.push_back({date, value});
    }
  }
  return pollutantInfo;
}

vector<string> WaterDataset::getLocations(const string& pollutantName) {
  vector<string> locations;
  for (auto i : data) {
    if (i.getDeterminand().getLabel() == pollutantName) {
      locations.push_back(i.getSample().getSamplingPoint().getLabel());
    }
  }
  return locations;
}

vector<string> WaterDataset::getLabels()
{
  vector<string> labels;
  for (int i = 0; i < data.size(); i++) {
    labels.push_back(data[i].getDeterminand().getLabel());
  }
  return labels;
}

vector<Water> WaterDataset::getData()
{
  checkDataExists();
  return data;
}

vector<Water> WaterDataset::getPOPs()
{
  checkDataExists();

  string popsList[] = {"PCB Con 028", "PCB Con 105", "PCB Con 052", "PCB Con 101",
  "PCB Con 138", "PCB Con 156", "PCB Con 118", "PCB Con 153", "PCB Con 180"};
  bool allFound = false;
  for (int i = 0; i < data.size(); i++) {
   for (string j : popsList) {
      if (data[i].getDeterminand().getLabel() == j) {
        pops.push_back(data[i]);
      }
   }
  }
  return pops;
}
/*
Quake QuakeDataset::strongest() const
{
  checkDataExists();

  auto quake = max_element(data.begin(), data.end(),
    [](Quake a, Quake b) { return a.getMagnitude() < b.getMagnitude(); });

  return *quake;
}


Quake QuakeDataset::shallowest() const
{
  checkDataExists();

  auto quake = min_element(data.begin(), data.end(),
    [](Quake a, Quake b) { return a.getDepth() < b.getDepth(); });

  return *quake;
}


double QuakeDataset::meanDepth() const
{
  checkDataExists();

  auto sum = accumulate(data.begin(), data.end(), 0.0,
    [](double total, Quake q) { return total + q.getDepth(); });

  return sum / data.size();
}


double QuakeDataset::meanMagnitude() const
{
  checkDataExists();

  auto sum = accumulate(data.begin(), data.end(), 0.0,
    [](double total, Quake q) { return total + q.getMagnitude(); });

  return sum / data.size();
}

*/

void WaterDataset::checkDataExists() const
{
  if (size() == 0)
  {
    throw std::runtime_error("Dataset is empty!");
  }
}
