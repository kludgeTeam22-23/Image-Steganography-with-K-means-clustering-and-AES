#include <iostream>
#include <sstream>
#include <fstream>
#include "keyExpansion.h"
#include "decryption.h"

using namespace std;

void convertStr_Hex(string ascii_str, char *hex_str){
    int loop = 0;
    int i = 0;
    for (int i = 0; i < 16; i ++){
        sprintf((char *)(hex_str+loop),"%02X", ascii_str[i]);
        loop += 2;
        if(i == 15) continue;
        sprintf((char *)(hex_str + loop), " ");
        loop ++;
        
    }
}

string convertBin_Hex(string cipherText){
    int start = 0;
    string output;

    for (int start = 0; start < cipherText.length(); start += 8){
    string r;
    for (int i = start; i < start + 8; i++){
        r = r + cipherText[i];
    }
    // cout << r << "\n";

    string out;
    for(int i = 0; i < 8; i += 4){
        int8_t n = 0;
        for(int j = i; j < i + 4; ++j){
            n <<= 1;
            if(r[j] == '1')
                n |= 1;
        }

        if(n<=9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }
    
    // cout << out << "\n";
    if (start != cipherText.length() - 8){
        output = output + out + " ";
    }
    else{
        output = output + out;
    }
 
    }
    return output;
}

void decrypt_final() {

    string cipherText, key_input;

    ifstream MyReadFile("example.txt");
    getline (MyReadFile, cipherText);

    cipherText = convertBin_Hex(cipherText);
    // cout << cipherText << "\n";
    int cipherText_len = 0;

    for(int i = 0; i < cipherText.length(); i ++){
        if (cipherText [i] == ' ')
            cipherText_len ++;
    }

    cipherText_len ++;

    unsigned char *decryptedText = new unsigned char [cipherText_len];

    istringstream input_stream(cipherText);
    unsigned int x;
    for(int i = 0; i < cipherText_len; i++){
	    input_stream >> hex >> x;
		decryptedText [i] = x; 
	}

    cout << "Please ensure that the key is of 16 characters. Please enter key: ";
    getline (cin, key_input);
    int len = key_input.length();

    char hex_str [3*len - 1];
    convertStr_Hex(key_input, hex_str);    

    //creating the key. 
    istringstream key_stream(hex_str);
    unsigned char key [16];

    cout << "Key: ";
    for(int i = 0; i < 16; i++){
	    key_stream >> hex >> x;
		key [i] = x; 
        cout << hex << (int) key [i] << " ";
	}
    cout << endl;

    //creating 11 keys for the 11 rounds
    unsigned char expandedKey [176];
    key_expansion(key, expandedKey);

    //decryption
    for(int i = 0; i < cipherText_len; i += 16){
        decrypt (decryptedText + i, expandedKey);
    }

    cout << endl;

    cout << "The decrypted text is: ";
    for(int i = 0; i < cipherText_len; i ++){
        cout << decryptedText [i];
    }
    cout << endl << endl;

    // return 0;
}