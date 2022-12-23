#include <iostream>
#include <set>

struct ListNode {
    int value;
    ListNode* next;
};

#pragma region dinamic

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

ListNode* addNewElement(ListNode* Head, int newElement) {

    if (Head->value > newElement) {
        ListNode* newNode = new ListNode;
        newNode->value = newElement;
        newNode->next = Head;
        Head = newNode;
        return Head;
    }

    ListNode* firstHead = Head;

    while (Head->next) {
        if (Head->next->value > newElement) {
            ListNode* newNode = new ListNode;
            newNode->value = newElement;
            newNode->next = Head->next;
            Head->next = newNode;
            return firstHead;
        }
        Head = Head->next;
    }

    if (newElement > Head->value) {
        ListNode* newNode = new ListNode;
        newNode->value = newElement;
        Head->next = newNode;
        newNode->next = nullptr;
        return firstHead;
    }


    return firstHead;
}

void Dinamic() {
    int length;
    std::cin >> length;

    ListNode* List = initiateList(length);

    int newElement;
    std::cin >> newElement;

    List = addNewElement(List, newElement);

    while (List)
        std::cout << List->value, List = List->next;

}

#pragma endregion

int main(){

{
