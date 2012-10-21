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
//void show_usage(string);

inline bool fexists(const char *filename){return ifstream(filename);}
inline void show_usage(string name) {
	cerr << "Usage: " << name << " "
    << "Options:\n"
    << "\t-h,--help\t\tShow this help message\n"
	<< "\t-i,--input mode\t\tEncrypt text form stdin\n"
  	<< "\t-f,--input file\t\tSpecify the input file path\n"
	<< "\t-o,--output file\tSpecify the output file path" << endl;
}

#endif	/* SIMPLECRYPT_H */

