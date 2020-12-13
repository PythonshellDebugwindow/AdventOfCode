#ifndef _PASSPORT_H
#define _PASSPORT_H

#include <vector>
#include <string>

class Passport
{
  std::vector<std::string> fields;
  std::vector<std::string> fieldVals;
  
  public:
    Passport();
    ~Passport();
    
    void AddField(std::string field, std::string fieldVal);
    
    bool IsValid();
};

#endif //_PASSPORT_H
