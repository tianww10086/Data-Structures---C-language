#pragma once
/*两栈共享空间*/
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
	int *top; //top指针指向当前栈顶元素的下一个位置。
	int *base; //base 指针指向栈底元素所在的内存位置
	int StackSize; //表示栈的最大元素
	int lenth;  //栈的大小
}Stack;

int InitStack(Stack* S);//初始化栈
int DestroyStack(Stack* S);  //销毁栈
int StackEmpty(Stack S); //判断栈是否为空
int ClearStack(Stack* S);  //清空栈
int GetTop(Stack S,int *e); //获取栈顶元素,保存在e里
int GetTop(Stack S);  //重载，不保存，输出它
int Push(Stack* S, int e);  //入栈操作
int Pop(Stack* S, int* e); //出栈操作
int Pop(Stack* S); //重载出栈操作，不保存栈顶值,而输出它
int StackLength(Stack S);//获取栈的长度
void StackMenu(); //StacK操作菜单
void showStack(Stack S); //输出栈的元素
