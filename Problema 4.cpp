#include <iostream>
#include <set>

struct ListNode {
    int value;
    ListNode* next;
};

#pragma region 4th problem static
void initiateArray(int* arr, int length, std::set<int>& values, int& newLength) {

    for (int i = 0; i < length; i++) {
        std::cin >> arr[i];
        if (values.find(arr[i]) == values.end())
            newLength++;
        values.insert(arr[i]);
    }
}

int * newUniqueArray(std::set<int> uniqueNumbers, int length) {
    int* arr = new int[length], index = 0;

    for (int value : uniqueNumbers)
        arr[index++] = value;

    return arr;
}

void readArray(int* arr, int length) {
    for (int i = 0; i < length; i++)
        std::cout << arr[i];
}

void Static() {
    int length;
    std::cin >> length;

    int* arr = new int[length];
    std::set<int> uniqueNumbers;
    int newLength = 0;

    initiateArray(arr, length, uniqueNumbers, newLength);
    int* newArr = newUniqueArray(uniqueNumbers, newLength);
    readArray(newArr, newLength);
}

#pragma endregion

#pragma region 4th problem Dinamic

ListNode* initiateList(int length, std::set<int>& value) {
    ListNode* Head = new ListNode;
    ListNode* secondHead = Head;

    while (length--) {
        secondHead->next = new ListNode;
        std::cin >> secondHead->next->value;
        value.insert(secondHead->next->value);
        secondHead = secondHead->next;
    }

    secondHead->next = nullptr;

    return Head->next;
}

void eliminateDublicates(ListNode* Head, std::set<int> value) {

    value.erase(Head->value);

    while (Head) {
        if (value.find(Head->next->value) == value.end()) {
            if (Head->next == nullptr) {
                Head->next == nullptr;
                break;
            }
            else
                Head->next = Head->next->next;
        }
        else {
            value.erase(Head->next->value);
            Head = Head->next;
        }
    }
}

void Dinamic() {
    int length;
    std::cin >> length;

    std::set<int> value;
    ListNode* List = initiateList(length, value);
    eliminateDublicates(List, value);

    while (List)
        std::cout << List->value, List = List->next;


}

#pragma endregion

int main() {

}