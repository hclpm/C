#include "function.h"

int main() {
	//시작점 노드 생성(head node)
	list l1, l2;
	initList(&l1);
	initList(&l2);

	createNode(&l1, 1);
	createNode(&l1, 2);
	createNode(&l1, 4);
	createNode(&l1, 5);
	insertNode(&l1, 2, 3);

	createNode(&l2, 100);
	createNode(&l2, 200);
	createNode(&l2, 300);

	printList(&l1);
	deleteNode(&l1, 1);
	printList(&l1);
	printList(&l2);

	freeList(&l1);
	freeList(&l2);

	
	return 0;
}