#include"stack.h"

int InitStack(Stack* S) {
	S->base = (int*)malloc(sizeof(int) * MAXSIZE);  //为顺序栈分配空间，使栈底指向他。
	S->top = S->base;
	S->StackSize = MAXSIZE;
	S->lenth = 0;
	printf("初始化完成");
	return OK;
}

int DestroyStack(Stack* S) {
	if (S->base==NULL) {
		printf("此栈不存在，无需执行销毁操作");
		return ERROR;
	}

	free(S->base); //释放->base指向的空间
	//把两个栈指针都置为空;
	S->base = NULL; 
	S->top = NULL;
	S->StackSize = 0;
	printf("栈删除成功\n");
	return OK;
}
/*当s.base不为空的时候，让s.top(栈顶指针)直接指向s.base（栈底）,则把所有的元素逻辑上清空了

而当s.base为空的时候，则栈已经被销毁了，无需清空*/
int ClearStack(Stack* S) {

	if (S->base == NULL) {
		printf("栈已空,无需操作\n");
		return ERROR;
	}
	S->top = S->base;
	S->lenth = 0;
	printf("清空操作已完成\n");
	return OK;
}

int StackEmpty(Stack S) {
	if (S.base == NULL) {
		printf("栈不存在，无法操作\n");
		return ERROR;
	}
	if (S.base == S.top) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
/*获取栈顶元素*/
int GetTop(Stack S,int *e) {
	if (S.base == NULL) {
		printf("栈不存在，无法操作\n");
		return ERROR;
	}
	if (StackEmpty(S)) {
		printf("栈为空，无法获取");
		return ERROR;
	}
	else {
		*e = *(--S.top);
		return OK;
	}
}
/*输出栈顶元素*/
int GetTop(Stack S) {
	if (S.base == NULL) {
		printf("栈不存在，无法操作");
		return ERROR;
	}
	if (StackEmpty(S)) {
		printf("栈为空，无法获取\n");
		return ERROR;
	}
	printf("栈顶元素为%d\n", *(--S.top));
	return OK;
}

int Push(Stack* S, int e) {
	if (S->base == NULL) {
		printf("栈不存在，无法操作\n");
		return ERROR;
	}
	//判断栈是否已满，若已满，则无法进行操作
	if (S->top == S->base + S->StackSize) {
		printf("栈已满，无法进行入栈操作");
		return ERROR;
	}
	*(S->top) = e;
	S->top++;
	S->lenth++;
	return OK;
}

int Pop(Stack* S) {
	if (S->base == NULL) {
		printf("栈不存在，无法操作\n");
		return ERROR;
	}
	/*判断栈是否为空，若为空，则无法进行操作*/
	if (S->top == S->base) {
		printf("栈为空，无法执行操作\n");
		return ERROR;
	}
	printf("栈顶已出栈，被出栈的元素为%d\n", *(--S->top));
	S->top--;
	S->lenth--;
	return OK;
}

int Pop(Stack* S, int* e) {
	if (S->base == NULL) {
		printf("栈不存在，无法操作\n");
		return ERROR;
	}
	/*判断栈是否为空，若为空，则无法进行操作*/
	if (S->top == S->base) {
		printf("栈为空，无法执行操作\n");
		return ERROR;
	}
	*e = *(S->top); //把栈顶元素保存在e值上;
	S->top--;
	S->lenth--;
	return OK;
}

int StackLength(Stack S) {
	if (S.base == NULL) {
		printf("栈不存在，无法操作\n");
		return ERROR;
	}
	return S.lenth;
}

void StackMenu(){
	puts("-----------------------");
	puts("栈操作(输入序号执行对应操作):");
	puts("1.初始化栈");
	puts("2.销毁栈");
	puts("3.判断栈是否为空");
	puts("4.清空栈");
	puts("5.获取栈顶元素");
	puts("6.入栈");
	puts("7.出栈");
	puts("8.获取栈的长度");
	puts("9.查看栈的所有元素");
	puts("0.退出");
}

void showStack(Stack S) {
	if (S.base == NULL) {
		printf("栈不存在，无法操作\n");
		return;
	}
	printf("此栈的元素:");
	for (int i = 0; i < S.lenth; i++) {
		printf("%d ", *(S.base++));
	}
	puts("");
}