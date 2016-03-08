#! /bin/bash
yacc -d myparse.y
lex mylexer.l
g++ y.tab.c codegen.cpp Global.cpp -o scc
