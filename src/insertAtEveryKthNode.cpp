/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

#define and &&
#define or ||

struct node {
	int num;
	struct node *next;
};

typedef struct node *lptr;

struct node * insertAtEveryKthNode(struct node *head, int K) {

	lptr ptr = NULL,tmp = NULL;
	int k,nodes = 0;
	if (head == NULL or K < 0)
		return NULL;
	tmp = head;
	while (tmp != NULL){
		tmp = tmp->next;
		nodes++;
	}

	if (K > nodes)
		return head;

	k = 1;
	tmp = head;
	while (tmp != NULL){
		while (k++ != K and tmp != NULL)
			tmp = tmp->next;

		if (tmp != NULL){
			ptr = (lptr)malloc(sizeof(struct node));
			ptr->num = K;
			ptr->next = tmp->next;
			tmp->next = ptr;
			tmp = tmp->next->next;
			k = 1;
		}
	}
	return head;
}
