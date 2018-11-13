#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node 
{
	int data; 
	struct node *next; 
}; 

void dump(struct node *node) {
	if(node == NULL){
		printf("empty\n");
	}
	while (node != NULL) {
		printf("%d", node->data);
		node = node->next;
		if(node != NULL){
			printf(" ");
		} else{
			printf("\n");
		}
	}
}

void append(struct node** head, int data) {
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	struct node *last = *head;
	temp->data  = data;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
		return;
	}

	while (last->next != NULL)
		last = last->next; 
 
	last->next = temp;
	return; 
}


void bubblesort(struct node** head, int len) {
	struct node *p;
	struct node *q;
	int t;
	p=q = *head;
	q = q->next;

	for(int i = 0; i<len-1; i++){
		for(int j=0; j<len-i-1; j++){
			if(q->data > p->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
			p = p->next;
			q = q->next;
		}
		p=q = *head;
		q = q->next;
	}

}


int main(void) {
	struct node* head = NULL;
	int N, len;
	char str[1000];
	int num[1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
		append(&head, num[i]);
	}
	bubblesort(&head, N);
	dump(head);
}
