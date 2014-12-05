#include <stdlib.h>
#include <stdio.h>

typedef struct listNode
{
	/* data */
	int value;
	struct listNode *next;

}listNode;

typedef struct list
{
	/* data */
	size_t size;
	listNode *head;
	listNode *tail;

}list;

int main(int argc, char const *argv[])
{
	list *alist = malloc(sizeof(list *));
	alist->head = NULL;
	alist->tail = NULL;
	alist->size = 0;

	int listSize = 5;
	
	for(int i = 1; i < listSize; i++){
		listNode *node = malloc(sizeof(listNode *));
		node->value = i;
		node->next = NULL;
		
		if(alist->head == NULL){	
			alist->head = node;
		}

		if(alist->tail == NULL){
			alist->tail = node;
		}else{
			alist->tail->next = node;
			alist->tail = node;
		}
		alist->size++;
	}

	listNode *node = alist->head;

	while(node){
		printf("%p, %d\n", node, node->value);
		listNode *preNode = node;
		node = node->next;
		free(preNode);

	}
	free(alist);

	return 0;

}