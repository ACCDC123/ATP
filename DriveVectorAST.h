

#ifndef DRIVEVECTORAST_H
#define DRIVEVECTORAST_H

#include "ATPast.h"
#include "VectorAST.h"

class DriveVectorAST {
public:
DriveVectorAST();
void push_vector_node(const VectorAST);


void read_vector_list()const;
void read_operation_list()const;
void read_vector_line()const;



std::shared_ptr<std::vector<VectorAST>> vector_list;
};

#endif
