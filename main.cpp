#include "SimpleCrypt.h"

int main() {
    string keyHandle = "keys/DESkey.key";
    if(!fexists(keyHandle.c_str())){
        cout << "generating des key: DESkey.key";
        writeKey(keyHandle, 24);
    }
    
    string cipher = readKey(keyHandle);
    printKey(cipher);
    return EXIT_SUCCESS;
}



bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return ifile;
}



void printKey(string sIn){
    char *a=new char[sIn.size()+1];
    int size = sIn.size();
    a[size]=0;
    memcpy(a,sIn.c_str(), size);
    
    for(int x = 0; x < size; ++x){
        if (isprint(static_cast<unsigned char>(a[x]))) {
            cout << a;
	} else {
            cout << "-";
        }
    }
}
