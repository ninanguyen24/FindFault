// Author: Nina Nguyen
// Filename: p2.cpp
// Date: 10/21/2017 (Version 1 - 10/15/2017)
// Version: 2

/*Descriptions and anticipated use: This class encapsulate several (FIVE) EncryptWord objects. The user has to correct input words that matches
requirements set by EncryptWord class. (4 letters, lowercase or more and no spaces or punctuations). It will encrypt or decrypt a word but adds the
notion of "corruption". The program uses a random number generator between 1-100 and then use modulo to get an odd
or even number. Even is considered false and the word won't be corrupted and Odd is considered true and will be corrupted.
Words are corrupted by adding "x" to the end of the string.  The program will assist the user in finding the
corrupted word by calling decode on the encrypted word. If the decrypted word does not match the original word
sent in by the user, it will be considered corrupt. Query will keep track of the numnber of corrupt words and return that amount.

Data structure used: Array is used to hold distinct FindFault objects then passed into the callEncrypt() method
Class used with functionality: EncryptWord- shift(string) and decode()
							   Findfault - uses callEncrypt(string[]), isCorrup() and faultQuery() to return the corrupted words.
Value ranges: Array of words is set to hold 5 words.
Source of input: cin
Format of outpout: cout
User interface used to get input from the user.
Legal and illegal inputs: User is only asked for words to encrypt. 4 letters or more, no spaces, punctuations or numbers, and all lowercase.
						  Program requires "yes" or "no" user input and should be entered as a single string lower case. There are some 
						  defensive programming in placed but program might react differently if the correct input was not entered.
Design and intent: Driver is just to accept five words from the user and let FindFault class corrupt the words and encrypt it. The array of
words will be passed into callEncrypt() method. Need to call the helper method getArrayOfWords() before calling any FindFault functions.
Errors: User is expected to enter the correct words, program will work when words passed through to the class doesn't meet requirements
	    but results are not guaranteed.
Assumption: User is required to enter the correct input. The program may crash or may not return the expected result if
words entered are incorrect. Errors will not be caught by the class program and will fall on the application programmer to
provide the correct words. FindFault is not interative, user won't be able to guess the wrong words. It will be returned by
class once all the words are passed in. User won't have any access to EncryptWord class. FindQuery() can only be called when state is corrupt.
User can request to have findFault assist in finding corruption.
There is nothing to return when the state is not corrupt. So defensive programming will be in placed to make sure isCorrupt() returns true before
findQuery() can be accessed. User can continue to use the program as long as keepPlaying is "true". 
*/
#include "FindFault.h"
#include "EncryptWord.h"
#include <iostream>
#include <string>
using namespace std;

//Short introduction about the program and what it needs to run
void introForP2() {
	cout << "Welcome to Find Fault! This program takes in 5 words from you and encrypt it. \nThere might be some corruption to your encrypted words ";
	cout << "but don't worry! \nFind Fault will help you find the corrupted words and let you know how many \nwords were corrupted in total." << endl;
	cout << "Let's begin!";
	cout << "************************************************************************" << endl;
	cout << endl;
}

//This method is called by main to get 5 words from the user and put it in the array
string* getArrayOfWords() {
	int count = 0;
	string* words = new string[ARRAY_SIZE];

	cout << "Please enter 5 all lowercase words that are 4 letters or more. Avoid punctuations and spaces." << endl;
	while (count != ARRAY_SIZE) {
		string userWord;
		cout << "Please enter word #" << count + 1 << ": ";
		cin >> userWord;
		words[count] = userWord;
		count++;
	}
	return words;
}

/*main create an object of findFault and calls the getArrayOfWords() to passes that to the findFault object.
Allows the user to get help finding the corrupted word or not.
And allow the user to continue to encrypting more words until they want to stop.*/
int main() {

	introForP2();

	bool keepPlaying = true;
	while (keepPlaying) {
		FindFault findFault;
		
		//For testing only
		//string testArray[] = { "hello", "world", "soccer", "seattle", "lamp" };
		//findFault.callEncrypt(testArray);

		string* wordsArray = getArrayOfWords();
		string* wordsReturn = findFault.callEncrypt(wordsArray);
	

		for (int i = 0; i < ARRAY_SIZE; i++) {
			cout << "The encrypted words " << "#" << i + 1 << " are: " << wordsReturn[i] << endl;
		}
		delete[] wordsArray;

		string userResponse;
		cout << "Do you need help to find the corrupted words? (Enter \"yes\" or \"no\")" << endl;
		cin >> userResponse;
		cout << endl;
		if (userResponse == "yes" || userResponse == "Yes") {
			if (findFault.isCorrupt()) {
				findFault.faultQuery();
			}
			else {
				cout << "None of the words are corrupted!" << endl;
			}
		}
		else if (userResponse == "no" || userResponse == "No") {
			cout << "Thank you for using the program. Have a great day!" << endl;
		}
		else {
			cout << "Invalid response! The program is going to terminate. Goodbye." << endl;
		}
		cout << endl;
		cout << "Do you want to use the program again? (\"yes\" or \"no\") " << endl;
		cin >> userResponse;
		if (userResponse == "yes" || userResponse == "Yes") {
			keepPlaying = true;
		}
		else {
			keepPlaying = false;
		}
	}
}