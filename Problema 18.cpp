// Probleme Doamna Miroiu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0) {};
    ListNode(int x) : value(x) {}
};

struct NumberInformation {
    bool isPositive;
    int value;
};

void finishNumber(ListNode* Number, ListNode*& Head, bool carry) {
    while (Number) {
        if (Number->value < 0)
            Number->value = abs(Number->value);

        if (Number->value > 0)
            Head->next = new ListNode(Number->value - carry), carry = false;
        else
            Head->next = new ListNode(9);
        Head = Head->next;

        Number = Number->next;
    }
}

void reverse(ListNode* prev, ListNode* node) {
    if (node == nullptr)
        return;

    reverse(node, node->next);
    node->next = prev;

}

void removeZeros(ListNode*& Head) {
    while (Head->next) {
        if (Head->value == 0)
            Head = Head->next;
        else
            return;
    }
}


ListNode* additionCase(ListNode* firstNumber, ListNode* secondNumber, bool isNegative) {

    ListNode* resultHead = new ListNode;
    ListNode* Head = resultHead;

    while (firstNumber && secondNumber) {

        if (firstNumber->value < 0)
            firstNumber->value = abs(firstNumber->value);
        if (secondNumber->value < 0)
            secondNumber->value = abs(secondNumber->value);

        Head->next = new ListNode(firstNumber->value + secondNumber->value);
        Head = Head->next;

        firstNumber = firstNumber->next;
        secondNumber = secondNumber->next;
    }

    finishNumber(firstNumber, Head, 0);
    finishNumber(secondNumber, Head, 0);
    Head->next = nullptr;

    reverse(nullptr, resultHead->next);
    if (isNegative)
        Head->value = Head->value * -1;

    return Head;
}

ListNode* differeneSign(ListNode* firstNumber, ListNode* secondNumber, bool isNegative) {
    ListNode* resultHead = new ListNode;
    ListNode* Head = resultHead;
    bool carry = 0;

    while (firstNumber && secondNumber) {
        Head->next = new ListNode;


        if (firstNumber->value < 0)
            firstNumber->value = abs(firstNumber->value);
        if (secondNumber->value < 0)
            secondNumber->value = abs(secondNumber->value);

        if (secondNumber->value > firstNumber->value) {
            if (carry)
                Head->next->value = (10 - carry) + firstNumber->value - secondNumber->value;
            else
                Head->next->value = 10 + firstNumber->value - secondNumber->value, carry = true;
        }
        else {

            if (carry) {
                if (firstNumber->value - 1 >= secondNumber->value)
                    Head->next->value = (firstNumber->value - carry) - secondNumber->value, carry = false;
                else
                    Head->next->value = 9 + firstNumber->value - secondNumber->value;
            }
            else {
                Head->next->value = firstNumber->value - secondNumber->value;
            }
        }

        Head = Head->next;
        firstNumber = firstNumber->next;
        secondNumber = secondNumber->next;
    }

    finishNumber(firstNumber, Head, carry);

    Head->next = nullptr;
    reverse(nullptr, resultHead->next);
    removeZeros(Head);
    if (isNegative)
        Head->value = Head->value * -1;

    return Head;
}

ListNode* calculateNumber(ListNode* firstNumber, NumberInformation firstNumberInformation, ListNode* secondNumber, NumberInformation secondNumberInformation) {
    ListNode* result = new ListNode;


    if (firstNumberInformation.isPositive == false && secondNumberInformation.isPositive == true)
        result = additionCase(firstNumber, secondNumber, true);

    if (firstNumberInformation.isPositive == true && secondNumberInformation.isPositive == false)
        result = additionCase(firstNumber, secondNumber, false);

    if (firstNumberInformation.isPositive == false && secondNumberInformation.isPositive == false)
        if (firstNumberInformation.value > secondNumberInformation.value)
            result = differeneSign(secondNumber, firstNumber, false);
        else
            result = differeneSign(firstNumber, secondNumber, true);

    if (firstNumberInformation.isPositive == true && secondNumberInformation.isPositive == true)
        if (firstNumberInformation.value > secondNumberInformation.value)
            result = differeneSign(firstNumber, secondNumber, false);
        else
            result = differeneSign(secondNumber, firstNumber, true);


    return result;
}

void createListNumber(ListNode* List, NumberInformation& Number) {
    int number;
    std::cout << "Insert Your number : ";
    std::cin >> number;

    Number.value = number;

    while (number) {

        if (number / 10 == 0) {
            if (number > 0)
                Number.isPositive = true;
            else
                Number.isPositive = false;
        }

        List->next = new ListNode(number % 10);
        List = List->next;

        number = number / 10;
    }
    List->next = nullptr;
}

void Dinamic() {
    NumberInformation firstNumberInformation, secondNumberInformation;
    ListNode* firstNumber = new ListNode, * secondNumber = new ListNode;

    createListNumber(firstNumber, firstNumberInformation);
    firstNumber = firstNumber->next;

    createListNumber(secondNumber, secondNumberInformation);
    secondNumber = secondNumber->next;

    ListNode* result = calculateNumber(firstNumber, firstNumberInformation, secondNumber, secondNumberInformation);

    while (result)
        std::cout << result->value, result = result->next;

}

int main()
{
    Dinamic();
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
