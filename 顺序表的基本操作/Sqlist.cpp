#include"SqList.h"

int InitList(Sqlist* L) {
	L->elem = (int*)malloc(sizeof(int) * MAXSIZE);  /*给指针分配空间，可看为数组*/
	L->length = 0;
	return OK;
}

int DestroyList(Sqlist* L) {
	if (L->elem == NULL) {
		printf("表不存在,无需删除\n");
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

/*算法步骤：
	1.如果插入位置不合理，抛出异常；
	2.如果线性表长度大于等于数组，则抛出异常或动态增加容量
	3.从最后一个元素遍历到第i个位置，分别将它们都向后移动一个位置；
	4.将要插入元素填入位置i处
	5.表长+1*/
int ListInsert(Sqlist* L, int i, int e) {
	if (L->length == MAXSIZE) {
		printf("表已满\n");
		return ERROR;
	}

	if (i >L->length+1&&i<1) {
		printf("插入位置不合理\n");
		return ERROR;
	}
	/*经过两次判断后,i的值被限定在
	1<=i<=length
	*/
	if (i <= L->length) {
		for (int j = L->length - 1; j >= i - 1; j--) {
			//向后移动一个位置
			L->elem[j + 1] = L->elem[j];
		}
	}
	
	L->elem[i - 1] = e;
	L->length++;
	return OK;
}
/*算法步骤:
	1.如果删除位置不合理，抛出异常
	2.取出删除元素
	3.从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一位位置
	4.如果该位置是最后一位，也就是i==length，则直接--
	5.表长-1
*/
int ListDelete(Sqlist* L, int i, int* e) {
	if (L->length == 0) {
		printf("表为空\n");
		return ERROR;
	}
	
	if (i<1 || i>L->length) {
		printf("位置不合理\n");
		return ERROR;
	}

	/*经过两次判断后,i的值被限定在
	1<=i<length;
	*/
	*e = L->elem[i - 1];//保存删除元素
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
		printf("获取元素的位置不合理\n");
		return ERROR;
	}

	*e = L.elem[i - 1];
	return OK;
}

void showList(Sqlist L) {
	printf("该表的元素有:");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

void ListMenu() {
	puts("-------------");
	puts("顺序表操作");
	puts("1.初始化表");
	puts("2.删除表");
	puts("3.清空表");
	puts("4.在线性表L中第i个位置插入元素e");
	puts("5.删除表中第i个位置，并用e返回");
	puts("6.判断表是否为空");
	puts("7.返回表的长度");
	puts("8.返回与e值相等的元素，查找成功,保存该序号");
	puts("9.将线性表第i个位置返回给e");
	puts("10.查看所有元素");
	puts("0.退出");
}
