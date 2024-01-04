#ifndef VECTORBLOCKAST_H
#define VECTORBLOCKAST_H

#include "ATPast.h"
#include "PinListAST.h"
#include "DriveVectorAST.h"

class VectorBlockAST {
public:
VectorBlockAST();


PinListAST pin_list_node;
DriveVectorAST drive_vector_node;
};

#endif