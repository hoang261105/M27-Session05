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
}

void insertElement(Node** head, int value, int position){
	Node* newNode = createNode(value);
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node* temp = *head;
	
	for(int i=0; temp != NULL && i<position - 1; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
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
	int position;
	int value;
	
	insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

	printf("Danh sach nut ban dau: \n");
    printList(head);
    
   	printf("Nhap vi tri can chen: ");
	scanf("%d", &position);
	printf("Nhap gia tri can chen: ");
	scanf("%d", &value);
	
	insertElement(&head, value, position);
	
	printf("Danh sach nut sau khi chen: \n");
	printList(head); 
	return 0;
}
