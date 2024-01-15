#include "ImportBlockAST.h"
#include "LoggerManager.h"

#include <iostream>

ImportBlockAST::ImportBlockAST() : tset(std::make_shared<std::vector<std::string>>()) {}

void ImportBlockAST::push_tset(const std::string import)
{
  tset->push_back(import);
}

void ImportBlockAST::read_tset() const
{
  auto logger = LoggerManager::getLogger();
  std::string time;
  for (auto val : *tset)
  {
    time = time + val + " ";
  }
  logger->debug("There are the tset for the ATP file:"+time);
}