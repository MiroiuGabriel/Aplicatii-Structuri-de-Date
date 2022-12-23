
#include <iostream>
#include <set>

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* initiateList(int length) {
    ListNode* Head = new ListNode;
    ListNode* secondHead = Head;

    while (length--) {
        secondHead->next = new ListNode;
        std::cin >> secondHead->next->value;
        secondHead = secondHead->next;
    }

    secondHead->next = nullptr;

    return Head->next;
}

bool isPrime(int number) {

    for (int i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}

void fillHeads(ListNode* Head, ListNode* primeHead, ListNode* normalHead) {
    

    while (Head) {

        if (isPrime(Head->value)) {
            primeHead->next = new ListNode;
            primeHead->next->value = Head->value;
            primeHead = primeHead->next;
        }
        else {
            normalHead->next = new ListNode;
            normalHead->next->value = Head->value;
            normalHead = normalHead->next;
        }

        Head = Head->next;
    }

    primeHead->next = nullptr;
    normalHead->next = nullptr;

}

void Dinamic() {
    int firstLength;
    std::cin >> firstLength;

    ListNode* Head = initiateList(firstLength);

    ListNode* primeHead = new ListNode, * normalHead = new ListNode;
    
    fillHeads(Head, primeHead, normalHead);
    primeHead = primeHead->next, normalHead = normalHead->next;

    while (primeHead)
        std::cout << primeHead->value << " ", primeHead = primeHead->next;
    std::cout << std::endl;
    
    while(normalHead)
        std::cout << normalHead->value << " ", normalHead = normalHead->next;
}

int main() {

}