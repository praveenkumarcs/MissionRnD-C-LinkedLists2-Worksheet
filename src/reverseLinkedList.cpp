/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node *lptr;



struct node * reverseLinkedList(struct node *head) {
	lptr tmp1,tmphead = NULL,newhead = NULL;
	
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	tmp1 = head;
	tmphead = head->next;
	while (tmphead != NULL){
		if (newhead == NULL){
			newhead = tmp1;
			newhead->next = NULL;
		}
		else{
			tmp1 = tmphead;
			tmphead = tmphead->next;
			tmp1->next = newhead;
			newhead = tmp1;
		}
	}

	return newhead;
}
