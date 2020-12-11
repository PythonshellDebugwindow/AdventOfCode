#include "policy.hpp"

Policy::Policy(int min, int max, char c, std::string pwd)
{
  this->min = min;
  this->max = max;
  this->c = c;
  this->pwd = pwd;
}

Policy::~Policy()
{}

bool Policy::IsValid()
{
  bool hasMin = this->pwd.at(this->min - 1) == this->c;
  bool hasMax = this->pwd.at(this->max - 1) == this->c;
  return hasMin ^ hasMax;
}
