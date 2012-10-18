/* 
 * File:   SimpleCrypt.h
 * Author: dm
 *
 * Created on October 17, 2012, 2:36 PM
 */

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
void encryptString(string, string);

#endif	/* SIMPLECRYPT_H */

