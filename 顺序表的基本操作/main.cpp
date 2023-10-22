#include"SqList.h"

int main() {
	Sqlist L;
	int x;
	ListMenu();
	scanf_s("%d", &x);
	while (x != 0) {
		switch (x) {
		case 1:
			if (InitList(&L)) {
				printf("初始化完成\n");
			}
			else {
				printf("初始化失败\n");
			}
			break;
		case 2:
			if (DestroyList(&L)) {
				printf("删除成功\n");
			}
			else {
				printf("删除失败\n");
			}
			break;
		case 3:
			ClearList(&L);
			printf("清空完成\n");
			break;
		case 4:
			int i, e;
			printf("请输入你要插入的位置和元素:");
			scanf_s("%d %d", &i, &e);
			if (ListInsert(&L, i, e)) {
				printf("插入完成\n");
			}
			else {
				printf("插入失败\n");
			}
			break;
		case 5:
			int i1, e1;
			printf("请输入你要删除的位置:");
			scanf_s("%d", &i1);
			if (ListDelete(&L,i1, &e1)) {
				printf("删除成功,被删除的值是%d\n", e1);
			}
			else {
				printf("删除失败\n");
			}
			break;

		case 6:
			if (ListEmpty(L)) {
				printf("此表为空\n");
			}
			else {
				printf("此表不为空\n");
			}
			break;
		case 7:
			printf("此表的长度为%d", ListLength(L));
			break;
		case 8:
			int e2;
			int j;
			printf("请输入你想要查找的值:");
			scanf_s("%d", &e2);
			if (LocateElem(L, e2)) {
				printf("值%d对应的序号是:%d\n",e2,LocateElem(L, e2));
			}
			else {
				printf("查找失败,表中并无此元素\n");
			}
			break;
		case 9:
			int i3,e3;
			printf("请输入你要查找的位置:");
			scanf_s("%d", &i3);
			if (GetElem(L,i3,&e3)) {
				printf("此位置上的值为%d\n", e3);
			}
			break;
		case 10:
			showList(L);
			break;
		}
		ListMenu();
		scanf_s("%d", &x);
	}
}