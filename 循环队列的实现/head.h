#pragma once //��ֹͷ�ļ�����ΰ�����ֻ�ܱ�����һ��
#include<stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int QElemtype;  //QElemtype���͸�������������������Ϊint
typedef int Status;

/*˳��ṹ�洢����*/
typedef struct {
	QElemtype data[MAXSIZE];  //������
	int front;   /*ָ���ͷ��ָ�룬���ͷָ��*/
	int rear;   /*ָ���β����һ��Ԫ�ص�ָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
}SqQueue;

Status InitQueue(SqQueue* Q); //��ʼ��һ���ն���Q
int QueueLength(SqQueue q);//����Q�ĳ���
Status EnQueue(SqQueue* Q, QElemtype e);//ѭ�����еĽ����в���
Status DeQueue(SqQueue* Q, QElemtype* e);//ѭ�����еĳ����в���
Status ClearQueue(SqQueue *Q); //���������
Status GetHaed(SqQueue Q, QElemtype* e);//��ȡ���еĶ�ͷԪ��
Status showQueue(SqQueue Q); /*�鿴���е�Ԫ��*/
void showmenu(); /*����˵�*/

/*��ʽ�ṹ�洢���У����������*/
typedef struct QNode { /*���ṹ*/
	QElemtype data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct { /*���е�����ṹ*/
	QueuePtr front, rear; /*��ͷ����βָ��*/
}LinkQueue;


