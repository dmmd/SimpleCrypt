#include "SimpleCrypt.h"

int main() {
	srand((unsigned int) time(NULL));
	int keylength = 8;
    string keyhandle = "keys/DESkey.key";
    if(!fexists(keyhandle.c_str())){
        cout << "generating des key: DESkey.key";
        writekey(keyhandle, keylength);
    }
    
    string cipher = readkey(keyhandle);
    //printKey(cipher, keylength);

	cout << "enter text to encrypt" << endl;

	string plaintext;
	getline(cin, plaintext);
	
	cout << endl << "ciphertext: " << endl;
	string ciphertext = encryptString(cipher, plaintext);
	
	printkey(ciphertext, ciphertext.length());
	
	cout << endl << "restored plaintext: " << endl;
	string restoredtext = encryptString(cipher, ciphertext);
	
	cout << restoredtext << endl;
	
    return EXIT_SUCCESS;
}








