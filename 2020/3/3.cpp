#include <iostream>
#include <fstream>
#include <vector>

void readFileInto(std::string fname, std::vector<std::string>& lines);
int numTrees(std::vector<std::string>& lines);

int main()
{
  std::vector<std::string> lines;
  readFileInto("input.txt", lines);
  // int cnt = 0, i, len = lines.size();
  std::cout << numTrees(lines) << std::endl;
}

void readFileInto(std::string fname, std::vector<std::string>& lines)
{
  std::ifstream file(fname);
  std::string line;
  
  while(std::getline(file, line))
    lines.push_back(line);
}

int numTrees(std::vector<std::string>& lines)
{
  int cnt = 0, x = 0, y = 0, len = lines.size(), llen = lines.at(0).length();
  while(x < len)
  {
    if(lines.at(x).at(y % llen) == '#')
      ++cnt;
    ++x;
    y += 3;
  }
  return cnt;
}
