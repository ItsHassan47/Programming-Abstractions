#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

/*
 *	Soundex Search
 *	First letter remain the same
 *	Remove the repeated alphabets
 */

string soundexSearch(string &s);
void removeDuplicates(string &s);

// main function
int main()
{
	string s {"Hassan"};
	removeDuplicates(s);
	cout << soundexSearch(s) << endl;

	return 0;
}

// Remove the repeated alphabets
void removeDuplicates(string &s)
{
	for (size_t i = 0; i < s.length() - 1;) {
		if (s.at(i) == s.at(i + 1))
			s.erase(i, 1);
		else
			++i;
	}
}

// First letter remain the same
string soundexSearch(string &s)
{
	for (size_t i = 1; i < s.length(); ++i) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' || s[i] == 'h' || s[i] == 'w') {
			s[i] = '0';
		}
		if (s[i] == 'b' || s[i] == 'f' || s[i] == 'p' || s[i] == 'v') {
			s[i] = '1';
		}
		if (s[i] == 'c' || s[i] == 'g' || s[i] == 'j' || s[i] == 'k' || s[i] == 'q' || s[i] == 's' || s[i] == 'x' || s[i] == 'z') {
			s[i] = '2';
		}
		if (s[i] == 'd' || s[i] == 't') {
			s[i] = '3';
		}
		if (s[i] == 'l') {
			s[i] = '4';
		}
		if (s[i] == 'm' || s[i] == 'n') {
			s[i] = '5';
		}
		if (s[i] == 'r') {
			s[i] = '6';
		}
	}

	// Remove zeros
	for (size_t i = 0; i < s.length(); ++i) {
		if (s.at(i) == '0') {
			s.erase(i, 1);
			--i;
		}
	}
	 
	constexpr size_t code_len = 4;
	// if code is too short than pad zeros
	if (s.length() < code_len) {
		const size_t zeros = code_len - s.length();
		for (size_t i = 0; i < zeros; ++i) {
			s += '0';
		}
	}

	// if code is too long then remove zeros
	else if (s.length() > code_len) {
		s = s.substr(0, code_len);
	}

	return s;
}