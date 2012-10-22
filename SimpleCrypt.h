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
bool fexists(const char);
string readkey(string);
void printkey(string, int);
string encryptString(string, string);
char printChar(char);
char xorChars(char, char);
void inputencrypt(string);
void fileencrypt(string);
void checkkey();
void filecrypt(string, string, string);
static void show_usage(string);

inline bool fexists(const char *filename){return ifstream(filename);}
//inline void writekey(string filename, int keylength){ofstream keyfile(filename.c_str()) << getkey(keylength);}

#endif	/* SIMPLECRYPT_H */

