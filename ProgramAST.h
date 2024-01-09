#ifndef PROGRAMAST_H
#define PROGRAMAST_H
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "ATPast.h"
#include "ImportBlockAST.h"
#include "VectorBlockAST.h"

class ProgramAST  {
public:
ProgramAST();
ImportBlockAST import_block;
VectorBlockAST vector_block;
};

#endif