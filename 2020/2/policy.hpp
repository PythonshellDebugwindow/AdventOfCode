#ifndef _POLICY_H
#define _POLICY_H

#include <string>

class Policy
{
  private:
    int min, max;
    char c;
    std::string pwd;
  
  public:
    Policy(int min, int max, char c, std::string pwd);
    ~Policy();
    
    bool IsValid();
};

#endif //_POLICY_H
