#ifndef _BOARDINGPASS_H
#define _BOARDINGPASS_H

#include <string>

struct BoardingPass
{
  private:
    int row;
    int col;
  
  public:
    //Evaluate binary space partioning (BSP)
    BoardingPass(std::string bsp)
    {
      int i, rowMin = 0, rowMax = 127, colMin = 0, colMax = 7;
      
      for(i = 0; i < 7; ++i)
      {
        if(bsp.at(i) == 'F')
          rowMax = (rowMax - rowMin) / 2 + rowMin;
        else
          rowMin = (rowMax - rowMin) / 2 + rowMin + 1;
      }
      this->row = rowMin;

      for(; i < 10; ++i)
      {
        if(bsp.at(i) == 'L')
          colMax = (colMax - colMin) / 2 + colMin;
        else
          colMin = (colMax - colMin) / 2 + colMin + 1;
      }
      this->col = colMin;
    }
    
    int getSeatID()
    {
      return this->row * 8 + this->col;
    }
};

#endif //_BOARDINGPASS_H
