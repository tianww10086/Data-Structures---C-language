#pragma once
/*��ջ����ռ�*/
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemtype;

typedef struct {
	int *top; //topָ��ָ��ǰջ��Ԫ�ص���һ��λ�á�
	int *base; //base ָ��ָ��ջ��Ԫ�����ڵ��ڴ�λ��
	int StackSize; //��ʾջ�����Ԫ��
	int lenth;  //ջ�Ĵ�С
}Stack;

int InitStack(Stack* S);//��ʼ��ջ
int DestroyStack(Stack* S);  //����ջ
int StackEmpty(Stack S); //�ж�ջ�Ƿ�Ϊ��
int ClearStack(Stack* S);  //���ջ
int GetTop(Stack S,int *e); //��ȡջ��Ԫ��,������e��
int GetTop(Stack S);  //���أ������棬�����
int Push(Stack* S, int e);  //��ջ����
int Pop(Stack* S, int* e); //��ջ����
int Pop(Stack* S); //���س�ջ������������ջ��ֵ,�������
int StackLength(Stack S);//��ȡջ�ĳ���
void StackMenu(); //StacK�����˵�
void showStack(Stack S); //���ջ��Ԫ��
