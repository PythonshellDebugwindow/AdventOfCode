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
  // int cnt = 0, i, len = lines.size();
  std::cout << numValid(passports) << std::endl;
}

void readFileInto(std::string fname, std::vector<Passport>& passports)
{
  std::ifstream file(fname);
  std::string line, curField;
  bool isEnteringField;
  Passport curPassport({});
  int i, len;
  
  while(std::getline(file, line))
  {
    if(line.length() == 0)
    {
      passports.push_back(curPassport);
      curPassport = Passport({});
    }
    else
    {
      isEnteringField = true;
      len = line.length();
      for(i = 0; i < len; ++i)
      {
        if(line.at(i) == ' ')
        {
          isEnteringField = true;
        }
        else if(line.at(i) == ':')
        {
          isEnteringField = false;
          curPassport.AddField(curField);
          // std::cout<<i<<"\t"<<curField<<"\t\t"<<line<<std::endl;
          curField = "";
        }
        else if(isEnteringField)
          curField += line.at(i);
      }
    }
  }
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
