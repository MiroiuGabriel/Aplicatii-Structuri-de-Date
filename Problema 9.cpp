//#include <iostream>
//
///*
//Să se creeze o listă ce conţine elementele prime până la un n dat,
//folosind reprezentare statică, respectiv dinamică.
//*/
//
//bool isPrime(int num) {
//	if (num < 2) return false;
//	if (num == 2) return true;
//	if (num % 2 == 0) return false;
//
//	for (int d = 3; d * d <= num; d += 2) {
//		if (num % d == 0) return false;
//	}
//
//	return true;
//}
//
//
//// Lista statica
//#if false
//
//const auto MAX_SIZE = 100;
//
//int array[MAX_SIZE], length = 0;
//
//void push(int value) {
//	if (length >= MAX_SIZE) {
//		std::cout << "Nu mai este spatiu pentru inserare";
//		return;
//	}
//	array[length++] = value;
//}
//
//void populateWithPrimes(int num) {
//	for (int i = 2; i <= num; i++) {
//		if (isPrime(i)) push(i);
//	}
//}
//
//void display() {
//	if (length == 0) {
//		std::cout << "Lista este vida";
//		return;
//	}
//	for (int i = 0; i < length; i++) std::cout << array[i] << " ";
//}
//
//int main() {
//	int num;
//	std::cout << "n = ";
//	std::cin >> num;
//	populateWithPrimes(num);
//	display();
//}
//
//#endif
//
//
//// Lista dinamica
//#if true
//
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
//void populateWithPrimes(Node*& head) {
//	head = new Node(2);
//	Node* itr = head;
//
//	int size;
//
//	std::cout << "n = ";
//	std::cin >> size;
//
//	Node* temp;
//	for (int i = 3; i <= size; i++) {
//		if (isPrime(i)) {
//			temp = new Node(i);
//			itr->next = temp;
//			itr = temp;
//		}
//	}
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
//	while (head) {
//		temp = head;
//		head = head->next;
//		delete temp;
//	}
//}
//
//int main() {
//	Node* list;
//	populateWithPrimes(list);
//	display(list);
//	clear(list);
//}
//#endif