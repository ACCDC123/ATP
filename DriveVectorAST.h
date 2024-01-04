

#ifndef DRIVEVECTORAST_H
#define DRIVEVECTORAST_H

#include "ATPast.h"
#include <memory>
#include <vector>
#include <string>

class DriveVectorAST {
public:
DriveVectorAST();
void push_vector(std::vector<std::string>);
void push_operation(std::string);
void push_operation_line(int);

void read_vector();
void read_operation();
void read_operation_line();


std::shared_ptr<std::vector<std::string>> operation_list;
std::shared_ptr<std::vector<int>> operation_line;
std::shared_ptr<std::vector<std::vector<std::string>>> vector_list;
};

#endif
