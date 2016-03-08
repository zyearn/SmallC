%{
#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"
class treeNode;
#include <fstream>
#include <string.h>
#include <ctype.h>
#include "Global.h"
#include "codegen.h"
int yylex(void);
int yyerror(char* s);
extern FILE* yyin;
extern FILE* yyout;
void Tranverse(treeNode *, int);
%}

%union
{
	treeNode* node;
}

%nonassoc IFX
%nonassoc ELSE
%right <node> ASN ADDASN MINASN MULASN DIVASN BANDASN BXORASN BORASN SLASN SRASN
%left <node> LOR
%left <node> LAND
%left <node> BOR
%left <node> BXOR
%left <node> BAND
%left <node> EQ NEQ
%left <node> GT GTE LT LTE
%left <node> SL SR
%left <node> ADD MIN
%left <node> MUL DIV MOD
%right <node> LNOT PINC PDEC BNOT
%left <node> DOT
%start PROGRAM

%type <node> PROGRAM 

%type <node> EXTDEFS EXTDEF EXTVARS SPEC STSPEC OPTTAG VAR	FUNC PARAS PARA
%type <node> STMTBLOCK STMTS STMT DEFS DEF DECS DEC INIT EXP ARGS ARRS


%token <node> INT ID SEMI COMMA TYPE LP RP LB RB LC RC STRUCT READ WRITE
%token <node> RETURN IF ELSE BREAK CONT FOR


%%

PROGRAM	:EXTDEFS
		{
			treeNode* tmp = new treeNode("PROGRAM",1,1);
			tmp->child[0] = $1;
			$$ = tmp;
			//Tranverse(tmp,0);
		//	printf("ready to genProgram\n");
			if(FT["_G"] == NULL)
			{
				FT["_G"] = new map<string, int>();
			}
			freopen(outputFile.c_str(), "w", stdout);
			genProgram(tmp);
			tmp->Clear(tmp);
		}
		;

EXTDEFS	:EXTDEF EXTDEFS
		{
			treeNode *tmp = new treeNode("EXTDEFS",2,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|{$$ = new treeNode("EXTDEFS",0,2);}
		;

EXTDEF	:SPEC EXTVARS SEMI
		{
			treeNode *tmp = new treeNode("EXTDEF",3,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		//	printf("ready to genGT\n");
			genGT(tmp);
		}
		|SPEC FUNC STMTBLOCK
		{
			treeNode *tmp = new treeNode("EXTDEF",3,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		//	printf("ready to genFT\n");
			genFT(tmp);
		}
		;

EXTVARS	:DEC
		{
			treeNode *tmp = new treeNode($1->data,1,1);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|DEC COMMA EXTVARS
		{
			treeNode *tmp = new treeNode($1->data+","+$3->data,3,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|{$$ = new treeNode("",0,3);}
		;

SPEC	:TYPE
		{
			treeNode *tmp = new treeNode("",1,1);	//·µ»Ø¿Õ
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|STSPEC
		{
			treeNode *tmp = new treeNode($1->data,1,2);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		;

STSPEC	:STRUCT OPTTAG LC DEFS RC
		{
			treeNode *tmp = new treeNode("|"+$4->data+"|",5,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			tmp->child[4] = $5;
			$$ = tmp;
		}
		|STRUCT ID
		{
			treeNode *tmp = new treeNode("STSPEC",2,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		;

OPTTAG	:ID
		{
			treeNode* tmp = new treeNode($1->data,1,1);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|{$$ = new treeNode("",0,2);}
		;

VAR		:ID
		{
			treeNode* tmp = new treeNode($1->data,1,1);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|VAR LB INT RB
		{
			treeNode *tmp = new treeNode($1->data+"["+$3->data+"]",4,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			$$ = tmp;
		}
		;
		
FUNC	:ID LP PARAS RP
		{
			treeNode *tmp = new treeNode("FUNC",4,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			$$ = tmp;
		}
		;

PARAS	:PARA COMMA PARAS
		{
			treeNode *tmp = new treeNode($1->data+","+$3->data,3,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|PARA
		{
			treeNode *tmp = new treeNode($1->data,1,2);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|{$$ = new treeNode("",0,3);}

		;

PARA	:SPEC VAR
		{
			treeNode *tmp = new treeNode($2->data,2,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		;

STMTBLOCK:LC DEFS STMTS RC
		{
			treeNode *tmp = new treeNode("STMTBLOCK",4,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			$$ = tmp;
		}
		;

STMTS	:STMT STMTS
		{
			treeNode *tmp = new treeNode("STMTS",2,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|{$$ = new treeNode("STMTS",0,2);}
		;

STMT	:EXP SEMI
		{
			treeNode *tmp = new treeNode("STMT",2,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|STMTBLOCK
		{
			treeNode* tmp = new treeNode("STMT",1,2);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|RETURN EXP SEMI
		{
			treeNode *tmp = new treeNode("STMT",3,3);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|IF LP EXP RP STMT %prec IFX
		{
			treeNode *tmp = new treeNode("STMT",5,4);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			tmp->child[4] = $5;
			$$ = tmp;
		}
		|IF LP EXP RP STMT ELSE STMT
		{
			treeNode *tmp = new treeNode("STMT",7,5);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			tmp->child[4] = $5;
			tmp->child[5] = $6;
			tmp->child[6] = $7;
			$$ = tmp;
		}
		|FOR LP EXP SEMI EXP SEMI EXP RP STMT
		{
			treeNode *tmp = new treeNode("STMT",9,6);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			tmp->child[4] = $5;
			tmp->child[5] = $6;
			tmp->child[6] = $7;
			tmp->child[7] = $8;
			tmp->child[8] = $9;
			$$ = tmp;
		}
		|CONT SEMI
		{
			treeNode *tmp = new treeNode("STMT",2,7);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|BREAK SEMI
		{
			treeNode *tmp = new treeNode("STMT",2,8);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|READ LP EXP RP SEMI
		{
			treeNode *tmp = new treeNode("STMT",5,9);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			tmp->child[4] = $5;
			$$ = tmp;
		}
		|WRITE LP EXP RP SEMI
		{
			treeNode *tmp = new treeNode("STMT",5,10);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			tmp->child[4] = $5;
			$$ = tmp;
		}
		;

DEFS	:DEF DEFS
		{
			treeNode *tmp = new treeNode($1->data+","+$2->data,2,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|{$$ = new treeNode("",0,2);}
		;

DEF		:SPEC DECS SEMI
		{
			treeNode *tmp = new treeNode($2->data,3,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		;

DECS	:DEC COMMA DECS
		{
			treeNode *tmp = new treeNode($1->data+","+$3->data,3,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|DEC
		{
			treeNode* tmp = new treeNode($1->data,1,2);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		;

DEC		:VAR
		{
			treeNode* tmp = new treeNode($1->data,1,1);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|VAR ASN INIT
		{
			treeNode *tmp = new treeNode($1->data,3,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		;

INIT	:EXP
		{
			treeNode* tmp = new treeNode("INIT",1,1);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|LC ARGS RC
		{
			treeNode *tmp = new treeNode("INIT",3,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
			//Tranverse(tmp,0);
		}
		;

EXP		:LNOT EXP
		{
			treeNode *tmp = new treeNode("EXP",2,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|PINC EXP
		{
			treeNode *tmp = new treeNode("EXP",2,2);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|PDEC EXP
		{
			treeNode *tmp = new treeNode("EXP",2,3);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|BNOT EXP
		{
			treeNode *tmp = new treeNode("EXP",2,4);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|EXP MUL EXP
		{
			treeNode *tmp = new treeNode("EXP",3,5);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP DIV EXP
		{
			treeNode *tmp = new treeNode("EXP",3,6);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP MOD EXP
		{
			treeNode *tmp = new treeNode("EXP",3,7);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP ADD EXP
		{
			treeNode *tmp = new treeNode("EXP",3,8);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP MIN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,9);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP SL EXP
		{
			treeNode *tmp = new treeNode("EXP",3,10);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP SR EXP
		{
			treeNode *tmp = new treeNode("EXP",3,11);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP GT EXP
		{
			treeNode *tmp = new treeNode("EXP",3,12);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP GTE EXP
		{
			treeNode *tmp = new treeNode("EXP",3,13);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP LT EXP
		{
			treeNode *tmp = new treeNode("EXP",3,14);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP LTE EXP
		{
			treeNode *tmp = new treeNode("EXP",3,15);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP EQ EXP
		{
			treeNode *tmp = new treeNode("EXP",3,16);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP NEQ EXP
		{
			treeNode *tmp = new treeNode("EXP",3,17);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP BAND EXP
		{
			treeNode *tmp = new treeNode("EXP",3,18);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP BXOR EXP
		{
			treeNode *tmp = new treeNode("EXP",3,19);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP BOR EXP
		{
			treeNode *tmp = new treeNode("EXP",3,20);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP LAND EXP
		{
			treeNode *tmp = new treeNode("EXP",3,21);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP LOR EXP
		{
			treeNode *tmp = new treeNode("EXP",3,22);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP ASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,23);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP ADDASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,24);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP MINASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,25);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP MULASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,26);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP DIVASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,27);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP BANDASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,28);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP BXORASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,29);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP BORASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,30);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}		
		|EXP SLASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,31);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP SRASN EXP
		{
			treeNode *tmp = new treeNode("EXP",3,32);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|LP EXP RP
		{
			treeNode *tmp = new treeNode("EXP",3,33);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|ID LP ARGS RP
		{
			treeNode *tmp = new treeNode("EXP",4,34);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			$$ = tmp;
		}
		|ID ARRS
		{
			treeNode *tmp = new treeNode("EXP",2,35);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			$$ = tmp;
		}
		|EXP DOT ID
		{
			treeNode *tmp = new treeNode("EXP",3,36);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|INT
		{
			treeNode *tmp = new treeNode("EXP",1,37);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		|{$$ = new treeNode("EXP",0,38);}
		;

ARRS	:LB EXP RB ARRS
		{
			treeNode *tmp = new treeNode("ARRS",4,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			tmp->child[3] = $4;
			$$ = tmp;
		}
		|{$$ = new treeNode("ARRS",0,2);}
		;

ARGS	:EXP COMMA ARGS
		{
			treeNode *tmp = new treeNode("ARGS",3,1);
			tmp->child[0] = $1;
			tmp->child[1] = $2;
			tmp->child[2] = $3;
			$$ = tmp;
		}
		|EXP
		{
			treeNode *tmp = new treeNode("ARGS",1,2);
			tmp->child[0] = $1;
			$$ = tmp;
		}
		;
%%

#include "lex.yy.c"

int main(int argc, char* argv[])
{
//	printf("111\n");
//	printf("enter file name: ");
//	char name[20];
//	scanf("%s",name);
	if(argc != 3)
	{
		fprintf(stderr,"Usage: ./scc <input> <output>\n");
		return 0;
	}
	yyin = fopen(argv[1],"r");
//	yyout = fopen(argv[2],"w");
	outputFile = argv[2];

	if(yyin == NULL)
		printf("yyin == NULL!\n");
//	printf("111\n");
	yyparse();

	fclose(yyin);
	fclose(yyout);
	return 0;
}

int yyerror(char* s)
{
	printf("line%4d Error :%s,%s\n",yylineno,s,yytext);
}


void Tranverse(treeNode *t, int n)
{
	int i;
	for(i=0; i<n; i++) fprintf(yyout,"\t");
	fprintf(yyout,"%s\n",(t->data).c_str());
	if(t->childnum >= 1)
	{
		for(i=0; i< (t->childnum); i++)
			Tranverse(t->child[i],n+1);
	}
}


