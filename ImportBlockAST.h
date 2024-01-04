

#ifndef IMPORTBLOCKAST_H
#define IMPORTBLOCKAST_H

#include <memory>
#include <vector>
#include <string>

class ImportBlockAST 
{
public:
ImportBlockAST();
  void push_tset(std::string import);
  void read_tset();


  std::shared_ptr<std::vector<std::string>> tset;
};

#endif





