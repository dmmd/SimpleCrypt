#include "SimpleCrypt.h"

int main(int argc, char* argv[]) {
	srand((unsigned int) time(NULL));
	checkkey();
	
	int chances = 5;
	string input;
		
	inputencrypt(readkey(".secretkey"));
    return EXIT_SUCCESS;
}

void inputencrypt(string cipher){
	cout << "enter text to encrypt" << endl;

	string plaintext;
	getline(cin, plaintext);
	
	cout << endl << "ciphertext: " << endl;
	string ciphertext = encryptString(cipher, plaintext);
	
	printkey(ciphertext, ciphertext.length());
	
	cout << endl << "restored plaintext: " << endl;
	string restoredtext = encryptString(cipher, ciphertext);
	
	cout << restoredtext << endl;
}

void fileencrypt(string cipher){}







