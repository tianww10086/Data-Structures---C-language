#pragma once //防止头文件被多次包含，只能被包含一次
#include<stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int QElemtype;  //QElemtype类型根据情况而定，这里假设为int
typedef int Status;

/*顺序结构存储队列*/
typedef struct {
	QElemtype data[MAXSIZE];  //数据域
	int front;   /*指向队头的指针，简称头指针*/
	int rear;   /*指向队尾的下一个元素的指针，若队列不空，指向队列尾元素的下一个位置*/
}SqQueue;

Status InitQueue(SqQueue* Q); //初始化一个空队列Q
int QueueLength(SqQueue q);//返回Q的长度
Status EnQueue(SqQueue* Q, QElemtype e);//循环队列的进队列操作
Status DeQueue(SqQueue* Q, QElemtype* e);//循环队列的出队列操作
Status ClearQueue(SqQueue *Q); //将队列清空
Status GetHaed(SqQueue Q, QElemtype* e);//获取队列的队头元素
Status showQueue(SqQueue Q); /*查看队列的元素*/
void showmenu(); /*输出菜单*/

/*链式结构存储队列，检查链队列*/
typedef struct QNode { /*结点结构*/
	QElemtype data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct { /*队列的链表结构*/
	QueuePtr front, rear; /*队头、队尾指针*/
}LinkQueue;


