#include "SimpleCrypt.h"

void filecrypt(string cipher, string filehandle, string outfilehandle){
	ifstream::pos_type size;
	char * memblock;
	
	ifstream file(filehandle.c_str(), ios::in|ios::binary|ios::ate);
	ofstream outfile(outfilehandle.c_str(), ios::out|ios::binary|ios::ate);
	
	size = file.tellg();
	memblock = new char [size];
	file.seekg (0, ios::beg);
	file.read (memblock, size);
	file.close();
	
	for(int i = 0; i < size; i += 8){
		for(int j = 0; j < 8; ++j){
			if(j > size){break;}
			outfile << static_cast<unsigned char>((cipher[j] ^ memblock[i + j]));
		}
  	}
	
	outfile.close();
}