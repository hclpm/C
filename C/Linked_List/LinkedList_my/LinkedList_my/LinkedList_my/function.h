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

//������ ��� ������ �ʱ�ȭ, ����Ʈ�� ����ȭ
node* initList(list* pList);

//����Ʈ�� �޾� ����Ʈ ���� ��� ����
void createNode(list* pList, int data);

//����Ʈ ù ���~�� ��� ���
void printList(list* pList);

//���ϴ� ����Ʈ�� ���ϴ� ��ġ�� ������ ����
void insertNode(list* pList, int location, int data);

//������ ������ ������ �޸� ����(free)
void freeList(list* pList);
//��� ����
void deleteNode(list* pList, int prevNodeData);