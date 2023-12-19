#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


struct Node {
	int data;
	struct Node* next;
};


struct Node* first = NULL;


void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* ptr = first;
	int res = 0;
	while (ptr != NULL) {
		res += ptr->data;
		ptr = ptr->next;
	}
	return res;
}

int numEvens() {
	struct Node* ptr = first;
	int res = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			res++;
		}
		ptr = ptr->next;
	}
	return res;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
	}
}

void I_elemX10(int index) { // элемент i х100
	struct Node* ptr = first;
	int i = 0;
	while (ptr != NULL) {
		if (i == index) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		i++;
	}
}

void leftX10(int index) { // x10 левее i
	struct Node* ptr = first;
	int i = 0;
	while (ptr != NULL) {
		if (i != index) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		i++;
		if (i == index) {
			return;
		}
	}
}

void rightX10(int index) { // x10 правее i
	struct Node* ptr = first;
	int i = 0;
	while (ptr != NULL) {
		if (i > index) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		i++;
	}
}

void deleteElem(int index) {
	if (first == NULL) {
		return;
	}
	if (index == 0) {
		deleteFromHead();
		return;
	}

	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int i = 1;
	while (ptr != NULL) {
		if (i - 1 >= index) {
			prev_ptr->data = ptr->data;
		}
		if (ptr->next == NULL) {
			prev_ptr->next = NULL;
			free(ptr);
			return;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
		i++;
	}
}


int main()
{
	addToHead(1);
	addToHead(2);
	addToHead(3);
	addToHead(8);
	addToHead(9);
	printList();

	printf("sum = %d\n", sum());
	printf("evens - %d\n", numEvens());

	deleteElem(2);
	printList();

	/*oddsX10();
	printList();

	I_elemX10(3);
	I_elemX10(1);
	printList();

	leftX10(4);
	printList();

	rightX10(2);
	printList();*/
}


