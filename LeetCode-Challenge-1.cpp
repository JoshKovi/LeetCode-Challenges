/*
This was a leet code challenge to reverse a string of english characters while not
sswapping character positions of any non english character, adapted to console 
for testing. Not otherwise docuumented.
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	string insertString;

	do {

		cout << "Please enter string to reverse: ";
		getline(cin, insertString);

		string testString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		string tempString = "";
		vector<int> dashPos;
		vector<string> charFound;


		for (int i = insertString.length() - 1; i >= 0; i--) {
			if (testString.find(insertString[i]) != -1) {
				tempString += insertString[i];
			}
			else {
				dashPos.push_back(i);
				charFound.push_back(string(1, insertString[i]));
			}

		}

		reverse(dashPos.begin(), dashPos.end());
		reverse(charFound.begin(), charFound.end());

		for (int i = 0; i < dashPos.size(); i++) {
			tempString.insert(dashPos.at(i), charFound.at(i));
		}

		cout << tempString << "    |    " << insertString[4] << endl << endl;
	} while (insertString != "0");


	return 0;
}