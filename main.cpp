#include "SimpleCrypt.h"

int main(int argc, char* argv[]) {
	using namespace std;
	srand((unsigned int) time(NULL));

	if (argc < 2) {
        show_usage(argv[0]);
        return EXIT_FAILURE;
	}

	string inputhandle, outputhandle;
	for (int i = 1; i < argc; ++i) {
		string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
        	show_usage(argv[0]);
            return EXIT_SUCCESS;
        } else if ((arg == "-f") || (arg == "--input")) {
 			if (i + 1 < argc) {
            	inputhandle = argv[++i]; 
           	} else { 
  				cerr << "--input file option requires one argument." << std::endl;
           		return EXIT_FAILURE;
            } 
		} else if ((arg == "-o") || (arg == "--output")) {
 			if (i + 1 < argc) {
            	outputhandle = argv[++i]; 
           	} else { 
  				cerr << "--output file option requires one argument." << endl;
           		return EXIT_FAILURE;
            }
		} else if ((arg == "-i")) {
			checkkey();
			inputencrypt(readkey(".secretkey"));
			return EXIT_SUCCESS;
	    } else {
			cerr << "unknown argument." << endl;
			show_usage(argv[0]);
       		return EXIT_FAILURE;
		}
	}
	
	if(inputhandle.length() == 0 || outputhandle.length() == 0){
		cerr << "input or output file missing" << endl;
		show_usage(argv[0]);
        return EXIT_FAILURE;
	} else{
		checkkey();
		filecrypt(readkey(".secretkey"),inputhandle, outputhandle);
	}
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








