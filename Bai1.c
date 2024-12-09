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

void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printReverseList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    // Di chuyen den phan tu cuoi cung
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Duyet nguoc tu cuoi ve dau
    printf("Danh sach in nguoc: NULL ");
    while (temp != NULL) {
        printf("<--> %d ", temp->data);
        temp = temp->prev;
    }
    printf("<--> NULL\n");
}


int main(){
	Node* head = NULL;
	
	insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printReverseList(head);
	return 0;
}
