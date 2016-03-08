//#pragma warning(disable:4503 4511 4512 4514 4663 4786)
#ifndef _GLOBAL
#define _GLOBAL
#include <string>
#include <map> 
#include <stack>
using namespace std;

extern string outputFile;
extern int labelNumber;
extern int globalNumber;
extern map <string, map<string, int>*> FT;
extern map <string, map<string, int>*> ST;
extern map <string, string> STAC;
extern map <string, map<string, int>*> ISA;

#endif
