#include <iostream>
#include <fstream>
#include <vector>

void readFileInto(std::string fname, std::vector<int>& lines);
int getProdSum2020(std::vector<int> lines);

int main()
{
  std::vector<int> lines;
  readFileInto("input.txt", lines);
  int product = getProdSum2020(lines);
  std::cout << "Answer: " << product << std::endl;
}

void readFileInto(std::string fname, std::vector<int>& lines)
{
  std::ifstream file(fname);
  int n;
  while(file >> n)
    lines.push_back(n);
}

int getProdSum2020(std::vector<int> lines)
{
  std::cout<<lines.size()<<std::endl;
  int len = lines.size(), i, j, k;

  for(i = 0; i < len; ++i)
  {
    // std::cout<<i<<std::endl;
    for(j = i; j < len; ++j)
    {
      // std::cout<<j<<std::endl;
      for(k = i; k < len; ++k)
      {
        // std::cout<<i<<" "<<j<<" "<<k<<std::endl;
        if(lines.at(i) + lines.at(j) + lines.at(k) == 2020)
          return lines.at(i) * lines.at(j) * lines.at(k);
      }
    }
  }
  return -255;
}
