#include "SimpleCrypt.h"

int main() {
	int keylength = 8;
    string keyhandle = "keys/DESkey.key";
    if(!fexists(keyhandle.c_str())){
        cout << "generating des key: DESkey.key";
        writeKey(keyhandle, keylength);
    }
    
    string cipher = readKey(keyhandle);
    //printKey(cipher, keylength);

	cout << "enter text to encrypt" << endl;

	string plaintext;
	getline(cin, plaintext);
	
	cout << "ciphertext: " << endl;
	string ciphertext = encryptString(cipher, plaintext);
	
	printKey(ciphertext, ciphertext.length());
    return EXIT_SUCCESS;
}








