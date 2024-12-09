#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* createNode(int data){
	// Cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void insertEnd(Node** head, int value){
	// Tao node moi
	Node* newNode = createNode(value);
	Node* temp = *head;
	// Duyet
	if(*head == NULL){
		*head = newNode;
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void deleteEnd(Node** head){
	if(*head == NULL) return;
	
	Node* temp = *head;
	if(temp->next == NULL){
		free(temp);
		*head = NULL;
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->prev->next = NULL;
	free(temp);
}

void printList(Node* head){
	Node* temp = head;
	printf("NULL ");
	while(temp != NULL){
		printf("<--> %d ",temp->data);
		temp = temp->next;
	}
	printf("<--> NULL\n");
}


int main(){
	Node* head = NULL;
	
	insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

	printf("Danh sach nut ban dau: \n");
    printList(head);
    
    deleteEnd(&head);
	
	printf("Danh sach nut sau khi xoa: \n");
	printList(head); 
	return 0;
}
