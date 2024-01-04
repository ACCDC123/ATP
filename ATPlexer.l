%{
#include <stdio.h>
#include <string>
#include "ATPast.h"
#include "ATPParser.hpp"

#define SAVE_TOKEN yylval.string = new string(yytext)
#define TOKEN(t) ( yylval.token = t)

static FILE* yyparse_file_ptr;
 void yyparse_init(const char* filename)
 {
 	yyparse_file_ptr = fopen(filename, "r");
	yyin = yyparse_file_ptr;
    printf("<");
 }

 void yyparse_cleanup()
 {
 	fclose(yyparse_file_ptr);
 }
%}
%option noyywrap

%%
"["                     puts("L_SQUARE_BRACKET");return TOKEN(L_SQUARE_BRACKET); 
"]"                     puts("R_SQUARE_BRACKET");return TOKEN(R_SQUARE_BRACKET); 

"("                     puts("L_PARENTHESIS");return TOKEN(L_PARENTHESIS); 
")"                     puts("R_PARENTHESIS");return TOKEN(R_PARENTHESIS); 
"{"                     puts("L_BRACE");return TOKEN(L_BRACE); 
"}"                     puts("R_BRACE");return TOKEN(R_BRACE);

"<"                     puts("LESS_THAN");return TOKEN(LESS_THAN);
"<="                    puts("LESS_EQUAL_THAN");return TOKEN(LESS_EQUAL_THAN);
">"                     puts("GREAT_THAN");return TOKEN(GREAT_THAN);
">="                    puts("GREAT_EQUAL_THAN");return TOKEN(GREAT_EQUAL_THAN);

","                     puts("COMMA");return TOKEN(COMMA);
":"                     puts("COLON");return TOKEN(COLON);
";"                     puts("SEMICOLON");return TOKEN(SEMICOLON);
"'"                     puts("QUOTATION");return TOKEN(QUOTATION);

"-"                     SAVE_TOKEN;puts("HYPHEN");return HYPHEN;

"#".*                   ;
[ \t\r\n]				;
"import"                puts("IMPORT"); return IMPORT;
"tset"                  puts("TSET"); return TSET;
"H"                     SAVE_TOKEN;puts("H");return H;
"L"                     SAVE_TOKEN;puts("L");return L;
"X"                     SAVE_TOKEN;puts("X");return X;
"vector"                puts("VECTOR"); return VECTOR;
"$tset"                 SAVE_TOKEN; puts("TIMNG"); return TIMNG;  
"loop"                  SAVE_TOKEN; puts("LOOP"); return LOOP; 
"halt"                  SAVE_TOKEN; puts("HALT"); return HALT; 
"START"                 SAVE_TOKEN; puts("START"); return START;
"STOP"                  SAVE_TOKEN; puts("STOP"); return STOP; 
"dash"                 SAVE_TOKEN; puts("DASH"); return DASH;
"match"                 SAVE_TOKEN;puts("MATCH");return MATCH;
"repeat"                SAVE_TOKEN;puts("REPEAT");return REPEAT;       

[a-zA-Z_][a-zA-Z0-9_]*	SAVE_TOKEN; puts(yytext); return IDENTIFIER;
[0-9]+\.[0-9]*			SAVE_TOKEN; puts(yytext); return DOUBLE;
[0-9]+  				SAVE_TOKEN; puts(yytext); return INTEGER;
\"[^"]*\"               SAVE_TOKEN; puts(yytext); return STRING;

"//"[^\n]*\n                                           puts("ANNOTATION");return ANNOTATION;  // 识别单行注释
"/*"([^*]|\*+[^/*])*"*/"                               puts("MULTI_LINE_ANNOTATION");return MULTI_LINE_ANNOTATION; // 识别多行注释


.						printf("Unknown token:%s\n", yytext); yyterminate();



%%