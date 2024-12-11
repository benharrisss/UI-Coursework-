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
  /*
  Quake strongest() const;
  Quake shallowest() const;
  double meanDepth() const;
  double meanMagnitude() const;
  */

private:
  std::vector<Water> data;
  std::vector<std::string> pollutants;
  void checkDataExists() const;
};
