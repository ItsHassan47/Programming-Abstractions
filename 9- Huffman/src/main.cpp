#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

struct HuffmanNode
{
	char character;
	int freq;
	HuffmanNode *zero, *one;

	HuffmanNode(char c = '\0', int f = 0, HuffmanNode *z = nullptr, HuffmanNode *o = nullptr)
		: character {c}, freq {f}, zero {z}, one {o} {}
	bool isLeaf() const { return zero == nullptr && one == nullptr; }
};

void calcFreq(const std::string &str, std::map<char, int> &freqTable);
HuffmanNode *buildEncodingTree(const std::map<char, int> &freqTable);
std::map<char, std::string> calcCodes(const HuffmanNode *root, std::string s);
std::string decode(HuffmanNode *root, const std::string &encodedMsg);
void printTree(const HuffmanNode *root);
void freeTree(HuffmanNode *&root);

int main()
{
	std::map<char, int>freqTable;
	std::string word {"HASSAN"};
	std::string encodedMsg;
	calcFreq(word, freqTable);

	HuffmanNode *root = buildEncodingTree(freqTable);
	std::map<char, std::string>codes = calcCodes(root, "");

	for (const auto &it : codes)
		std::cout << it.first << " " << it.second << std::endl;

	for (const auto &s : word)
		encodedMsg += codes[s];
	std::cout << '\n' << encodedMsg << std::endl;

	std::string decodedMsg = decode(root, encodedMsg);
	std::cout << decodedMsg << std::endl;
	freeTree(root);
	return 0;
}

void calcFreq(const std::string &str, std::map<char, int> &freqTable)
{
	for (const auto &s : str)
		freqTable[s]++;
}

std::map<char, std::string> calcCodes(const HuffmanNode *root, std::string s)
{
	static std::map<char, std::string>codes;
	if (root == nullptr) {
		std::map<char, std::string>empty_map;
		return empty_map;
	}
	if (root->character != '#')
		codes.insert(std::make_pair(root->character, s));	// codes[root->character] = s;
	calcCodes(root->zero, s + "0");
	calcCodes(root->one, s + "1");

	return codes;
}

HuffmanNode *buildEncodingTree(const std::map<char, int> &freqTable)
{
	auto cmp = [](const HuffmanNode *left, const HuffmanNode *right) { return (left->freq) > (right->freq); };
	std::priority_queue <HuffmanNode *, std::vector<HuffmanNode *>, decltype(cmp) > pq(cmp);

	for (auto it = freqTable.begin(); it != freqTable.end(); ++it)
		pq.push(new HuffmanNode(it->first, it->second));

	while (pq.size() > 1) {
		HuffmanNode *zero = pq.top();
		pq.pop();
		HuffmanNode *one = pq.top();
		pq.pop();
		HuffmanNode *top = new HuffmanNode('#', zero->freq + one->freq, zero, one);
		pq.push(top);
	}
	return pq.top();
}

std::string decode(HuffmanNode *root, const std::string &encodedMsg)
{
	if (root == nullptr)	return "";
	HuffmanNode *temp = root;
	std::string decodedMsg {};
	for (const auto &s : encodedMsg) {
		if (s == '0')
			temp = temp->zero;
		else
			temp = temp->one;

		if (temp->isLeaf()) {
			decodedMsg += temp->character;
			temp = root;
		}
	}
	return decodedMsg;
}

void printTree(const HuffmanNode *root)
{
	if (root == nullptr)	return;
	printTree(root->zero);
	printTree(root->one);
	std::cout << root->character << " ";
}

void freeTree(HuffmanNode *&root)
{
	if (root == nullptr)	return;
	freeTree(root->zero);
	freeTree(root->one);
	delete root;
}