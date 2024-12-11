#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

string scramble(const string& text) {
	
	string chars = text;
	
	for (int i = 0; i < chars.length(); i++){
		srand(time(0));
		
		int j = rand() % chars.length();
		char temp = chars[i];
		chars[i] = chars[j];
		chars[j] = temp;
	}
	
	return chars;
}

int main() {
	string text[5] = {"memorise", "pacify", "strangle", "marianna", "enomfon"};
	string scrambled = scramble(text);
	
	cout << "Scrambled word guess game " << endl;
	
	while (count < 5){
		cout << Scrambled(text[count]);
		
		getline(cin, guess);
		
		if (guess == words[count]){
			cout << "Correct";
		}
		else {
			cout << "This is wrong.";
		}
		
		cout++;
	}
	
	return 0; 
}