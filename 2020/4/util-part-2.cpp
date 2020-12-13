#include "util.h"

int parseInteger(std::string s)
{
  int r = 0, i, len = s.length();
  char c;
  
  for(i = 0; i < len; ++i)
  {
    c = s.at(i);
    if(c >= '0' && c <= '9')
    {
      r *= 10;
      r += c - 48;
    }
    else
      return -1;
  }
  
  return r;
}

bool isValidHexCol(std::string s)
{
  if(s.length() != 7 || s.at(0) != '#')
    return false;
  else
  {
    int i;
    char c;
    for(i = 1; i < 7; ++i)
    {
      c = s.at(i);
      if(!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f'))
        return false;
    }
  }
  return true;
}

bool isValidEyeCol(std::string s)
{
  return s == "amb"
      || s == "blu"
      || s == "brn"
      || s == "gry"
      || s == "grn"
      || s == "hzl"
      || s == "oth";
}
