#include <iostream>

#if false
const auto MAX_SIZE = 100;

int array[MAX_SIZE], length = 0;

void push(int value) {
	if (length == MAX_SIZE) {
		std::cout << "Lista este plina";
		return;
	}
	array[length++] = value;
}

void populate() {
	int size;
	std::cout << "Numarul de elemente: " << std::endl;
	std::cin >> size;

	int value;
	for (int i = 0; i < size; i++) {
		std::cin >> value;
		push(value);
	}
}

void display() {
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
}

void insert(int value, int pos) {
	if (length == MAX_SIZE) {
		std::cout << "Lista este plina";
		return;
	}

	for (int i = length++; i > pos; i--) {
		array[i] = array[i - 1];
	}

	if (pos == 0 && array[0] > value) array[0] = value;
	else if (array[pos] > value) {
		array[pos] = value;
	}
	else {
		array[pos + 1] = value;
	};
}

void insert(int value) {
	int left = 0, right = length - 1;

	while (left < right) {
		int middle = left + (right - left) / 2;
		if (array[middle] < value) left = middle + 1;
		else right = middle - 1;
	}

	std::cout << "left = " << left << " right = " << right << std::endl;

	insert(value, right);
}

int main() {
	populate();
	std::cout << "Introduceti valoarea:" << std::endl;
	std::cout << "k = ";
	int value = 7;
	std::cin >> value;
	insert(value);
	display();
}

#endif

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

	int size;
	std::cout << "Numarul de elemente: " << std::endl;
	std::cin >> size;

	int value;
	Node* temp, * itr = head;
	for (int i = 0; i < size; i++) {
		std::cin >> value;
		temp = new Node(value);
		itr->next = temp;
		itr = temp;
	}
}

void insert(Node* head, bool (*comparisonFn)(int, int)) {
	int value;
	std::cout << "Introduceti valoarea:" << std::endl;
	std::cout << "k = ";
	std::cin >> value;
	Node* itr = head;

	while (itr->next != NULL) {
		if (comparisonFn(itr->next->value, value)) {
			Node* temp = new Node(value);
			temp->next = itr->next;
			itr->next = temp;
			return;
		}
		itr = itr->next;
	}

	itr->next = new Node(value);
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
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool comparatorAscending(int x, int y) {
	return x > y;
}

bool comparatorDescending(int x, int y) {
	return x < y;
}

int main() {
	Node* list;

	bool (*comparisonFn)(int, int);
	int option;
	std::cout << "1 = crescator; 2 = descrescator" << std::endl;
	std::cin >> option;

	if (option == 1) {
		comparisonFn = comparatorAscending;
	}
	else {
		comparisonFn = comparatorDescending;
	}

	populate(list);
	insert(list, comparisonFn);
	display(list);
	clear(list);
}