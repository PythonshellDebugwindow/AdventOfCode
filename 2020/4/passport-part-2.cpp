#include "passport.h"
#include "util.h"

Passport::Passport()
{
  this->fields = {};
}

Passport::~Passport()
{}
#include<iostream>//TEMPORARY//
void Passport::AddField(std::string field, std::string fieldVal)
{
  std::cout<<"Adding "<<field<<"\t\t"<<fieldVal<<std::endl;
  this->fields.push_back(field);
  this->fieldVals.push_back(fieldVal);
}

bool Passport::IsValid()
{
  std::cout<<"==="<<std::endl;
  bool byr = false,
       iyr = false,
       eyr = false,
       hgt = false,
       hcl = false,
       ecl = false,
       pid = false;
  std::string f, v;
  int i, len = this->fields.size();
  
  for(i = 0; i < len; ++i)
  {
    std::cout<<"Chk:"<<this->fields.at(i)<<","<<this->fieldVals.at(i)<<";"<<std::endl;
    f = this->fields.at(i);
    v = this->fieldVals.at(i);
    
    if(f == "byr")
    {
      if(parseInteger(v) >= 1920 && parseInteger(v) <= 2002)
        byr = true;
    }
    else if(f == "iyr")
    {
      if(parseInteger(v) >= 2010 && parseInteger(v) <= 2020)
        iyr = true;
    }
    else if(f == "eyr")
    {
      if(parseInteger(v) >= 2020 && parseInteger(v) <= 2030)
        eyr = true;
    }
    else if(f == "hgt")
    {
      int vlm2 = v.length() - 2, rest = parseInteger(v.substr(0, vlm2));
      if(v.substr(vlm2) == "cm" && rest >= 150 && rest <= 193)
        hgt = true;
      else if(v.substr(vlm2) == "in" && rest >= 59 && rest <= 76)
        hgt = true;
    }
    else if(f == "hcl")
      hcl = isValidHexCol(v);
    else if(f == "ecl")
      ecl = isValidEyeCol(v);
    else if(f == "pid")
      pid = v.length() == 9 && parseInteger(v) > -1;
  }
  return byr && iyr && eyr && hgt && hcl && ecl && pid;
}
