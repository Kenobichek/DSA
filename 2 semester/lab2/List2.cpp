#include <iostream>
#include "MyHeading2.h"

using namespace std;

void DoublyLinkedList2::insert(HashNode2 Data) {
	Node2* newNode = new Node2();
	newNode->data = Data;
	newNode->next = NULL;
	newNode->parent = tail;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}

	else {
		Node2* currentNode = newNode;
		tail->next = newNode;
		tail = newNode;
	}

	quantity++;
}

HashNode2 DoublyLinkedList2::erase(string* remove) {
	Node2* currentNode = head;

	while (currentNode != NULL) {
		if (currentNode->data.key == *remove) {
			break;
		}
		currentNode = currentNode->next;
	}

	if (currentNode == NULL) {
		//cout << "there is no item with such a key\n";
		return { { '0',0, 0 }, "0" };
	}
	else {
		HashNode2 selected = currentNode->data;
		Node2* deleted = currentNode;

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

int DoublyLinkedList2::size() {
	return quantity;
}

void DoublyLinkedList2::print() {
	Node2* currentNode = head;
	while (currentNode != NULL) {
		//cout << currentNode->data.value.numberParticipants << " " << currentNode->data.value.pairNumber << " " << currentNode->data.value.teachersName << " " << currentNode->data.key << endl;
		currentNode = currentNode->next;
	}
}

Node2* DoublyLinkedList2::find(string* key) {
	Node2* currentNode = head;
	while (currentNode != NULL) {
		if (currentNode->data.key == *key) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}

void DoublyLinkedList2::replace(Node2* p, HashNode2 Data) {
	p->data = Data;
}