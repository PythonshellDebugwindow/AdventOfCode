#ifndef _PASSPORT_H
#define _PASSPORT_H

#include <vector>
#include <string>

class Passport
{
  std::vector<std::string> fields;
  
  public:
    Passport(std::vector<std::string> fields);
    ~Passport();
    
    void AddField(std::string field);
    
    bool IsValid();
};

#endif //_PASSPORT_H
