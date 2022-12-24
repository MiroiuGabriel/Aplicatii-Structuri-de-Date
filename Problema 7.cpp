#include <iostream>

struct Node {
	int value;
	Node* next;
	Node* prev;

	Node(int value) {
		Node::value = value;
		next = NULL;
		prev = NULL;
	}
	Node() {
		value = NULL;
		next = NULL;
		prev = NULL;
	}
};
 
void populate(Node*& head) {
	Node* temp;
	Node* tempHead = new Node();
	Node* itr = tempHead;

	int size;
	std::cout << "n = ";
	std::cin >> size;

	for (int i = 1; i <= size; i++) {
		temp = new Node(i);
		temp->prev = itr;
		itr->next = temp;
		itr = temp;
	}

	head = tempHead->next;
	head->prev = NULL;
}

void displayLeftRight(Node* head) {
	if (head == NULL) {
		std::cout << "Lista este vida";
		return;
	}
	Node* tail = NULL;

	for (Node* itr = head; itr != NULL; itr = itr->next) {
		tail = itr;
		std::cout << itr->value << " ";
	};

	std::cout << std::endl;

	for (Node* itr = tail; itr != NULL; itr = itr->prev) {
		std::cout << itr->value << " ";
	};
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
	Node* list;
	populate(list);
	displayLeftRight(list);
	clear(list);
}