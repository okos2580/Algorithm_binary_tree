#pragma once

typedef struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
} Node;

extern Node* makeTree();
extern void printTree(Node* root);
extern Node* findNode(int value, Node* root);
extern Node* insertLeftNode(Node* where, Node* new_node);
extern Node* insertRightNode(Node* where, Node* new_node);