#include <iostream>

struct Node {
	float power;
	float coefficient;
	Node* next;
	Node() {
		next = NULL;
		power = NULL;
		coefficient = NULL;
	}
	Node(float power, float coefficient) {
		Node::power = power;
		Node::coefficient = coefficient;
		next = NULL;
	}
};

void populateAndDerive(Node*& head) {
	head = new Node();

	int size;
	std::cout << "Numarul de variabile: ";
	std::cin >> size;
	Node* temp, * itr = head;

	for (int i = 0; i < size; i++) {
		temp = new Node();
		std::cout << "Coeficient: ";
		std::cin >> temp->coefficient;
		std::cout << "Putere: ";
		std::cin >> temp->power;

		std::cout << temp->coefficient << "x^" << temp->power << std::endl;

		if (temp->power == 0) continue;

		//derive
		temp->coefficient *= temp->power;
		temp->power--;

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

void display(Node* head) {
	if (head == NULL) {
		std::cout << "Polinomul este derivat complet";
	}

	int k = 0;
	for (Node* itr = head; itr != NULL; itr = itr->next) {
		if (k == 0 && itr->power == 0) { std::cout << itr->coefficient; k++; }
		else if (k == 0) {
			std::cout << itr->coefficient << "x^" << itr->power;
			k++;
		}
		else if (itr->power == 0 && itr->coefficient > 0) std::cout << "+" << itr->coefficient;
		else if (itr->power == 0) std::cout << itr->coefficient;
		else if (itr->coefficient > 0) std::cout << "+" << itr->coefficient << "x^" << itr->power;
	}
}

int main() {
	Node* list;
	populateAndDerive(list);
	display(list);
	clear(list);
}