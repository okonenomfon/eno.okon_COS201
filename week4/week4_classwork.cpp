#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

bool palindrome(const string &str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool anagrams(string str1, string str2) {
	
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    cout << "Str1 is" << (palindrome(str1) ? "" : "not ") << "a palindrome." << endl;
    cout << "Str2 is" << (palindrome(str2) ? "" : "not ") << "a palindrome." << endl;
    cout << "The strings are " << (anagrams(str1, str2) ? "" : "not ") << "anagrams." << endl;

    return 0;
}