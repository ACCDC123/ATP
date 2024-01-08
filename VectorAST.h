
#ifndef VECTORAST_H
#define VECTORAST_H

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class VectorAST
{public:

    std::shared_ptr<std::vector<std::string>> atp_vector;
    std::string atp_operation;
    int vector_line;

    VectorAST();
    
    void push_vector(std::vector<std::string>);
    void read_vector();
    void push_operation(std::string);
    void read_operation();
    void push_vector_line(int);
    void read_vector_line();
};
#endif