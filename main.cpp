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








