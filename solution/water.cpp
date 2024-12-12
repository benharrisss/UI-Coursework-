#include <stdexcept>
#include <sstream>
#include "water.hpp"

using namespace std;

Water::Water(const std::string &id, float result, std::string resultQualifier, std::string resultInterpretation,
             Sample sample, Determinand determinand)
    : id(id), result(result), resultQualifier(resultQualifier), resultInterpretation(resultInterpretation),
      sample(sample), determinand(determinand)
{
  ostringstream error;
}