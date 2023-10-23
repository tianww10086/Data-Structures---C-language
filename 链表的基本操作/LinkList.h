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
	struct Node* next; //指针域
	int length;
}Node,*LinkList; //LinkList表示头指针,把它看做表头,代表一个表
//头指针指向头结点,头结点的next域指向首元结点
//它需要这个表头的地址
int InitList(LinkList * L);//初始化表L
int ClearList(LinkList* L);//将L重置为空表;
int DestroyList(LinkList* L); //销毁单链表
int IsEmpty(LinkList L); //判断是否为空表
int ListLength(LinkList L); //返回表的长度
int GetElem(LinkList L, int i, int* e); //获取出第i个元素的值
int ListInsert(LinkList* L, int i, int e);//插入元素在第i个位置
int ListDelete(LinkList* L, int i, int* e);//删除表L在第i个位置上的元素，保存在e里
int LocateElem(LinkList L, int e); //按值查找，返回对应序号
void CreateListHead(LinkList* L, int n); /*头插法整表创建,n代表要创建多少个元素*/
void CreateListTail(LinkList* L, int n); /*尾插法*/
#endif