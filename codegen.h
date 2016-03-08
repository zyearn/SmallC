//#pragma warning(disable:4503 4511 4512 4514 4663 4786)
#ifndef _CODEGEN_H
#define _CODEGEN_H
#include "treeNode.h"
#include "Global.h"

void genProgram(treeNode* node);
void genExtdefs(treeNode* node,int type);
void genGT(treeNode* node);
void genFT(treeNode* node);
void genExtdef(treeNode* node,int type);
void genExtvars(treeNode* node, int type, string scope);
void genStmtblock(treeNode* node, int type, string scope, int labelN = 0);
void genStmts(treeNode* node, int type, string scope, int labelN = 0);
void genStmt(treeNode* node, int type, string scope, int labelN = 0);
void genDefs(treeNode* node, int type, string scope);
void genDef(treeNode* node, int type, string scope);
void genDecs(treeNode* node, int type, string scope);
void genDec(treeNode* node, int type, string scope);
void genInit(treeNode* node, int type, string scope);
void genExp(treeNode* node, int type, string scope,int PRE = 0);
int genArgs(treeNode* node, int type, string scope);

#endif
