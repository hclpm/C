#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE {	//node 라는 구조체 변수 생성
	int data;
	struct NODE* next;
}node;

typedef struct LIST {	//list라는 구조체 포인터 생성
	node* pList;
}list;
//node 구조체 내의 노드들을 읽기 위해 list 구조체 포인터를 사용하는 것(?)



void printList(list* pList);			//리스트 출력 함수
void initList(list* pList);				//리스트 초기화 함수
void freeList(list* pList);				//리스트 해제 함수

node* createNode(int data, node* next); //노드 생성 함수
void insertNode(list* pList, int prevData, int data); //노드 삽입 함수
void deleteNode(list* pList, int data); //노드 삭제 함수