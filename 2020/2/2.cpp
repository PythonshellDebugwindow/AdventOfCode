#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

#include "policy.hpp"

void readFileInto(std::string fname, std::vector<Policy>& policies);
int parseInt(std::string s);

int main()
{
  std::vector<Policy> policies;
  readFileInto("input.txt", policies);
  int cnt = 0, i, len = policies.size();
  for(i = 0; i < len; ++i)
    if(policies.at(i).IsValid())
      ++cnt;
  std::cout << cnt << std::endl;
}

void readFileInto(std::string fname, std::vector<Policy>& policies)
{
  std::ifstream file(fname);
  std::regex r("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)");
  std::string line;
  std::smatch sm;
  
  int pmin, pmax;
  char pc;
  std::string ppwd;
  
  while(std::getline(file, line))
  {
    regex_match(line, sm, r);
    
    pmin = parseInt(sm[1]);
    pmax = parseInt(sm[2]);
    pc = ((std::string)sm[3]).at(0);
    ppwd = sm[4];
    
    policies.push_back(Policy(pmin, pmax, pc, ppwd));
  }
}

int parseInt(std::string s)
{
  int i, len = s.length(), n = 0;
  for(i = 0; i < len; ++i)
  {
    n *= 10;
    n += s.at(i) - 48;
  }
  return n;
}
