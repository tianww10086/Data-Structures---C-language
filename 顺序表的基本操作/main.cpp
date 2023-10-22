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
				printf("��ʼ�����\n");
			}
			else {
				printf("��ʼ��ʧ��\n");
			}
			break;
		case 2:
			if (DestroyList(&L)) {
				printf("ɾ���ɹ�\n");
			}
			else {
				printf("ɾ��ʧ��\n");
			}
			break;
		case 3:
			ClearList(&L);
			printf("������\n");
			break;
		case 4:
			int i, e;
			printf("��������Ҫ�����λ�ú�Ԫ��:");
			scanf_s("%d %d", &i, &e);
			if (ListInsert(&L, i, e)) {
				printf("�������\n");
			}
			else {
				printf("����ʧ��\n");
			}
			break;
		case 5:
			int i1, e1;
			printf("��������Ҫɾ����λ��:");
			scanf_s("%d", &i1);
			if (ListDelete(&L,i1, &e1)) {
				printf("ɾ���ɹ�,��ɾ����ֵ��%d\n", e1);
			}
			else {
				printf("ɾ��ʧ��\n");
			}
			break;

		case 6:
			if (ListEmpty(L)) {
				printf("�˱�Ϊ��\n");
			}
			else {
				printf("�˱�Ϊ��\n");
			}
			break;
		case 7:
			printf("�˱�ĳ���Ϊ%d", ListLength(L));
			break;
		case 8:
			int e2;
			int j;
			printf("����������Ҫ���ҵ�ֵ:");
			scanf_s("%d", &e2);
			if (LocateElem(L, e2)) {
				printf("ֵ%d��Ӧ�������:%d\n",e2,LocateElem(L, e2));
			}
			else {
				printf("����ʧ��,���в��޴�Ԫ��\n");
			}
			break;
		case 9:
			int i3,e3;
			printf("��������Ҫ���ҵ�λ��:");
			scanf_s("%d", &i3);
			if (GetElem(L,i3,&e3)) {
				printf("��λ���ϵ�ֵΪ%d\n", e3);
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