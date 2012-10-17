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

void printKey(string s){
    for(int x = 0; x < 24; ++x){
        char c = s[x];
        if (!isprint(static_cast<unsigned char>(c))){
            cout << "-";
        } else {
        cout << c;
        }
    }
    cout << endl;
}
