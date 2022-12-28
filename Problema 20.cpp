// Probleme Doamna Miroiu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct letter {
    char letter;
    int freq = 0;
};

struct TreeNode {
    int value;
    char letter;
    TreeNode* left;
    TreeNode* right;
};


int findMin(std::map<char, int> letters) {
    int min = INT_MAX;

    for (auto letter : letters) {
        if (letter.second < min)
            min = letter.second;
    }

    return min;
}

std::vector<std::pair<char, int>> sortLetters(std::map<char, int> letters) {


    int min = findMin(letters);

    std::vector<std::pair<char, int>> newOrder;

    bool isDone = true;
    while (letters.size()) {
        isDone = true;
        for (std::pair<char, int> letter : letters) {
            if (letter.second == min) {
                newOrder.push_back({ letter.first, letter.second });
                letters.erase(letter.first);
                isDone = false;
                break;
            }
        }
        if (isDone)
            min++;
    }

    return newOrder;
}

std::map<char, int> fillMap(std::string Text) {

    std::map<char, int> result;

    for (char letter : Text)
        result[letter]++;

    return result;
}

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->letter = NULL;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* createNode(int value, char letter) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->letter = letter;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* createHuffermanTree(std::vector<std::pair<char, int>> newOrder) {

    TreeNode* left = new TreeNode;
    TreeNode* right = new TreeNode;
    left = nullptr;



    while (newOrder.size() != 2) {

        if (newOrder[0].second <= newOrder[2].second) {

            if (left == nullptr)
                left = createNode(newOrder[0].second, newOrder[0].first);

            if (newOrder[1].first == NULL)
                right = createNode(newOrder[1].second);
            else
                right = createNode(newOrder[1].second, newOrder[1].first);


            TreeNode* newNode = new TreeNode;
            newNode->value = newOrder[0].second + newOrder[1].second;
            newNode->letter = NULL;
            newNode->left = left;
            newNode->right = right;
            left = newNode;

            newOrder.erase(newOrder.begin());
            newOrder.erase(newOrder.begin());
            newOrder.insert(newOrder.begin(), { left->letter, left->value });

        }
        else {
            TreeNode* newNode = new TreeNode;
            TreeNode* temporalLeft = new TreeNode;

            if (newOrder[1].first != NULL)
                temporalLeft = createNode(newOrder[1].second, newOrder[1].first);
            else
                temporalLeft = createNode(newOrder[1].second);

            if (newOrder[2].first != NULL)
                right = createNode(newOrder[2].second, newOrder[2].first);
            else
                right = createNode(newOrder[2].second);

            newNode->value = newOrder[1].second + newOrder[2].second;
            newNode->letter = NULL;
            newNode->left = temporalLeft;
            newNode->right = right;
            right = newNode;

            newOrder.erase(newOrder.begin() + 1);
            newOrder.erase(newOrder.begin() + 1);
            newOrder.insert(newOrder.begin(), { right->letter, right->value });
        }

    }

    TreeNode* newNode = new TreeNode;
    newNode->value = newOrder[0].second + newOrder[1].second;

    if (newOrder[1].first != NULL)
        right = createNode(newOrder[1].second, newOrder[1].first);

    newNode->letter = NULL;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}

void recursiv(TreeNode* head, std::map<char, std::string>& codeTable, std::string number) {
    if (head->letter != NULL) {
        codeTable.insert({ head->letter, number });
        return;
    }
    recursiv(head->left, codeTable, number + '0');
    recursiv(head->right, codeTable, number + '1');
}

std::map<char, std::string> createCodeTable(TreeNode* head) {
    std::string number;
    std::map<char, std::string> result;
    recursiv(head, result, number);
    return result;
}

std::string encode(std::map<char, std::string> codeTable, std::string Text) {
    std::string result;
    for (char letter : Text)
        result += codeTable.at(letter);

    return result;
}

void Hufferman() {

    std::cout << "Text : ";
    std::string Text;
    getline(std::cin, Text);

    std::map<char, int> letters = fillMap(Text);

    std::vector<std::pair<char, int>> newOrder = sortLetters(letters);

    TreeNode* Head = createHuffermanTree(newOrder);

    std::map<char, std::string> codeTable = createCodeTable(Head);

    std::string result = encode(codeTable, Text);

    std::cout << result;
}

int main()
{
    Hufferman();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
