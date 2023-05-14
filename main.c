#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

int main(int argc, char* argv[])
{
	printf("Hello World\n");

	Node* root = makeTree();
	printTree(root);

	int valueToFind = 400;
	Node* foundNode = findNode(valueToFind, root);
	if (foundNode != NULL) {
		printf("\nFound Node with value %d\n", valueToFind);
	}
    else {
        printf("\nNode with value %d not found\n", valueToFind);
    }

    // Insert a new node
    Node* newNode = createNode(600);
    Node* where = foundNode; // Insert the new node to the right of the found node
    Node* updatedNode = insertRightNode(where, newNode);
    if (updatedNode != NULL) {
        printf("\nNew node with value %d inserted to the right of the node with value %d\n", newNode->value, where->value);
    }
    else {
        printf("\nFailed to insert new node\n");
    }

    return 0;
}