

#ifndef IMPORTBLOCKAST_H
#define IMPORTBLOCKAST_H

#include "ATPast.h"
class ImportBlockAST 
{
public:
ImportBlockAST();
  void push_tset(const std::string import);
  void read_tset()const;


  std::shared_ptr<std::vector<std::string>> tset;
};

#endif






