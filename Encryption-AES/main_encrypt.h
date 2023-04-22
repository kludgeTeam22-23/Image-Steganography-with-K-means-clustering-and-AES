#include <iostream>
#include <sstream>
#include "keyExpansion.h"
#include "encryption.h"
#include <fstream>

using namespace std;

//to convert string to hex
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

string convertInt_Bin(int n){
    string r, temp = "";
    int x;
    while (n != 0){
        r = (n %2 == 0 ? "0":"1") + r;
        n = n / 2;
    }
    if (r.length() != 8){
        x = 8 - r.length();
        for (int i = 0; i < x; i++){
            temp = temp + "0";
        }
    }
    return temp + r;
}


void encrypt_final() {
    string plaintext, key_input;

    cout << "Please enter the text to be encrypted: ";
    getline(cin, plaintext);
    
    //padding the plaintext:
    int plaintext_len = plaintext.length();
    int plaintext_padded_len;

    //creating length of padded plaintext
    if (plaintext_len % 16 != 0){
        plaintext_padded_len = (16 - (plaintext_len % 16)) + plaintext_len;
    }
    else{
        plaintext_padded_len = plaintext_len;
    }

    //allocating memory on the heap for cipherText
    unsigned char * cipherText = new unsigned char[plaintext_padded_len];

    //creating cipherText with padding
    for (int i = 0; i < plaintext_padded_len; i ++){
        if (i >= plaintext_len){
            cipherText [i] = 0;
        }
        else{
            cipherText[i] = plaintext [i];
        }
    }

    cout << "Please ensure that the key is of 16 characters. Please enter key: ";
    getline (cin, key_input);
    int len = key_input.length();

    char hex_str [3*len - 1];
    convertStr_Hex(key_input, hex_str);    

    //creating the key.
    istringstream key_stream(hex_str);
    unsigned char key [16];
    unsigned int x;

    // cout << "Key: ";
    for(int i = 0; i < 16; i++){
	    key_stream >> hex >> x;
		key [i] = x; 
        // cout << hex << (int) key [i] << " ";
	}
    cout << endl;

    //creating 11 keys for the 11 rounds
    unsigned char expandedKey [176];
    key_expansion(key, expandedKey);

    //encryption
    for(int i = 0; i < plaintext_padded_len; i += 16 ){
        encrypt(cipherText + i, expandedKey);
    }
    
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        for(int i = 0; i < plaintext_padded_len; i ++){
            myfile << convertInt_Bin((int) cipherText [i]) ;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}