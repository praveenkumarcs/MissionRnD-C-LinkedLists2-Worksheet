/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#define and &&
#define or ||

struct node {
	int num;
	struct node *next;
};

typedef struct node *lptr;

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	lptr parent = NULL, child = NULL, tmp1 = NULL, tmp2 = NULL;

	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	if (head1->num > head2->num){
		tmp1 = head1;
		head1 = head2;
		head2 = tmp1;
	}

	parent = head1;
	child = head1->next;
	tmp1 = tmp2 = head2;

	while (child != NULL){

		while (tmp2->num >= parent->num and tmp2->num < child->num){
			tmp2 = tmp1->next;
			tmp1->next = parent->next;
			parent->next = tmp1;
			parent = parent->next;
			tmp1 = tmp2;
		}
		parent = parent->next;
		child = child->next;

	}
	if (tmp2 != NULL)
		parent->next = tmp2;

	return head1;
}
