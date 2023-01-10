#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

struct TreeNode {
	char letter;
	int freq;
	TreeNode* left, * right;
	TreeNode() {
		letter = NULL;
		freq = NULL;
		left = NULL;
		right = NULL;
	}
};

// Ascending

bool comparator(const std::pair<char, int>& left, const std::pair<char, int>& right)
{
	return (left.second < right.second);
}

TreeNode* createTreeNode(std::pair<char, int> left, std::pair<char, int> right) {
	TreeNode* leftNode = new TreeNode();
	TreeNode* rightNode = new TreeNode();

	leftNode->freq = left.second;
	leftNode->letter = left.first;
	rightNode->freq = right.second;
	rightNode->letter = right.first;

	TreeNode* curr = new TreeNode();

	curr->left = leftNode;
	curr->right = rightNode;
	curr->freq = leftNode->freq + rightNode->freq;

	return curr;
}

TreeNode* createTreeNode(TreeNode* left, std::pair<char, int> right) {
	TreeNode* rightNode = new TreeNode();

	rightNode->freq = right.second;
	rightNode->letter = right.first;

	TreeNode* curr = new TreeNode();

	curr->left = left;
	curr->right = rightNode;
	curr->freq = left->freq + rightNode->freq;

	return curr;
}

TreeNode* createTreeNode(TreeNode* left, TreeNode* right) {
	TreeNode* curr = new TreeNode();

	curr->left = left;
	curr->right = right;
	curr->freq = left->freq + right->freq;

	return curr;
}

void createTable(TreeNode* root, std::map<char, std::string>& table, std::string number) {
	if (root->letter) {
		table[root->letter] = number;
		return;
	}

	createTable(root->left, table, number + '0');
	createTable(root->right, table, number + '1');
}

void createTable(TreeNode* root, std::map<char, std::string>& map) {
	createTable(root, map, std::string());
}

std::string encode(std::map<char, std::string> map, std::string text) {
	std::string result = "";
	for (char ch : text) {
		result += map[ch];
	}
	return result;
};


std::string decode(TreeNode* root, std::string text) {
	auto it = root;
	std::string result = "";
	for (char ch : text) {
		if (it->letter) {
			result += it->letter;
			it = root;
		};
		if (ch == '0') it = it->left;
		else it = it->right;
	}

	return result;
}

void printTable(std::map<char, std::string> table) {
	std::cout << "Table:" << std::endl;
	for (auto it = table.begin(); it != table.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

int main()
{
	std::vector<std::pair<char, int>> vec;
	std::map<char, int> freq;

	std::ifstream in("huffman.in");
	std::ifstream compressed("huffman.out");
	std::ofstream out("huffman.out");

	std::string input = "";

	while (std::getline(in, input));

	for (char ch : input) freq[ch]++;

	// Converting freq map to a vector

	for (auto it = freq.begin(); it != freq.end(); ++it) {
		vec.push_back(std::pair<char, int>(it->first, it->second));
	}

	// sort ascending order
	std::sort(vec.begin(), vec.end(), comparator);

	for (auto it = vec.begin(); it < vec.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	auto root = createTreeNode(vec[0], vec[1]);

	for (auto it = vec.begin() + 2; it != vec.end(); ++it) {
		if (it == vec.end() - 1 || root->freq <= (it + 1)->second) {
			root = createTreeNode(root, *it);
		}
		else {
			auto tree = createTreeNode(*it, *(it + 1));
			root = createTreeNode(root, tree);
			it++;
		}
	}

	std::map<char, std::string> table;

	createTable(root, table);

	std::string result = encode(table, input);
	out << result;

	std::string compressedText = "";
	in.close();
	out.close();

	while (std::getline(compressed, compressedText));

	printTable(table);
	std::cout << "Text: " << input << std::endl;
	std::cout << "Encoded: " << result << std::endl;
	std::cout << "Decoded: " << decode(root, compressedText);

	return 0;
}
