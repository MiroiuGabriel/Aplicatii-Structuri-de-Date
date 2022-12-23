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
    Head = Head->next;
    secondHead->next = Head;

    return Head;
}

void goToPosition(ListNode*& List, int length) {
    while (length--)
        List = List->next;
}

void untilRepeat(ListNode* List, int step) {
    std::set<int> value;

    while (List) {
        if (value.find(List->value) == value.end()) {
            value.insert(List->value);
            std::cout << List->value << " ";
            goToPosition(List, step);
        }
        else
            break;
    }
}

void Dinamic() {

    int length, startPosition, step;
    std::cin >> length;

    ListNode* List = initiateList(length);
    std::cin >> startPosition;
    goToPosition(List, startPosition);
    std::cin >> step;
    untilRepeat(List, step);
}

int main()
{

}