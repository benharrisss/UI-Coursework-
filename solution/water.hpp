#pragma once

#include <string>
#include <iostream>

class SamplingPoint
{
public:
  SamplingPoint(std::string notation, float easting, float northing, std::string label)
      : notation(notation), easting(easting), northing(northing), label(label) {}

  std::string getNotation() const { return notation; }
  std::string getLabel() const { return label; }
  float getEasting() const { return easting; }
  float getNorthing() const { return northing; }

private:
  std::string notation;
  float easting;
  float northing;
  std::string label;
};

class Determinand
{
public:
  Determinand(std::string label, std::string definition, std::string notation, std::string unit)
      : label(label), definition(definition), notation(notation), unit(unit) {}
  std::string getLabel() const { return label; }
  std::string getDefinition() const { return definition; }
  std::string getNotation() const { return notation; }
  std::string getUnit() const { return unit; }
  friend class Water;

private:
  std::string label;
  std::string definition;
  std::string notation;
  std::string unit;
};

class Sample
{
private:
  SamplingPoint samplingPoint;
  std::string purpose;
  std::string materialType;
  std::string dateTime;
  bool isCompliance;

public:
  // Constructor
  Sample(SamplingPoint samplingPoint, std::string purpose, std::string materialType,
         std::string dateTime, bool isCompliance)
      : samplingPoint(samplingPoint), purpose(purpose), materialType(materialType),
        dateTime(dateTime), isCompliance(isCompliance) {}
  std::string getPurpose() const { return purpose; }
  std::string getMaterialType() const { return materialType; }
  std::string getDateTime() const { return dateTime; }
  bool getIsCompliance() const { return isCompliance; }
  SamplingPoint getSamplingPoint() const { return samplingPoint; }
};

class Water
{
private:
  std::string id;
  float result;
  std::string resultQualifier;
  std::string resultInterpretation;
  Sample sample;
  Determinand determinand;

public:
  Water(const std::string &id, float result, std::string resultQualifier, std::string resultInterpretation,
        Sample sample, Determinand determinand);
  std::string getId() const { return id; }
  float getResult() const { return result; }
  std::string getResultQualifier() const { return resultQualifier; }
  std::string getResultInterpretation() const { return resultInterpretation; }
  Determinand getDeterminand() const { return determinand; }
  Sample getSample() const { return sample; }
};

std::ostream &operator<<(std::ostream &, const Water &);
