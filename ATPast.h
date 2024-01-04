

#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
class ImportBlockAST;
class TsetAST;
class VectorBlockAST;
class PinListAST;
class DriveVectorAST;
class OperationAST;
class ATPAST;

class ATPAST
{
public:
  ATPAST() = default;
  virtual ~ATPAST() = default;
};
class TsetAST : public ATPAST
{
public:
  unique_ptr<string> Tset;
};
class ImportBlockAST : public ATPAST
{
public: /// ImportAST - AST ok_
  unique_ptr<TsetAST> Tset = nullptr;
};

class PinListAST : public ATPAST
{
public:
  unique_ptr<vector<string>> PinList;
};
class DriveVectorAST : public ATPAST
{
public:
  unique_ptr<vector<vector<string>>> Vector;
};

class VectorBlockAST : public ATPAST
{
public:
  unique_ptr<PinListAST> PinList = nullptr;
  unique_ptr<vector<DriveVectorAST>> DriveVector = nullptr;
};

class OperationAST : public ATPAST
{
public:
  unique_ptr<string> Operaton;
};

/// VectorDeclarationAST - AST class for vector declarations
