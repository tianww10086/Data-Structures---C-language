#include"SqList.h"

int InitList(Sqlist* L) {
	L->elem = (int*)malloc(sizeof(int) * MAXSIZE);  /*��ָ�����ռ䣬�ɿ�Ϊ����*/
	L->length = 0;
	return OK;
}

int DestroyList(Sqlist* L) {
	if (L->elem == NULL) {
		printf("������,����ɾ��\n");
		return ERROR;
	}
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	return OK;
}

int ClearList(Sqlist* L) {
	L->length = 0;
	return OK;
}

/*�㷨���裺
	1.�������λ�ò������׳��쳣��
	2.������Ա��ȴ��ڵ������飬���׳��쳣��̬��������
	3.�����һ��Ԫ�ر�������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ�ã�
	4.��Ҫ����Ԫ������λ��i��
	5.��+1*/
int ListInsert(Sqlist* L, int i, int e) {
	if (L->length == MAXSIZE) {
		printf("������\n");
		return ERROR;
	}

	if (i >L->length+1&&i<1) {
		printf("����λ�ò�����\n");
		return ERROR;
	}
	/*���������жϺ�,i��ֵ���޶���
	1<=i<=length
	*/
	if (i <= L->length) {
		for (int j = L->length - 1; j >= i - 1; j--) {
			//����ƶ�һ��λ��
			L->elem[j + 1] = L->elem[j];
		}
	}
	
	L->elem[i - 1] = e;
	L->length++;
	return OK;
}
/*�㷨����:
	1.���ɾ��λ�ò������׳��쳣
	2.ȡ��ɾ��Ԫ��
	3.��ɾ��Ԫ��λ�ÿ�ʼ���������һ��Ԫ��λ�ã��ֱ����Ƕ���ǰ�ƶ�һλλ��
	4.�����λ�������һλ��Ҳ����i==length����ֱ��--
	5.��-1
*/
int ListDelete(Sqlist* L, int i, int* e) {
	if (L->length == 0) {
		printf("��Ϊ��\n");
		return ERROR;
	}
	
	if (i<1 || i>L->length) {
		printf("λ�ò�����\n");
		return ERROR;
	}

	/*���������жϺ�,i��ֵ���޶���
	1<=i<length;
	*/
	*e = L->elem[i - 1];//����ɾ��Ԫ��
	if (i < L->length) {
		for (int k = i; k < L->length; k++) {
			L->elem[k - 1] = L->elem[k];
		}
	}
	L->length--;
	return OK;
}

int ListEmpty(Sqlist L) {
	if (L.length == 0) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int ListLength(Sqlist L) {
	return L.length;
}

int LocateElem(Sqlist L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

int GetElem(Sqlist L, int i, int* e) {
	if (L.length == 0 || i > L.length || i < 1) {
		printf("��ȡԪ�ص�λ�ò�����\n");
		return ERROR;
	}

	*e = L.elem[i - 1];
	return OK;
}

void showList(Sqlist L) {
	printf("�ñ��Ԫ����:");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

void ListMenu() {
	puts("-------------");
	puts("˳������");
	puts("1.��ʼ����");
	puts("2.ɾ����");
	puts("3.��ձ�");
	puts("4.�����Ա�L�е�i��λ�ò���Ԫ��e");
	puts("5.ɾ�����е�i��λ�ã�����e����");
	puts("6.�жϱ��Ƿ�Ϊ��");
	puts("7.���ر�ĳ���");
	puts("8.������eֵ��ȵ�Ԫ�أ����ҳɹ�,��������");
	puts("9.�����Ա��i��λ�÷��ظ�e");
	puts("10.�鿴����Ԫ��");
	puts("0.�˳�");
}
