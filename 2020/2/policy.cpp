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
  int cnt, i, len = this->pwd.length();
  for(i = 0; i < len; ++i)
    if(this->pwd.at(i) == this->c)
      ++cnt;
  return cnt >= this->min && cnt <= this->max;
}
