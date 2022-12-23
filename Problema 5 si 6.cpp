//#include <iostream>
//#include <set>
//
///*
//Problema 5:
//Să se creeze o listă circulară, simplu înlănţuită cu elementele 1, 2, …, n (n dat).
//Începând cu poziţia s, să se afişeze elementele din
//k în k până când primul element se repetă 
//(s si k de asemenea date).
//
//Problema 6:
//Să se creeze o listă circulară simplu înlănţuită cu elementele 1, 2, …, n (n dat).
//Începând cu poziţia s, să se afişeze elementele din
//k în k până când un element afişat se repetă
//(s si k de asemenea date)
//*/
//
//struct Node {
//	int value;
//	Node* next;
//	Node() {
//		value = NULL;
//		next = NULL;
//	}
//	Node(int value) {
//		Node::value = value;
//		next = NULL;
//	}
//};
//
//void populate(Node*& head) {
//	head = new Node();
//
//	int size;
//	std::cout << "n = ";
//	std::cin >> size;
//	if (size <= 0) {
//		abort();
//		return;
//	}
//	head->value = 1;
//	head->next = head;
//
//	Node* temp, * ultim = head;
//
//	for (int i = 2; i <= size; i++) {
//		temp = new Node(i);
//		ultim->next = temp;
//		temp->next = head;
//		ultim = temp;
//	}
//}
//
//
//// pentru problema 6
//#if false
//void display(Node* head) {
//	int pos, skip;
//	std::cout << "Pozitia: ";
//	std::cin >> pos;
//	std::cout << "k =  ";
//	std::cin >> skip;
//
//	for (int i = 1; i < pos; i++) head = head->next;
//
//	int step = 1;
//
//	std::set<int> s;
//
//	while (head) {
//		if (step % skip == 0) {
//			if (s.find(head->value) != s.end()) break;
//			std::cout << head->value << " ";
//			s.insert(head->value);
//		}
//		step++;
//		head = head->next;
//	}
//}
//#endif
//
//// pentru problema 5
//#if true
//void display(Node* head) {
//	int pos, skip;
//	std::cout << "Pozitia: ";
//	std::cin >> pos;
//	std::cout << "k =  ";
//	std::cin >> skip;
//
//	int stopValue = head->value;
//	int step = 1;
//
//	for (int i = 1; i < pos; i++) head = head->next;
//
//	while (head) {
//		if (step % skip == 0) {
//			if (head->value == stopValue) break;
//			std::cout << head->value << " ";
//		}
//		step++;
//		head = head->next;
//	}
//}
//#endif
//
//void clear(Node*& head) {
//	Node* temp;
//	Node* itr = head->next;
//	while (itr != head) {
//		temp = itr;
//		itr = itr->next;
//		delete temp;
//	}
//	delete head;
//}
//
//int main() {
//	Node* list;
//	populate(list);
//	display(list);
//	clear(list);
//}