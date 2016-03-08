scc:tab.o code.o glo.o
	g++ -o scc tab.o code.o glo.o

tab.o:y.tab.c
	yacc -d myparse.y
	lex mylexer.l
	g++ -c y.tab.c -o tab.o

code.o:codegen.cpp codegen.h
	g++ -c codegen.cpp -o code.o

glo.o:Global.cpp Global.h
	g++ -c Global.cpp -o glo.o
