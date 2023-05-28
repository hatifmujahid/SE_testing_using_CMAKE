#include<iostream>
#include<conio.h>
#include<string.h>
#include<cctype>
#include<cmath>
#include <gtest/gtest.h>

using namespace std;
//function prototypes
string textEnc(string encrypt, string key);
string textDec(string decrypt, string key);
TEST(EDA, CorrectDecryption) {
  // Expect a string after being decrypted to be equal to the original string.
  string original = "WAHAJJAVED";
  string encrypted = textEnc(original, "assignment");
  string decrypted = textDec(encrypted, "assignment");
  EXPECT_EQ(original, decrypted);
}
TEST(EDA,EmptyInput){
//if the input string is empty the encrypted string should also be empty
	string original = "";
	string encrypted = textEnc(original,"assignment");
	EXPECT_EQ(original,encrypted);
}
TEST(EDA,CorrectEncryption){
	//encrypted string should not equal original string
	string original = "AGHA MAARIJ AMIR";
	string encrypted = textEnc(original,"assignment");
	EXPECT_NE(original,encrypted);
}
//defect testing
TEST(EDA,IncorrectKey){
	//if encryption key != decryption key , the string should not be decrypted
	string original = "Agha Maarij Amir";
	string encrypted = textEnc(original,"assignment");
	string decrypted = textDec(original,"notassignment");
	EXPECT_EQ(original,decrypted);
}
TEST(EDA, wronginput){
	//number input is invalid
	string original = "hatif123";
  	string encrypted = textEnc(original, "assignment");
	string decrypted = textDec(encrypted, "assignment");
	EXPECT_EQ(decrypted, encrypted);
}
TEST(EDA, message_key_no_same){
	// swapping string with key should yield same result(if they have equal length)
	string original = "hatifmujahi";
	string original2 = "assignement";
	string encrypted1 = textEnc(original,original2);
	string encrypted2 = textEnc(original2,original);
	EXPECT_EQ(encrypted1,encrypted2);
}
int main() {
    testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

string textEnc(string encrypt,string key){
	char newKey[100],encryption[100];
	int j=0;
	//remove punctuations from string and capitalize
	for(int i=0;i<encrypt.size();i++){
		if(!ispunct(encrypt[i]) && encrypt[i]!=' '){
			encrypt[j] = toupper(encrypt[i]);
			j++;
		}
	}
	encrypt[j]='\0';
	int stringLen = j;
	int encryptNum[stringLen],stringNum[stringLen],keyNum[stringLen];
	//convert into numbers
	for(int i=0;i<stringLen;i++){
		stringNum[i] = encrypt[i]-'A';
	}
	//remove punctuations from key and capitalize
	for(int i=0,j=0;i<key.size();i++){
		if(!ispunct(key[i]) && key[i]!=' '){
			key[j] = toupper(key[i]);
			j++;
		}
	}
	key[j]='\0';
	int keyLen = key.size();
	//repititions of key
	int k=0;
	for(int i=0,j=0;i<stringLen;i++){
		if(j == keyLen){
			j=0;
		}
		newKey[i] = key[j];
		j++;
		k++;
	}
	newKey[k]='\0';
	//convert key into numbers
	for(int i =0;i<stringLen;i++){
		keyNum[i]= newKey[i] - 'A';
	}
	//comparison
	for(int i=0;i<stringLen;i++){
		encryptNum[i] = (stringNum[i] + keyNum[i]); 
	}
	//encryption
	for(int i=0,k=0;i<stringLen;i++){
		encryption[i] = (encryptNum[i] %26) + 'A';
		k++;
	}
	encryption[k]='\0';
	return encryption;
}
string textDec(string decrypt, string key){
	char newKey[100],decryption[100];
	int j=0;
	//remove punctuations and capitalize
	for(int i=0;i<decrypt.size();i++){
		if(!ispunct(decrypt[i]) && decrypt[i]!=' '){
			decrypt[j] = toupper(decrypt[i]);
			j++;
		}
	}
	decrypt[j] = '\0';
	int stringLen = j;
	int decryptNum[stringLen],stringNum[stringLen],keyNum[stringLen];
	//conversion into numbers
	for(int i=0;i<stringLen;i++){
		stringNum[i] = decrypt[i] - 'A';
	}
	//remove punctuations and capitalize key
	for(int i=0,j=0;i<key.size();i++){
		if(!ispunct(decrypt[i]) && decrypt[i] != ' '){
			key[j] = toupper(key[i]);
			j++;
		}
	}
	key[j] = '\0';
	//generate a repititive key
	int k=0;
	for(int i=0,j=0;i<stringLen;i++){
		if(j==key.size()){
			j=0;
		}
		newKey[i] = key[j];
		j++;
		k++;
	}
	newKey[k] = '\0';
	//convert key into numbers
	for(int i=0;i<stringLen;i++){
		keyNum[i] = newKey[i] - 'A';
	}
	//comparison
	for(int i=0;i<stringLen;i++){
		decryptNum[i] = stringNum[i] - keyNum[i] + 26;
	}
	//Decryption
	for(int i=0,j=0;i<stringLen;i++){
		decryption[i] = (decryptNum[i] % 26) + 'A';
		j++;
	}
	decryption[j] = '\0';
	return decryption;
}