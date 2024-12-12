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

  std::vector<std::pair<std::string, double>> getPollutants(const std::string &pollutantName, const std::string &location);
  std::vector<std::pair<std::string, double>> getPollutants(const std::string &pollutantName);
  std::vector<std::string> getLocations(const std::string &pollutantName);

  std::vector<std::string> getLabels();

  std::vector<Water> getData();
  std::vector<Water> getPOPs();

private:
  std::vector<Water> data;
  std::vector<std::string> pollutants;
  std::vector<Water> pops;
  std::vector<std::string> labels;
  void checkDataExists() const;
};