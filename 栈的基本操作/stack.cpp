#include"stack.h"

int InitStack(Stack* S) {
	S->base = (int*)malloc(sizeof(int) * MAXSIZE);  //Ϊ˳��ջ����ռ䣬ʹջ��ָ������
	S->top = S->base;
	S->StackSize = MAXSIZE;
	S->lenth = 0;
	printf("��ʼ�����");
	return OK;
}

int DestroyStack(Stack* S) {
	if (S->base==NULL) {
		printf("��ջ�����ڣ�����ִ�����ٲ���");
		return ERROR;
	}

	free(S->base); //�ͷ�->baseָ��Ŀռ�
	//������ջָ�붼��Ϊ��;
	S->base = NULL; 
	S->top = NULL;
	S->StackSize = 0;
	printf("ջɾ���ɹ�\n");
	return OK;
}
/*��s.base��Ϊ�յ�ʱ����s.top(ջ��ָ��)ֱ��ָ��s.base��ջ�ף�,������е�Ԫ���߼��������

����s.baseΪ�յ�ʱ����ջ�Ѿ��������ˣ��������*/
int ClearStack(Stack* S) {

	if (S->base == NULL) {
		printf("ջ�ѿ�,�������\n");
		return ERROR;
	}
	S->top = S->base;
	S->lenth = 0;
	printf("��ղ��������\n");
	return OK;
}

int StackEmpty(Stack S) {
	if (S.base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return ERROR;
	}
	if (S.base == S.top) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
/*��ȡջ��Ԫ��*/
int GetTop(Stack S,int *e) {
	if (S.base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return ERROR;
	}
	if (StackEmpty(S)) {
		printf("ջΪ�գ��޷���ȡ");
		return ERROR;
	}
	else {
		*e = *(--S.top);
		return OK;
	}
}
/*���ջ��Ԫ��*/
int GetTop(Stack S) {
	if (S.base == NULL) {
		printf("ջ�����ڣ��޷�����");
		return ERROR;
	}
	if (StackEmpty(S)) {
		printf("ջΪ�գ��޷���ȡ\n");
		return ERROR;
	}
	printf("ջ��Ԫ��Ϊ%d\n", *(--S.top));
	return OK;
}

int Push(Stack* S, int e) {
	if (S->base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return ERROR;
	}
	//�ж�ջ�Ƿ������������������޷����в���
	if (S->top == S->base + S->StackSize) {
		printf("ջ�������޷�������ջ����");
		return ERROR;
	}
	*(S->top) = e;
	S->top++;
	S->lenth++;
	return OK;
}

int Pop(Stack* S) {
	if (S->base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return ERROR;
	}
	/*�ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ����޷����в���*/
	if (S->top == S->base) {
		printf("ջΪ�գ��޷�ִ�в���\n");
		return ERROR;
	}
	printf("ջ���ѳ�ջ������ջ��Ԫ��Ϊ%d\n", *(--S->top));
	S->top--;
	S->lenth--;
	return OK;
}

int Pop(Stack* S, int* e) {
	if (S->base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return ERROR;
	}
	/*�ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ����޷����в���*/
	if (S->top == S->base) {
		printf("ջΪ�գ��޷�ִ�в���\n");
		return ERROR;
	}
	*e = *(S->top); //��ջ��Ԫ�ر�����eֵ��;
	S->top--;
	S->lenth--;
	return OK;
}

int StackLength(Stack S) {
	if (S.base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return ERROR;
	}
	return S.lenth;
}

void StackMenu(){
	puts("-----------------------");
	puts("ջ����(�������ִ�ж�Ӧ����):");
	puts("1.��ʼ��ջ");
	puts("2.����ջ");
	puts("3.�ж�ջ�Ƿ�Ϊ��");
	puts("4.���ջ");
	puts("5.��ȡջ��Ԫ��");
	puts("6.��ջ");
	puts("7.��ջ");
	puts("8.��ȡջ�ĳ���");
	puts("9.�鿴ջ������Ԫ��");
	puts("0.�˳�");
}

void showStack(Stack S) {
	if (S.base == NULL) {
		printf("ջ�����ڣ��޷�����\n");
		return;
	}
	printf("��ջ��Ԫ��:");
	for (int i = 0; i < S.lenth; i++) {
		printf("%d ", *(S.base++));
	}
	puts("");
}