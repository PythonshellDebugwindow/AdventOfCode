#include "passport.h"

Passport::Passport(std::vector<std::string> fields)
{
  this->fields = fields;
}

Passport::~Passport()
{}

void Passport::AddField(std::string field)
{
  this->fields.push_back(field);
}

bool Passport::IsValid()
{
  bool byr = false,
       iyr = false,
       eyr = false,
       hgt = false,
       hcl = false,
       ecl = false,
       pid = false;
  std::string f;
  int i, len = this->fields.size();
  
  for(i = 0; i < len; ++i)
  {
    f = this->fields.at(i);
    if(f == "byr")
      byr = true;
    else if(f == "iyr")
      iyr = true;
    else if(f == "eyr")
      eyr = true;
    else if(f == "hgt")
      hgt = true;
    else if(f == "hcl")
      hcl = true;
    else if(f == "ecl")
      ecl = true;
    else if(f == "pid")
      pid = true;
  }
  return byr && iyr && eyr && hgt && hcl && ecl && pid;
}
