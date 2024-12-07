// COMP2811 Coursework 1 sample solution: QuakeDataset class
// fred
#pragma once

#include <vector>
#include "water.hpp"

class WaterDataset
{
public:
  WaterDataset() {}
  WaterDataset(const std::string &filename) { loadData(filename); }
  void loadData(const std::string &);
  int size() const { return data.size(); }
  Water operator[](int index) const { return data.at(index); }

  std::vector<std::pair<std::string, double>> getPollutants(const std::string& pollutantName, const std::string& location);
  std::vector<std::string> getLocations(const std::string& pollutantName);

  std::vector<std::string> getLabels();

  std::vector<Water> getData();
  std::vector<Water> getPOPs();
  /*
  Quake strongest() const;
  Quake shallowest() const;
  double meanDepth() const;
  double meanMagnitude() const;
  */

private:
  std::vector<Water> data;
  std::vector<std::string> pollutants;
  //std::vector<std::PollutantResults> popResults;
  std::vector<Water> pops;

  std::vector<std::string> labels;

  //Water record;

  void checkDataExists() const;
};
