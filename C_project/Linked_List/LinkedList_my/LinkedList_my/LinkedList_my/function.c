#include "function.h"

//head노드 생성, list 포인터와 연결
node* initList(list* pList) {
	node* head = malloc(sizeof(node));
	head->data = -1;
	head->next = NULL;
	pList->nodeLoc = head;
}
//리스트를 입력받아 노드 전체 출력
void printList(list* pList) {
	node* ptr = pList->nodeLoc->next;
	printf("List Address: %d // [head] - ", (int)pList%1000);
	while (ptr) {
		printf("[%d] - ", ptr->data);
		ptr = ptr->next;
	}
	printf("[NULL]\n\n");
}

//앞 노드 주소를 받아 그 뒤에 노드 생성
void createNode(list* pList, int data) {
	//노드 생성
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	//next == NULL인 노드 찾아서 뒤에 연결
	node* ptr = pList->nodeLoc;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
}

//노드와 노드 사이에 노드 생성
void insertNode(list* pList, int location, int data) {
	//노드 생성
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	//data == location(인자)인 노드 찾아서 뒤에 연결
	node* ptr = pList->nodeLoc;
	while (ptr->data != location) {
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
}


//시작점 노드부터 끝까지 메모리 해제(free)
void freeList(list* pList) {
	node* ptr = pList->nodeLoc;
	while (ptr) {
		node* temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
}

//노드 삭제
void deleteNode(list* pList, int prevNodeData) {
	node* ptr = pList->nodeLoc;
	while (ptr->data != prevNodeData) {
		ptr = ptr->next;
	}
	node* delNode = ptr->next;
	ptr->next = delNode->next;
	free(delNode);
}