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

// Them phan tu vao dau danh sach
void insertHead(Node** head, int value){
	// Tao node moi
	Node* newNode = createNode(value);
	newNode->next = *head;
	
	if(*head != NULL){
		(*head)->prev = newNode;
	}
	*head = newNode;
}

// Them phan tu vao cuoi danh sach
void insertEnd(Node** head, int value){
	Node* newNode = createNode(value);
	Node* temp = *head;
	
	if(*head == NULL){
		*head = newNode;
		return;
	}	
	
	// Tim phan tu cuoi
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

// Chen 1 phan tu vao vi tri bat ki
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

// Xoa phan tu tai vi tri bat ki
void deleteElement(Node** head, int position){
	Node* temp = *head;
	
	if(position == 0){
		*head = temp->next;
		if(*head != NULL){
			(*head)->prev = NULL;
		}
		free(temp);
		return;
	}
	
	for(int i=0; i<position && temp != NULL; i++){
		temp = temp->next;
	}
	
	if (temp == NULL) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    // Cap nhat con tro cua node truoc va node sau
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Giai phong bo nho cua node can xoa
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
	int value, position;
	do{
		printf("--------------------MENU-------------------\n");
		printf("1. Them 1 phan tu vao dau\n");
		printf("2. Xem danh sach\n");
		printf("3. Them 1 phan tu vao cuoi\n");
		printf("4. Them 1 phan tu vao vi tri bat ky\n");
		printf("5. Xoa 1 phan tu tai vi tri bat ky\n");
		printf("6. Thoat\n");
		printf("Moi nhap chon: ");
		
		int choice;
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Moi ban vao phan tu dau tien: ");
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2:
				printf("Danh sach node: \n");
				printList(head);
				break;
			case 3:
				printf("Moi ban vao phan tu can chen: ");
				scanf("%d", &value);
				insertEnd(&head, value);
				break;
			case 4:
				printf("Nhap vao vi tri can chen: ");
				scanf("%d", &position);
				printf("Moi ban vao phan tu can chen: ");
				scanf("%d", &value);
				insertElement(&head, value, position);
				break;
			case 5:
				printf("Nhap vao vi tri can xoa: ");
				scanf("%d", &position);
				deleteElement(&head, position);
				break;
			case 6:
				exit(0);
			default:
				printf("Vui long chon lai nhe");
		}
	}while(1==1);
	return 0;
}
