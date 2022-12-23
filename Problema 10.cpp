struct ListNode {
    int value;
    ListNode* next;
};

#pragma region static

void initiateArr(int* arr, int length) {
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];
}

void Swich(int*& firstArr, int*& secondArr, int& firstLength, int& secondLength) {
    int* temporal = firstArr;
    firstArr = secondArr;
    secondArr = temporal;

    int temporalLength = firstLength;
    firstLength = secondLength;
    secondLength = temporalLength;
}

bool isIncludedStatic(int* firstArr, int firstLength, int* secondArr, int secondLength) {
    
    int index = 0;
    int numberOfElements = 0;
    for (int i = 0; i < firstLength; i++) {
        if (firstArr[i] == secondArr[index]) {

            numberOfElements++;
            index++;
            if (secondLength == index && numberOfElements == secondLength)
                return true;
        }
        else {
            index = 0;
            numberOfElements = 0;
            if (firstArr[i] == secondArr[index])
                index = 1, numberOfElements = 1;
        }
    }

    return false;
}

void Static() {
    int firstLength, secondLength;

    std::cin >> firstLength;
    int* firstArr = new int[firstLength];
    initiateArr(firstArr, firstLength);

    std::cin >> secondLength;
    int* secondArr = new int[secondLength];
    initiateArr(secondArr, secondLength);

    if (secondLength > firstLength)
        Swich(firstArr, secondArr, firstLength, secondLength);


    std::cout << isIncludedStatic(firstArr, firstLength, secondArr, secondLength);
}

#pragma endregion

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

void swich(ListNode*& firstList, ListNode*& secondList, int& firstLength, int& secondLength) {
    ListNode* temporal = firstList;
    firstList = secondList;
    secondList = temporal;

    int temporalLength = firstLength;
    firstLength = secondLength;
    secondLength = temporalLength;
}

bool isIncludedDinamic(ListNode* firstList, ListNode* secondList, int firstLength, int secondLength) {

    ListNode* secondListTemporal = secondList;
    int numberOfElements = 0;

    while (firstList) {
        if (firstList->value == secondListTemporal->value) {
            numberOfElements++;
            if (numberOfElements == secondLength)
                return true;
            firstList = firstList->next;
            secondListTemporal = secondListTemporal->next;
        }
        else {

            numberOfElements = 0;
            secondListTemporal = secondList;
            if (firstList->value == secondListTemporal->value)
                numberOfElements = 1, secondListTemporal = secondListTemporal->next;
            firstList = firstList->next;
        }
    }
    return false;
}

void Dinamic() {
    int firstLength, secondLength;

    std::cin >> firstLength;
    ListNode* firstList = initiateList(firstLength);

    std::cin >> secondLength;
    ListNode* secondList = initiateList(secondLength);

    if (firstLength < secondLength)
        swich(firstList, secondList, firstLength, secondLength);

    std::cout << isIncludedDinamic(firstList, secondList, firstLength, secondLength);
}
#pragma endregion
int main()
{

}