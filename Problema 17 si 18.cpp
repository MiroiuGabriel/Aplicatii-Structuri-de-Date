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

int toNumber(char ch) {
	return ch - '0';
}

void populate(Node*& head, std::string number) {
	Node* temp;
	Node* tempHead = new Node();
	Node* itr = tempHead;

	for (int i = number.length() - 1; i >= 0; i--) {
		temp = new Node(toNumber(number[i]));
		itr->next = temp;
		itr = temp;
	}

	head = tempHead->next;
}

Node* sum(Node* left, Node* right) {
	Node* result = new Node();
	Node* itr = result;

	int carry = 0;

	while (left != NULL || right != NULL || carry != 0) {
		int x = left != NULL ? left->value : 0;
		int y = right != NULL ? right->value : 0;

		int sum = x + y + carry;

		Node* temp = new Node(sum % 10);

		itr->next = temp;

		itr = temp;

		carry = sum / 10;

		if (left != NULL) left = left->next;
		if (right != NULL) right = right->next;
	}

	return result->next;
}

Node* diff(Node* left, Node* right) {
	Node* result = new Node();
	Node* itr = result;

	int carry = 0;
	while (left != NULL && right != NULL || carry) {
		int x = left != NULL ? left->value : 0;
		int y = right != NULL ? right->value : 0;

		if (!(left != NULL || right != NULL || x || y) && carry) break;

		int difference = 0;

		if (carry == 0 && x >= y) {
			difference = x - y - carry;
			carry = 0;
		}
		else if (carry == 0 && x <= y) {
			difference = x - y - carry + 10;
			carry = 1;
		}
		else if (carry == 1 && x <= y) {
			difference = x - y - carry + 10;
			carry = 1;
		}


		Node* temp = new Node(difference);

		itr->next = temp;

		itr = temp;

		if (left != NULL) left = left->next;
		if (right != NULL) right = right->next;
	}

	return result->next;
}

void inverse(Node*& head) {
	Node* prev = NULL;
	Node* next;

	while ((next = head->next) != NULL) {
		head->next = prev;
		prev = head;
		head = next;
	}

	head->next = prev;
}

void display(Node* head) {
	if (head == NULL) {
		std::cout << "Lista este vida";
		return;
	}

	for (Node* itr = head; itr != NULL; itr = itr->next) std::cout << itr->value;
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
	std::string firstNumber;
	std::string secondNumber;

	std::cout << "Introduceti primul numar: ";
	std::cin >> firstNumber;
	std::cout << "Introduceti al doilea numar: ";
	std::cin >> secondNumber;

	Node* list1, * list2;

	populate(list1, firstNumber);
	populate(list2, secondNumber);

	Node* result = sum(list1, list2);
	std::cout << firstNumber << " + " << secondNumber << " = ";
	display(result); 

	clear(list1);
	clear(list2);
	clear(result);
}