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

void replaceNode(Node* head, int currentValue, int newValue){
	Node* temp = head;
	int found = 0;
	
	while(temp != NULL){
		if(temp->data == currentValue){
			temp->data = newValue;
			found = 1;
		}
		temp = temp->next;
	}
	
	if(!found){
		printf("Khong tim thay phan tu can thay the!\n");
	}
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
	int currentValue, newValue;
	
	insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

	printf("Danh sach nut ban dau: \n");
    printList(head);
    
	printf("Nhap gia tri can thay the: ");
	scanf("%d", &currentValue);
	
	printf("Nhap gia tri thay the: ");
	scanf("%d", &newValue);
	
	replaceNode(head, currentValue, newValue);
	
	printf("Danh sach nut sau khi thay the: \n");
    printList(head);
	return 0;
}
