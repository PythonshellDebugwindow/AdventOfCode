#include <iostream>
#include <fstream>
#include <vector>

#include "passport.h"

void readFileInto(std::string fname, std::vector<Passport>& passports);
int numValid(std::vector<Passport> passports);

int main()
{
  std::vector<Passport> passports;
  readFileInto("input.txt", passports);
  std::cout << numValid(passports) << std::endl;
}

void readFileInto(std::string fname, std::vector<Passport>& passports)
{
  std::ifstream file(fname);
  std::string line, curField, curFieldVal;
  bool isEnteringField, isFirstLine = true;
  Passport curPassport;
  int i, len;
  
  while(std::getline(file, line))
  {
    if(line.length() == 0)
    {
      passports.push_back(curPassport);
      curPassport = Passport();
      isFirstLine = true;
      std::cout<<"---"<<std::endl;
      curField = "";
      curFieldVal = "";
    }
    else
    {
      isEnteringField = true;
      len = line.length();

      if(i == 0 && !isFirstLine && curField.length() > 0)
      {
        curPassport.AddField(curField, curFieldVal);
        curField = "";
        curFieldVal = "";
      }
      
      for(i = 0; i < len; ++i)
      {
        if(line.at(i) == ' ')// || (i == 0 && !isFirstLine))
        {
          curPassport.AddField(curField, curFieldVal);
          curField = "";
          curFieldVal = "";
          isEnteringField = true;
        }
        else if(line.at(i) == ':')
          isEnteringField = false;
        else if(isEnteringField)
          curField += line.at(i);
        else
          curFieldVal += line.at(i);
      }
    }
    isFirstLine = false;
    
    if(curField.length() > 0)
    {
      curPassport.AddField(curField, curFieldVal);
      curField = "";
      curFieldVal = "";
    }
  }
  if(curField.length() > 0)
    curPassport.AddField(curField, curFieldVal);
  passports.push_back(curPassport);
}

int numValid(std::vector<Passport> passports)
{
  int cnt = 0, i, len = passports.size();
  for(i = 0; i < len; ++i)
    if(passports.at(i).IsValid())
      ++cnt;
  return cnt;
}
