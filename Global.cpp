//#pragma warning(disable:4503 4511 4512 4514 4663 4786)
#include "Global.h"
#include <string>

string outputFile;
int labelNumber;
int globalNumber = 1;
map <string, map<string, int>*> FT;
map <string, map<string, int>*> ST;	//struct name and attribute offset
map <string, map<string, int>*> ISA;
map <string, string> STAC;

