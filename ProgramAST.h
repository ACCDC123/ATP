#ifndef PROGRAMAST_H
#define PROGRAMAST_H


#include "ImportBlockAST.h"
#include "VectorBlockAST.h"

class ProgramAST  {
public:
ProgramAST();
ImportBlockAST import_block;
VectorBlockAST vector_block;
};

#endif