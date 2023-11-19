#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE {	//node ��� ����ü ���� ����
	int data;
	struct NODE* next;
}node;

typedef struct LIST {	//list��� ����ü ������ ����
	node* pList;
}list;
//node ����ü ���� ������ �б� ���� list ����ü �����͸� ����ϴ� ��(?)



void printList(list* pList);			//����Ʈ ��� �Լ�
void initList(list* pList);				//����Ʈ �ʱ�ȭ �Լ�
void freeList(list* pList);				//����Ʈ ���� �Լ�

node* createNode(int data, node* next); //��� ���� �Լ�
void insertNode(list* pList, int prevData, int data); //��� ���� �Լ�
void deleteNode(list* pList, int data); //��� ���� �Լ�