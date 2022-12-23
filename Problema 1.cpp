//
//#include <iostream>
//#include <set>
//
//struct ListNode {
//    int value;
//    ListNode* next;
//};
//
//void initiateArray(int* firstArr, int firstLength, int* secondArr, int secondLength) {
//
//    for (int i = 0; i < firstLength; i++)
//        std::cin >> firstArr[i];
//
//    for (int i = 0; i < secondLength; i++)
//        std::cin >> secondArr[i];
//
//}
//
//std::set<int> fillSet(int* firstArr, int firstLength) {
//
//    std::set<int> result;
//
//    for (int i = 0; i < firstLength; i++)
//        result.insert(firstArr[i]);
//    
//    return result;
//}
//
//void findCommonElements(int* secondArr, int secondLength, std::set<int> values) {
//
//    for (int i = 0; i < secondLength; i++)
//        if (values.find(secondArr[i]) != values.end())
//            std::cout << secondArr[i];
//}
//
//void Static() {
//    int firstLength, secondLength;
//    std::cin >> firstLength >> secondLength;
//
//    int* firstArr = new int[firstLength], *secondArr = new int[secondLength];
//
//    initiateArray(firstArr, firstLength, secondArr, secondLength);
//
//    std::set<int> values = fillSet(firstArr, firstLength);
//
//    findCommonElements(secondArr, secondLength, values);
//
//}
//
//ListNode* initiateList(int length) {
//    ListNode* Head = new ListNode;
//    ListNode* secondHead = Head;
//
//    while (length--) {
//        secondHead->next = new ListNode;
//        std::cin >> secondHead->next->value;
//        secondHead = secondHead->next;
//    }
//
//    secondHead->next = nullptr;
//
//    return Head->next;
//}
//
//void Dinamic() {
//    int firstLength, secondLength;
//    std::cin >> firstLength >> secondLength;
//
//    ListNode* firstHead = initiateList(firstLength);
//    ListNode* secondHead = initiateList(secondLength);
//    
//    std::set<int> values;
//    while (firstHead)
//        values.insert(firstHead->value), firstHead = firstHead->next;
//
//    while (secondHead) {
//        if (values.find(secondHead->value) != values.end())
//            std::cout << secondHead->value;
//        secondHead = secondHead->next;
//    }
//}
//
//int main() {
//
//}