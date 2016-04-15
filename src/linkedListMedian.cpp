/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

#define and &&
#define or ||

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	struct node *parent = NULL, *child = NULL;

	if (head == NULL)
		return -1;

	parent = head;
	child = head->next;

	while (child != NULL and child->next != NULL){
		parent = parent->next;
		child = child->next->next;
	}

	if (child == NULL)
		return parent->num;
	else
		return (parent->num + parent->next->num) / 2;

}
