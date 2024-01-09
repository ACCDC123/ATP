%{
	#include "ProgramAST.h"
	#include "VectorAST.h"
	#include <stdio.h>
	#include "ATPParser.hpp"
	#include <cstring>

	extern int yylex();
	void yyerror(const char* s)
	{
		printf("Error: %s\n", s);
	}
	extern std::shared_ptr<ProgramAST> ATPhead;
	auto vectornode = make_shared<std::vector<std::string>>();
	auto vectorast =make_shared<VectorAST>();
	int linenode =0;
	%}
%union
{
	std::string* string;
	int token;
	std::vector<std::string>* atpvector;
}

%token <string>  IMPORT TSET IDENTIFIER H L X VECTOR TIMNG LOOP HALT START STOP DASH DOUBLE INTEGER STRING MATCH REPEAT HYPHEN

%token <token>  L_SQUARE_BRACKET R_SQUARE_BRACKET L_PARENTHESIS R_PARENTHESIS L_BRACE R_BRACE MULTI_LINE_ANNOTATION 
%token <token>  LESS_THAN LESS_EQUAL_THAN GREAT_THAN GREAT_EQUAL_THAN  COLON QUOTATION SEMICOLON COMMA  ANNOTATION





%type <atpvector>   drives vector pinnames

%type <string> pinname 


%defines  
%start ATP
%%

ATP : importblockAST vectorblockAST{

      }
	  |vectorblock R_BRACE;

importblockAST : IMPORT TSET tsets SEMICOLON | ANNOTATION importblockAST | MULTI_LINE_ANNOTATION importblockAST;

tsets : IDENTIFIER
{
    std::string import;
    import = *$1;
    (*ATPhead).import_block.push_tset(import);
}
| tsets COMMA IDENTIFIER
{
    std::string import;
    import = *$3;
    (*ATPhead).import_block.push_tset(import);
};

vectorblockAST : VECTOR plist L_BRACE vectorblock R_BRACE | ANNOTATION vectorblockAST | MULTI_LINE_ANNOTATION vectorblockAST;

plist : L_PARENTHESIS TIMNG COMMA pinnames R_PARENTHESIS
{
    std::string Timing;
    Timing = *$2;
    ATPhead->vector_block.pin_list_node.timing = Timing;
}
| L_PARENTHESIS pinnames R_PARENTHESIS{

  };

pinnames : pinname
{
    std::string pinnode = *$1;
    (*ATPhead).vector_block.pin_list_node.push_pin(pinnode);
}
| pinnames COMMA pinname
{
    std::string pinnode = *$3;
    (*ATPhead).vector_block.pin_list_node.push_pin(pinnode);
};

pinname : STRING
{
    $$ = $1;
}
| IDENTIFIER
{
    $$ = $1;
};

vectorblock : vector SEMICOLON vectorblock{

              } |
              vector SEMICOLON{} | ANNOTATION vectorblock{} | MULTI_LINE_ANNOTATION vectorblock{};

vector : GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
	if(linenode%5==0)
	YYABORT;
}
| START COLON GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| STOP COLON GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| HALT COLON GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| MATCH INTEGER GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1 + *$2);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| REPEAT INTEGER GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1 + *$2);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| LOOP INTEGER GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1 + *$2);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| DASH INTEGER GREAT_THAN drives
{
    linenode++;
    vectorast->push_vector(*vectornode);
    vectornode.reset(new std::vector<std::string>());
    vectorast->push_operation(*$1 + *$2);
    vectorast->push_vector_line(linenode);
    ATPhead->vector_block.drive_vector_node.push_vector_node(*vectorast);
    vectorast.reset(new VectorAST());
}
| vector ANNOTATION{} | vector MULTI_LINE_ANNOTATION{};
;

drives : INTEGER
{

    vectornode->push_back(*$1);
}
| HYPHEN
{
    vectornode->push_back(*$1);
}
| IDENTIFIER
{

    vectornode->push_back(*$1);
}
| H
{

    vectornode->push_back(*$1);
}
| L
{

    vectornode->push_back(*$1);
}
| X
{

    vectornode->push_back(*$1);
}
| drives INTEGER
{

    vectornode->push_back(*$2);
}
| drives HYPHEN
{
    vectornode->push_back(*$2);
}
| drives H
{

    vectornode->push_back(*$2);
}
| drives L
{

    vectornode->push_back(*$2);
}
| drives X
{

    vectornode->push_back(*$2);
}
| drives IDENTIFIER
{

    vectornode->push_back(*$2);
}

;
 %%