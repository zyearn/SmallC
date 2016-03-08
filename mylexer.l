%{
#include "y.tab.h"
#include "treeNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern YYSTYPE yylval;
%}

delim   [ \t]
ws      {delim}+
letter  [a-zA-Z]
digit   [0-9]
id      [a-zA-Z_][0-9a-zA-Z_]*
integerten  [1-9]{digit}*
integeregt  0[0-7]+
integerstn  (0x|0X)[0-9A-Fa-f]+

%%

read        {yylval.node = new treeNode("READ",0); return READ;}
write       {yylval.node = new treeNode("WRITE",0); return WRITE;}
"\n"        {yylineno++;}
int         {yylval.node = new treeNode("TYPE_INT",0); return TYPE;}
struct      {yylval.node = new treeNode("TYPE_STRUCT",0); return STRUCT;}
return      {yylval.node = new treeNode("return",0);return RETURN;}
if          {yylval.node = new treeNode("if",0); return IF;}
else        {yylval.node = new treeNode("else",0); return ELSE;}
break       {yylval.node = new treeNode("break",0); return BREAK;}
continue    {yylval.node = new treeNode("continue",0); return CONT;}
for         {yylval.node = new treeNode("for",0); return FOR;}
";"         {yylval.node = new treeNode(";",0);return SEMI;}
","         {yylval.node = new treeNode(",",0);return COMMA;}
"("         {yylval.node = new treeNode("(",0);return LP;}
")"         {yylval.node = new treeNode(")",0);return RP;}
"["         {yylval.node = new treeNode("[",0);return LB;}
"]"         {yylval.node = new treeNode("]",0);return RB;}
"{"         {yylval.node = new treeNode("{",0);return LC;}
"}"         {yylval.node = new treeNode("}",0);return RC;}
"."         {yylval.node = new treeNode(".",0);return DOT;}
"!"         {yylval.node = new treeNode("!",0);return LNOT;}
"++"        {yylval.node = new treeNode("++",0);return PINC;}
"--"        {yylval.node = new treeNode("--",0);return PDEC;}
"~"         {yylval.node = new treeNode("~",0);return BNOT;}
"*"         {yylval.node = new treeNode("*",0);return MUL;}
"/"         {yylval.node = new treeNode("/",0);return DIV;}
"%"         {yylval.node = new treeNode("%",0);return MOD;}
"+"         {yylval.node = new treeNode("+",0);return ADD;}
"-"         {yylval.node = new treeNode("-",0);return MIN;}
"<<"        {yylval.node = new treeNode("<<",0);return SL;}
">>"        {yylval.node = new treeNode(">>",0);return SR;}
">"         {yylval.node = new treeNode(">",0);return GT;}
">="        {yylval.node = new treeNode(">=",0);return GTE;}
"<"         {yylval.node = new treeNode("<",0);return LT;}
"<="        {yylval.node = new treeNode("<=",0);return LTE;}
"=="        {yylval.node = new treeNode("==",0);return EQ;}
"!="        {yylval.node = new treeNode("!=",0);return NEQ;}
"&"         {yylval.node = new treeNode("&",0);return BAND;}
"^"         {yylval.node = new treeNode("^",0);return BXOR;}
"|"         {yylval.node = new treeNode("|",0);return BOR;}
"&&"        {yylval.node = new treeNode("&&",0);return LAND;}
"||"        {yylval.node = new treeNode("||",0);return LOR;}
"="         {yylval.node = new treeNode("=",0);return ASN;}
"+="        {yylval.node = new treeNode("+=",0);return ADDASN;}
"-="        {yylval.node = new treeNode("-=",0);return MINASN;}
"*="        {yylval.node = new treeNode("*=",0);return MULASN;}
"/="        {yylval.node = new treeNode("/=",0);return DIVASN;}
"&="        {yylval.node = new treeNode("&=",0);return BANDASN;}
"^="        {yylval.node = new treeNode("^=",0);return BXORASN;}
"|="        {yylval.node = new treeNode("|=",0);return BORASN;}
"<<="       {yylval.node = new treeNode("<<=",0);return SLASN;}
">>="       {yylval.node = new treeNode(">>=",0);return SRASN;}
{id}        {
                yylval.node = new treeNode(yytext,0);
                return ID;
            }
{integerten}    {yylval.node = new treeNode(yytext,0);return INT;}
{integeregt}    {int sum = 0;   int i = 1;  while(yytext[i] != '\0')
                    {
                        sum = sum*8 + yytext[i] - '0';
                        i++;
                    }
                    char num[256];  sprintf(num,"%d", sum);     yylval.node = new treeNode(num,0);return INT;
                }

{integerstn}    {
                    int sum = 0;
                    int i = 2;
                    while(yytext[i] != '\0')
                    {
                        if(yytext[i] >= 'A'&& yytext[i] <= 'F')
                            sum = sum*16 + yytext[i] - 'A' + 10;
                        else if(yytext[i] >= '0' && yytext[i] <= '9')
                            sum = sum*16 + yytext[i] - '0';
                        i++;
                    }
                    char num[256];
                    sprintf(num,"%d", sum);
                    yylval.node = new treeNode(num,0);return INT;
                }
{ws}        {}


%%

int yywrap()
{
    return 1;
}
