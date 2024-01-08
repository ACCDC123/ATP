
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
    
    void push_vector(const std::vector<std::string>);
    void read_vector()const;
    void push_operation(const std::string);
    void read_operation()const;
    void push_vector_line(const int);
    void read_vector_line()const;
};
#endif