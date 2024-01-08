

#ifndef DRIVEVECTORAST_H
#define DRIVEVECTORAST_H


#include <memory>
#include <vector>
#include <string>
#include "VectorAST.h"

class DriveVectorAST {
public:
DriveVectorAST();
void push_vector_node(VectorAST);


void read_vector_list();
void read_operation_list();
void read_vector_line_list();


std::shared_ptr<std::vector<VectorAST>> vector_list;
};

#endif
