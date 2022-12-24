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

void eliminateNumber(Node* head, int target) {
	while (head->next != NULL) {
		if (head->next->value % target == 0 && head->next->value != target) {
			Node* temp = head->next;
			head->next = temp->next;
			delete temp;
		}
		else head = head->next;
	}
}

void eratostene(Node*& head, int number) {
	for (int i = 2; i <= number; i++) {
		eliminateNumber(head, i);
	}
}

void populate(Node*& head, int number) {
	head = new Node();

	Node* temp;
	Node* itr = head;

	for (int i = 2; i <= number; i++) {
		temp = new Node(i);
		itr->next = temp;
		itr = temp;
	}
}

void display(Node* head) {
	if (head == NULL) {
		std::cout << "Lista este vida";
		return;
	}

	for (Node* itr = head->next; itr != NULL; itr = itr->next) std::cout << itr->value << " ";
}

void clear(Node*& head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	int number;
	std::cout << "n= ";
	std::cin >> number;

	Node* list;
	populate(list, number);
	eratostene(list, number);
	display(list);
	clear(list);
}