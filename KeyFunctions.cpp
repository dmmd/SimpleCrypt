#include "SimpleCrypt.h"

//pass a filename and keylength
void writeKey(string filename, int keylength){
    ofstream keyFile;
    keyFile.open(filename.c_str());
    string key = getKey(keylength);
    keyFile << key;
    keyFile.close();   
}

//pass a keylength, return a string of random chars of that length
string getKey(int keylength){
    srand((unsigned int) time(NULL));
    stringstream ss;
    for(int x = 0; x < keylength; ++x){
        ss << (unsigned char)(rand() % CHAR_MAX);
    }
    return ss.str();
}

string readKey(string s){
    
    cout << "reading key" << endl;
    ifstream keyfile;
    keyfile.open(s.c_str());
    
    string line;
    stringstream ss;
    if(keyfile.is_open()){
        while ( keyfile.good() ){
          getline (keyfile,line);
          ss << line;
        }
    } else {
        cerr << "Program can not open the key file" << endl;
        EXIT_FAILURE;
    }
    return ss.str();
}

void printKey(string s, int i){
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

void encryptString(string key, string plaintext){
	int keylength = key.length();
	int textlength = plaintext.length();
	int nloops = textlength / keylength;
	int nsteps = textlength % keylength;
	cout << "Encrypting Input" << endl
		<< "Key length: " << keylength<< endl
		<< "Plaintext length: " << textlength << endl
		<< "Number of loops needed to encrypt: " << nloops << endl
		<< "Number of additional steps: " << nsteps << endl;
	stringstream ss;
	int index = 0;
	for(int x = 0; x < nloops; ++x){
		cout << "loop " << x << "index " << index << endl << endl;
		stringstream keybuffer;
		for(int y = 0; y < keylength; ++y){
			char c = key[y];
			keybuffer << printChar(c);
			cout << plaintext[index];
			++index;
		}
		cout << endl;
		cout << keybuffer.str() << endl << endl;
		
	}
}
