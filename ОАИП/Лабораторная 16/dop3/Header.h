#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void fillTable(unordered_map<string, string>& m);
void print(unordered_map<string, string> m);
void findEl(unordered_map<string, string> m, string str);
void changeHelp(unordered_map<string, string>& m, string help, string keyWord);