#pragma once
#ifndef LinkList_H_
#define LinkList_H_
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#include<iostream>

typedef struct Node{
	int elem;
	struct Node* next; //ָ����
	int length;
}Node,*LinkList; //LinkList��ʾͷָ��,����������ͷ,����һ����
//ͷָ��ָ��ͷ���,ͷ����next��ָ����Ԫ���
//����Ҫ�����ͷ�ĵ�ַ
int InitList(LinkList * L);//��ʼ����L
int ClearList(LinkList* L);//��L����Ϊ�ձ�;
int DestroyList(LinkList* L); //���ٵ�����
int IsEmpty(LinkList L); //�ж��Ƿ�Ϊ�ձ�
int ListLength(LinkList L); //���ر�ĳ���
int GetElem(LinkList L, int i, int* e); //��ȡ����i��Ԫ�ص�ֵ
int ListInsert(LinkList* L, int i, int e);//����Ԫ���ڵ�i��λ��
int ListDelete(LinkList* L, int i, int* e);//ɾ����L�ڵ�i��λ���ϵ�Ԫ�أ�������e��
int LocateElem(LinkList L, int e); //��ֵ���ң����ض�Ӧ���
void CreateListHead(LinkList* L, int n); /*ͷ�巨������,n����Ҫ�������ٸ�Ԫ��*/
void CreateListTail(LinkList* L, int n); /*β�巨*/
#endif