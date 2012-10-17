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
    ifstream keyFile;
    keyFile.open(s.c_str());
    char output[100];
    while (!keyFile.eof()){
        keyFile >> output;
    }
    
    string cipher = output;
    return cipher;
}
