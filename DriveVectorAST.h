

#ifndef DRIVEVECTORAST_H
#define DRIVEVECTORAST_H


#include <memory>
#include <vector>
#include <string>
#include "VectorAST.h"

class DriveVectorAST {
public:
DriveVectorAST();
void push_vector_node(const VectorAST);


void read_vector_list()const;
void read_operation_list()const;
void read_vector_line_list()const;


std::shared_ptr<std::vector<VectorAST>> vector_list;
};

#endif
