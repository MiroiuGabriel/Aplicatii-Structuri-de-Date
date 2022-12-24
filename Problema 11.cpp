#include <iostream>

struct Node {
	int value;
	Node* next;
	Node(int value) {
		Node::value = value;
		next = NULL;
	}
	Node() {
		value = NULL;
		next = NULL;
	}
};

void populate(Node*& head) {
	head = new Node();

	Node* itr = head;

	int size;
	std::cout << "Numar elemente: ";
	std::cin >> size;

	Node* temp;
	int value;

	for (int i = 0; i < size; i++) {
		std::cin >> value;
		temp = new Node(value);
		itr->next = temp;
		itr = temp;
	}

	head = head->next;
}

void clear(Node*& head) {
	Node* temp;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

Node* cartesianProduct(Node* list1, Node* list2) {
	Node* result = new Node();

	Node* itr = result;

	while (list1) {
		int currValue = list1->value;
		Node* currNode = list2;

		Node* temp;

		while (currNode) {
			temp = new Node(currValue);
			temp->next = new Node(currNode->value);
			itr->next = temp;
			itr = temp->next;
			currNode = currNode->next;
		}

		list1 = list1->next;
	}

	return result->next;
}

void displayCartesianProduct(Node* head) {
	std::cout << "{ ";
	while (head) {
		std::cout << "(" << head->value << ",";
		std::cout << head->next->value << "), ";
		head = head->next->next;
	}
	std::cout << "\b\b" << " }";

}

int main() {
	Node* list1, * list2;

	std::cout << "Citire lista 1:" << std::endl;
	populate(list1);
	std::cout << "Citire lista 2:" << std::endl;
	populate(list2);

	Node* result = cartesianProduct(list1, list2);
	displayCartesianProduct(result);

	clear(list1);
	clear(list2);
	clear(result);
}