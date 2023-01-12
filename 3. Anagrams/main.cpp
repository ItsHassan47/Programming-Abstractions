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