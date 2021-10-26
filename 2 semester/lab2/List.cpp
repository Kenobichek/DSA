#include <iostream>
#include "MyHeading.h"

using namespace std;

void DoublyLinkedList::insert(HashNode Data) {
	Node* newNode = new Node();
	newNode->data = Data;
	newNode->next = NULL;
	newNode->parent = tail;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}

	else {
		Node* currentNode = newNode;
		tail->next = newNode;
		tail = newNode;
	}

	quantity++;
}

HashNode DoublyLinkedList::erase(long long remove) {
	Node* currentNode = head;

	while (currentNode != NULL) {
		if (currentNode->data.key == remove) {
			break;
		}
		currentNode = currentNode->next;
	}

	if (currentNode == NULL) {
		//cout << "there is no item with such a key\n";
		return { { '0',0, 0 }, 0 };
	}
	else {
		HashNode selected = currentNode->data;
		Node* deleted = currentNode;

		if (size() == 1) {
			head = NULL;
			tail = NULL;
		}

		else if (currentNode == head) {
			head = currentNode->next;
			head->parent = NULL;
		}

		else if (currentNode == tail) {
			tail = tail->parent;
			tail->next = NULL;
		}

		else {
			if (currentNode->parent != NULL) {
				currentNode->parent->next = currentNode->next;
			}
			

			if (currentNode->next != NULL) {
				currentNode->next->parent = currentNode->parent;
			}
			
		}
		quantity--;
		delete deleted;
		return selected;
	}
}

int DoublyLinkedList::size() {
	return quantity;
}

void DoublyLinkedList::print() {
	Node* currentNode = head;
	while (currentNode != NULL) {
		cout << currentNode->data.value.numberParticipants << " " << currentNode->data.value.pairNumber << " " << currentNode->data.value.teachersName << " " << currentNode->data.key << endl;
		currentNode = currentNode->next;
	}
}

Node* DoublyLinkedList::find(long long key) {
	Node* currentNode = head;
	while (currentNode != NULL) {
		if (currentNode->data.key == key) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}

void DoublyLinkedList::replace(Node* p, HashNode Data) {
	p->data = Data;
}