#pragma once
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef struct {
	int* elem;  /*数组*/
	int length; /*长度*/
}Sqlist;

int InitList(Sqlist* L); /*初始化操作*/
int DestroyList(Sqlist* L); /*删除表*/
int ClearList(Sqlist* L);/*清空表*/
int ListInsert(Sqlist* L, int i, int e); //在线性表L中第i个位置插入新元素e。
int ListDelete(Sqlist* L, int i, int* e);//删除线性表中第i个位置元素，并用e返回
int ListEmpty(Sqlist L); //判断表是否为空
int ListLength(Sqlist L); //返回表的长度
int LocateElem(Sqlist L, int e);//在线性表L中查找与给定值e相等的元素，如果查找成功,返回该元素在表中序号表示成功,否则返回0表示失败
int GetElem(Sqlist L, int i, int *e); //将线性表L中第i个位置的元素返回给e。
void showList(Sqlist L); //查看表的所有元素
void ListMenu(); //顺序表菜单
