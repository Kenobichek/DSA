#include <iostream>
#include <algorithm>
#include "AVL.h"

using namespace std;

Node* AVLTree::smallLeftRotate(Node* node) {
	Node* R = node->RightChild;
	Node* RL = R->LeftChild;

	R->LeftChild = node;
	node->RightChild = RL;

	R->height = 1 + max(height(R->LeftChild), height(R->RightChild));
	node->height = 1 + max(height(node->LeftChild), height(node->RightChild));
	return R;
}

Node* AVLTree::smallRightRotate(Node* node) {
	Node* L = node->LeftChild;
	Node* LR = L->RightChild;

	L->RightChild = node;
	node->LeftChild = LR;

	L->height = 1 + max(height(L->LeftChild), height(L->RightChild));
	node->height = 1 + max(height(node->LeftChild), height(node->RightChild));

	return L;
}

bool AVLTree::insert(const Data& value) {
	Node* added = findNode(value, root);
	if (added != NULL) {
		return false;
	}

	root = addNode(value, root);

	return true;
}

Node* AVLTree::addNode(const Data& value, Node* node) {
	if (node == NULL) {
		node = new Node;
		node->data = value;
		node->LeftChild = NULL;
		node->RightChild = NULL;
		node->height = 1;
	}

	if (value < node->data) {
		node->LeftChild = addNode(value, node->LeftChild);
	}

	else if (value > node->data) {
		node->RightChild = addNode(value, node->RightChild);
	}

	node->height = 1 + max(height(node->LeftChild), height(node->RightChild));

	int heightDifference = height(node->RightChild) - height(node->LeftChild);

	if (heightDifference > 1 && node->RightChild != NULL && value > node->RightChild->data) {
		return smallLeftRotate(node);
	}

	if (heightDifference > 1 && node->RightChild != NULL && value < node->RightChild->data) {
		node->RightChild = smallRightRotate(node->RightChild);
		return smallLeftRotate(node);
	}

	if (heightDifference < -1 && node->LeftChild != NULL && value < node->LeftChild->data) {
		return smallRightRotate(node);
	}

	if (heightDifference < -1 && node->LeftChild != NULL && value > node->LeftChild->data) {
		node->LeftChild = smallLeftRotate(node->LeftChild);
		return smallRightRotate(node);
	}

	return node;
}

int AVLTree::height(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(node->LeftChild), height(node->RightChild));
	}
}

bool AVLTree::find(const Data& value) {
	return (findNode(value, root) != NULL) ? 1 : 0;
}

Node* AVLTree::findNode(const Data& value, Node* node) {
	if (node == NULL) {
		return NULL;
	}
	else {
		if (value > node->data) {
			return findNode(value, node->RightChild);
		}
		else if (value < node->data) {
			return findNode(value, node->LeftChild);
		}
		else {
			return node;
		}
	}
	return NULL;
}

void AVLTree::print() {
	printTree(root);
}

void AVLTree::printTree(Node* node) {
	if (node != NULL) {
		printTree(node->LeftChild);
		cout << node->data.nickname << " " << node->data.rank << " " << node->data.amountOfExperience << " " << node->data.sizeDonut << " " << node->height <<endl;
		printTree(node->RightChild);
	}
}