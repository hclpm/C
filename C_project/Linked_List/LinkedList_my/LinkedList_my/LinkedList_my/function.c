#include "function.h"

//head��� ����, list �����Ϳ� ����
node* initList(list* pList) {
	node* head = malloc(sizeof(node));
	head->data = -1;
	head->next = NULL;
	pList->nodeLoc = head;
}
//����Ʈ�� �Է¹޾� ��� ��ü ���
void printList(list* pList) {
	node* ptr = pList->nodeLoc->next;
	printf("List Address: %d // [head] - ", (int)pList%1000);
	while (ptr) {
		printf("[%d] - ", ptr->data);
		ptr = ptr->next;
	}
	printf("[NULL]\n\n");
}

//�� ��� �ּҸ� �޾� �� �ڿ� ��� ����
void createNode(list* pList, int data) {
	//��� ����
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	//next == NULL�� ��� ã�Ƽ� �ڿ� ����
	node* ptr = pList->nodeLoc;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
}

//���� ��� ���̿� ��� ����
void insertNode(list* pList, int location, int data) {
	//��� ����
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	//data == location(����)�� ��� ã�Ƽ� �ڿ� ����
	node* ptr = pList->nodeLoc;
	while (ptr->data != location) {
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
}


//������ ������ ������ �޸� ����(free)
void freeList(list* pList) {
	node* ptr = pList->nodeLoc;
	while (ptr) {
		node* temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
}

//��� ����
void deleteNode(list* pList, int prevNodeData) {
	node* ptr = pList->nodeLoc;
	while (ptr->data != prevNodeData) {
		ptr = ptr->next;
	}
	node* delNode = ptr->next;
	ptr->next = delNode->next;
	free(delNode);
}