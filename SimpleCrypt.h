#ifndef SIMPLECRYPT_H
#define	SIMPLECRYPT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <fstream>

using namespace std;

void writekey(string, int);
string getkey(int);
bool fexists(const char *filename);
string readkey(string);
void printkey(string, int);
string encryptString(string, string);
char printChar(char);
char xorChars(char, char);

inline bool fexists(const char *filename){return ifstream(filename);}
#endif	/* SIMPLECRYPT_H */

