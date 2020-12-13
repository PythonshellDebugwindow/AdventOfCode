#include <iostream>
#include <fstream>
#include <vector>

#include "boardingpass.h"

void readFileInto(std::string fname, std::vector<BoardingPass>& passes);
int maxSeatValue(std::vector<BoardingPass> passes);

int main()
{
  std::vector<BoardingPass> passes;
  readFileInto("input.txt", passes);
  std::cout << maxSeatValue(passes) << std::endl;
}

void readFileInto(std::string fname, std::vector<BoardingPass>& passes)
{
  std::ifstream file(fname);
  std::string line;
  int i, len;
  
  while(std::getline(file, line))
  {
    passes.push_back(BoardingPass(line));
  }
}

int maxSeatValue(std::vector<BoardingPass> passes)
{
  int max = -1, i, len = passes.size();
  for(i = 0; i < len; ++i)
    if(passes.at(i).getSeatID() > max)
      max = passes.at(i).getSeatID();
  return max;
}
