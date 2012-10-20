#include "SimpleCrypt.h"

void writekey(string filename, int keylength){
	ofstream keyfile(filename.c_str());
	keyfile << getkey(keylength);
}

string getkey(int keylength){

    stringstream ss;
    for(int i = 0; i < keylength; ++i){
        ss << static_cast<unsigned char>((rand() % UCHAR_MAX));
    }
    return ss.str();
}

string readkey(string s){
    ifstream keyfile(s.c_str()); 

	if (!keyfile) {
	    cerr << "Program can not open the key file.\n";
	    EXIT_FAILURE;
	}
		
    string line;
    stringstream ss;
	while (getline(keyfile,line)){
	  ss << line;
	}
    return ss.str();
}

void printkey(string s, int i){
    for(int x = 0; x < i; ++x){
        char c = s[x];
        if (!isprint(static_cast<unsigned char>(c))){
            cout << "-";
        } else {
        cout << c;
        }
    }
    cout << endl;
}

char printChar(char c){
	if (!isprint(static_cast<unsigned char>(c))){
		return static_cast<unsigned char>(45);
	} else {
		return c;
	}
}

char xorChars(char x, char y){
	return static_cast<unsigned char>(x ^ y);
}

string encryptString(string key, string plaintext){
	int keylength = key.length();
	int textlength = plaintext.length();
	int nloops = textlength / keylength;
	int nsteps = textlength % keylength;
	stringstream cipherbuffer;
	int index = 0;
	
	for(int loop = 0; loop < nloops; ++loop){
		for(int y = 0; y < keylength; ++y){
			char c = key[y];
			cipherbuffer << xorChars(plaintext[index], key[y]);
			++index;
		}		
	}

	for(int x = 0; x < nsteps; ++x){
		char c = key[x];
		cipherbuffer << xorChars(plaintext[index], key[x]);
		++index;
	} 
	return cipherbuffer.str();
}
