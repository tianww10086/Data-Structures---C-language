#pragma once
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef struct {
	int* elem;  /*����*/
	int length; /*����*/
}Sqlist;

int InitList(Sqlist* L); /*��ʼ������*/
int DestroyList(Sqlist* L); /*ɾ����*/
int ClearList(Sqlist* L);/*��ձ�*/
int ListInsert(Sqlist* L, int i, int e); //�����Ա�L�е�i��λ�ò�����Ԫ��e��
int ListDelete(Sqlist* L, int i, int* e);//ɾ�����Ա��е�i��λ��Ԫ�أ�����e����
int ListEmpty(Sqlist L); //�жϱ��Ƿ�Ϊ��
int ListLength(Sqlist L); //���ر�ĳ���
int LocateElem(Sqlist L, int e);//�����Ա�L�в��������ֵe��ȵ�Ԫ�أ�������ҳɹ�,���ظ�Ԫ���ڱ�����ű�ʾ�ɹ�,���򷵻�0��ʾʧ��
int GetElem(Sqlist L, int i, int *e); //�����Ա�L�е�i��λ�õ�Ԫ�ط��ظ�e��
void showList(Sqlist L); //�鿴�������Ԫ��
void ListMenu(); //˳���˵�
