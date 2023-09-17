#include "Header.h"
string keyWords[] = {
   "operator",
   "const",
   "catch",
   "return",
   "public",
   "private",
   "switch",
   "for",
   "namespace",
   "if",
   "struct",
   "case",
   "break",
   "throw",
   "int",
   "this",
   "new",
   "do",
   "nullptr ",
   "void"
};
string help[] = {
	"declaration of an overloaded operator",
	"const-qualified member functions",
	"function-try-block",
	"as the declaration of the statement",
	"public access specifier",
	"private access specifier",
	"a selection operator",
	"a cycle",
	"namespace alias definition",
	"conditional operator",
	"declaration of a scoped enumeration type",
	"block in switch",
	"loop completion operator",
	"exception specifications",
	"integer",
	"this pointer",
	"dynamic memory allocation operator",
	"do-while loop: as the declaration of the loop",
	"null pointer",
	"parameter list of a function with no parameters"
};
void fillTable(unordered_map<string, string>& m) 
{
	for (int i = 0; i < 20; i++)
		m[keyWords[i]] = help[i];
}
void print(unordered_map<string, string> m) 
{
	for (auto el : m)
		cout << el.first << " --> " << el.second << endl;
}
void findEl(unordered_map<string, string> m, string str) {
	bool isFind = false;
	for (auto el : m) {
		if (el.first == str) {
			cout << "Ключевое слово найдено:" << endl;
			cout << el.first << " --> " << el.second << endl;
			isFind = true;
		}
	}
	if (!isFind)
		cout << "Ключевое слово не найдено." << endl;
	
}
void changeHelp(unordered_map<string, string>& m, string help, string keyWord) 
{
	m[keyWord] = help;
}