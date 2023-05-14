#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"



//Node* root;

Node* createNode(int val)
{
	// 1. sizeof(Node)로 메모리 할당
	Node* pNode = (Node*)malloc(sizeof(Node));

	// 2. 초기화 n->value = val, left, right (NULL)
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	// 3. 만든 Node 객체(변수) 포인터 반환
	return pNode;
}



Node* connectChild(Node* parent, Node* left, Node* right)
{
	if (parent == NULL)
	{
		return NULL;
	}

	parent->left = left;
	parent->right = right;
}

Node* makeTree()
{
	Node* pRoot = NULL;
	Node* tleft = NULL;
	Node* tright = NULL;

	pRoot = createNode(100);
	tleft = createNode(200);
	tright = createNode(300);

	connectChild(pRoot, tleft, tright); //if문도 써야함 NULL 생각해서

	connectChild(tright, createNode(400), createNode(500));

	return pRoot;
}

void printTree(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("Node: %d, ", root->value);
	printTree(root->left);
	printTree(root->right);

}

Node* findNode(int value, Node* root) {
	if (root == NULL || root->value == value) {
		return root;
	}

	Node* foundNode = findNode(value, root->left);
	if (foundNode == NULL) {
		foundNode = findNode(value, root->right);
	}

	return foundNode;
}

Node* insertLeftNode(Node* where, Node* new_node) {
	if (where == NULL) {
		return NULL;
	}

	where->left = new_node;
	return where;
}

Node* insertRightNode(Node* where, Node* new_node) {
	if (where == NULL) {
		return NULL;
	}

	where->right = new_node;
	return where;
}

