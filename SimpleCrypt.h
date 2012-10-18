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

void writeKey(string, int);
string getKey(int);
bool fexists(const char *filename);
string readKey(string);
void printKey(string, int);
string encryptString(string, string);
char printChar(char);
char xorChars(char, char);
#endif	/* SIMPLECRYPT_H */

