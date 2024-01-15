
#include "LoggerManager.h"
#include "ProgramAST.h"
#include "ATPParser.hpp"
extern int yyparse();
std::shared_ptr<ProgramAST> ATPhead = make_shared<ProgramAST>();
extern void yyparse_init(const char *filename);
extern void yyparse_cleanup();
extern FILE* yyparse_file_ptr;


int main(int argc, char **argv)
{
  auto logger = LoggerManager::getLogger();
  const char *file_name;
  logger->info("Please enter the file name:");
  std::string user_input;
  std::cin >> user_input;
  file_name = user_input.c_str();
  yyparse_init(file_name);
  
  if (!yyparse_file_ptr)
  {
    logger->error("can not open the input file");
  }
  long int last_pos = 0;
  int result;
  while (1)
  {

    result = yyparse();

    if (result != 0)
    {
      last_pos = ftell(yyparse_file_ptr);
      fseek(yyparse_file_ptr, last_pos, SEEK_SET);
      ATPhead.reset();
      ATPhead = make_shared<ProgramAST>();
    }
    else
    {
      break;
    }
  }

  yyparse_cleanup();

  return 0;
}
