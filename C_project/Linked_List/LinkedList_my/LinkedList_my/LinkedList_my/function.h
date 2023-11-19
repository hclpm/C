#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef struct NODE {
	int data;
	struct NODE* next;
}node;

typedef struct LIST {
	node* nodeLoc;
}list;

//시작점 노드 생성과 초기화, 리스트와 동기화
node* initList(list* pList);

//리스트를 받아 리스트 끝에 노드 생성
void createNode(list* pList, int data);

//리스트 첫 노드~끝 노드 출력
void printList(list* pList);

//원하는 리스트의 원하는 위치에 데이터 삽입
void insertNode(list* pList, int location, int data);

//시작점 노드부터 끝까지 메모리 해제(free)
void freeList(list* pList);
//노드 삭제
void deleteNode(list* pList, int prevNodeData);