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
  				cerr << "--input file option requires one argument.";
           		return EXIT_FAILURE;
            } 
		} else if ((arg == "-o") || (arg == "--output")) {
 			if (i + 1 < argc) {
            	outputhandle = argv[++i]; 
           	} else { 
  				cerr << "--output file option requires one argument.";
           		return EXIT_FAILURE;
            }
		} else if ((arg == "-t")) {
			checkkey();
			inputencrypt(readkey(".secretkey"));
			return EXIT_SUCCESS;
	    } else if ((arg == "-v")) {
			cout << "simplecrypt v0.0.2 (2012-10-22)" << endl;
				return EXIT_SUCCESS;
		 } else {
			cerr << "unknown argument.";
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

static void show_usage(string name) {
	cerr << "Usage: " << name << " "
	    << "Options:\n"
	    << "\t-h\t\tShow this help message\n"
		<< "\t-v\t\tPrint the version of the program\n"
		<< "\t-t\t\tEncrypt text from stdin (test key)\n"
	  	<< "\t-f\t\tSpecify the input file path\n"
		<< "\t-o\t\tSpecify the output file path" << endl;
}








