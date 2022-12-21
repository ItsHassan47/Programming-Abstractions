#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string sortWord(string word);

int main()
{
	ifstream english {"dictionary.txt"};
	map<string, vector<string>> anagrams;

	if (!english) {
		cerr << "Error opening dictionary.txt" << endl;
		return 1;
	}

	string word;
	while (getline(english, word)) {
		anagrams[sortWord(word)].push_back(word);
	}

	// Let user enter words, and print the word's anagrams
	string query;
	cout << "Enter a word to find anagrams (or \"q\" to quit): ";
	getline(cin, query);
	while (query != "q") {

		cout << "Your anagrams (including the word itself) are:" << endl;
		vector<string> matches = anagrams[sortWord(query)];
		for (const string &anagram : matches)
			cout << anagram << endl;

		cout << endl;
		cout << "Enter a word to find anagrams (or \"q\" to quit): ";
		getline(cin, query);
	}

	return 0;
}

/*
 * sortWord()
 *
 * Takes the given word, sorts the characters in alphabetical order,
 * and returns the resulting string.
 */
string sortWord(string word)
{
	sort(word.begin(), word.end());
	return word;
}

// With vectors

//void removeSpaces(string &str) {
//	remove_if(str.begin(), str.end(), isspace);
//}
//
//string sortLetters(string str) {
//	sort(str.begin(), str.end());
//	return str;
//}
//
//void toLowerCase(string &str) {
//	transform(str.begin(), str.end(), str.begin(), ::tolower);
//}
//
//
//int main() {
//
//	vector<string> dictionary;
//	vector<string> sorted;
//	string word;
//	ifstream in_file {"Scramble-Dictionary.txt"};
//
//	if (!in_file) {
//		cout << "Error opening Scramble-Dictionary.txt." << endl;
//		return 1;
//	}
//
//	while (getline(in_file, word)) {
//		removeSpaces(word);
//		toLowerCase(word);
//		sorted.push_back(sortLetters(word));
//		dictionary.push_back(word);
//	}
//
//	vector<string> anagrams;
//
//	string input;
//	cout << "Word: ";
//	getline(cin, input);
//	removeSpaces(input);
//	toLowerCase(input);
//	for (size_t i = 0; i < dictionary.size(); ++i) {
//		if (sorted[i] == sortLetters(input))
//			anagrams.push_back(dictionary[i]);
//	}
//
//	cout << "Anagrams of the " << input << " are: ";
//
//	for (const auto &vec : anagrams)
//		cout << vec << " ";
//
//	return 0;
//}