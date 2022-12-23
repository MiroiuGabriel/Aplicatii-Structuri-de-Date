//#include <iostream>
///*
//Fie două liste sortate crescător (reprezentare statică, respectiv dinamică).
//Din cele două să se creeze o nouă listă cu elementele sortate crescător.
//*/
//
//bool comparatorAscending(int x, int y) {
//	return x < y;
//}
//
//bool comparatorDescendings(int x, int y) {
//	return x > y;
//}
//
//#if false
//
//const auto MAX_SIZE = 100;
//
//void push(int arr[MAX_SIZE], int& length, int value) {
//	if (length >= MAX_SIZE) {
//		std::cout << "Nu mai este spatiu pentru inserare";
//		return;
//	}
//	arr[length++] = value;
//}
//
//void populate(int arr[MAX_SIZE], int& length) {
//	int numberOfElements;
//	std::cout << "Numarul de elemente: ";
//	std::cin >> numberOfElements;
//
//	int value;
//	for (int i = 0; i < numberOfElements; i++) {
//		std::cin >> value;
//		push(arr, length, value);
//	}
//}
//
//void display(int arr[MAX_SIZE], int& length) {
//	if (length == 0) {
//		std::cout << "Lista este vida";
//		return;
//	}
//
//	for (int i = 0; i < length; i++) {
//		std::cout << arr[i] << " ";
//	}
//}
//
//void merge(int arr1[MAX_SIZE], int arr2[MAX_SIZE], int arr3[MAX_SIZE], int m, int n, int& p, bool (*comparisonFcn)(int, int)) {
//	int i = 0, j = 0;
//
//	while (i < m && j < n) {
//		if (comparisonFcn(arr1[i], arr2[j])) {
//			arr3[p++] = arr1[i++];
//		}
//		else {
//			arr3[p++] = arr2[j++];
//		}
//	}
//
//	while (i < m) {
//		arr3[p++] = arr1[i++];
//	}
//
//	while (j < n) {
//		arr3[p++] = arr2[j++];
//	}
//}
//
//int main() {
//	int arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE], m = 0, n = 0, p = 0;
//
//	bool (*comparisonFcn)(int, int);
//
//	std::cout << "1 = crescator; 2 = descrescator" << std::endl;
//	int option;
//	std::cin >> option;
//	std::cout << "Cititi Lista 1: " << std::endl;
//	populate(arr1, m);
//	std::cout << "Cititi Lista 2: " << std::endl;
//	populate(arr2, n);
//
//	if (option == 1) {
//		std::cout << "Lista sortata crescator:" << std::endl;
//		comparisonFcn = comparatorAscending;
//	}
//	else {
//		std::cout << "Lista sortata descrescator:" << std::endl;
//		comparisonFcn = comparatorDescendings;
//	}
//
//	merge(arr1, arr2, arr3, m, n, p, comparisonFcn);
//	display(arr3, p);
//}
//
//#endif
//
//#if true
//struct Node {
//	int value;
//	Node* next;
//	Node(int value) {
//		Node::value = value;
//		next = NULL;
//	}
//	Node() {
//		value = NULL;
//		next = NULL;
//	}
//};
//
//void populate(Node*& head) {
//	head = new Node();
//	Node* itr = head;
//
//	std::cout << "Numarul de elemente: ";
//	int size;
//	std::cin >> size;
//
//	Node* temp;
//	int value;
//	for (int i = 0; i < size; i++) {
//		std::cin >> value;
//		temp = new Node(value);
//		itr->next = temp;
//		itr = temp;
//	}
//
//	head = head->next;
//}
//
//void display(Node* head) {
//	if (head == NULL) {
//		std::cout << "Lista este vida";
//		return;
//	}
//	for (Node* itr = head; itr != NULL; itr = itr->next) std::cout << itr->value << " ";
//}
//
//void clear(Node*& head) {
//	Node* temp;
//	while (head != NULL) {
//		temp = head;
//		head = head->next;
//		delete temp;
//	}
//}
//
//Node* merge(Node* list1, Node* list2, bool (*comparisonFcn)(int, int)) {
//	Node* mergedList = new Node();
//	Node* itr = mergedList;
//
//	while (list1 && list2) {
//		int x = list1->value;
//		int y = list2->value;
//
//		Node* temp = new Node();
//
//		if (comparisonFcn(x, y)) {
//			temp->value = x;
//			list1 = list1->next;
//		}
//		else {
//			temp->value = y;
//			list2 = list2->next;
//		}
//		itr->next = temp;
//		itr = temp;
//	}
//
//	if (list1) itr->next = list1;
//	if (list2) itr->next = list2;
//
//	return mergedList->next;
//}
//
//int main() {
//	Node* list1, * list2;
//
//	std::cout << "1 = crescator; 2 = descrescator" << std::endl;
//	int option;
//	std::cin >> option;
//
//	std::cout << "Cititi Lista 1: " << std::endl;
//	populate(list1);
//	std::cout << "Cititi Lista 2: " << std::endl;
//	populate(list2);
//
//	bool (*comparisonFcn)(int, int);
//
//	if (option == 1) {
//		std::cout << "Lista sortata crescator:" << std::endl;
//		comparisonFcn = comparatorAscending;
//	}
//	else {
//		std::cout << "Lista sortata descrescator:" << std::endl;
//		comparisonFcn = comparatorDescendings;
//	}
//
//	Node* merged = merge(list1, list2, comparisonFcn);
//	display(merged);
//
//	clear(list1);
//	clear(list2);
//}
//#endif