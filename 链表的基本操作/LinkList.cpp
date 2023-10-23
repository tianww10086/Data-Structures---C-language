#include"LinkList.h"
//���������Ҫ��ͷ�ĵ�ַ,
/*�㷨����:
	1.��ͷָ��LinkList����ռ�,����ͷ���
	2.��ͷ�����ΪNULL
	3.��������Ϊ0*/
int InitList(LinkList* L) {
	*L = (LinkList)malloc(sizeof(Node));/*����ͷ���,��ʹLָ���ͷ���*/
	if (!(*L)) {
		return ERROR;
	}
	//L��ָ��ͷָ���ָ�룬*L������ͷָ��,����ͷָ��ָ��Ľṹʹ��->
	(*L)->next = NULL; //*�������->��,Ҫ�����*L��next��,�����Ƚ�����
	(*L)->length = 0;
	return OK;
}
/*
3.��յ�����:
�㷨����:
	1.��������LinkListָ��,q,p;
	2.pָ���һ��Ԫ��
	3.ѭ��
		3.1 qָ��p����һ��Ԫ��
		3.2 �ͷ�p
		3.2 pָ��q;
	4.��ͷ����ָ������ΪNULL
�������:����L����Ϊ�ձ�
*/
int ClearList(LinkList* L)
{
	//�����ͷų�ͷ���������нڵ�,����ͷ����ָ������Ϊ��
	LinkList q, p;
	p = (*L)->next; //��pָ��ͷ����next��-----��Ԫ���
	//��pΪnullʱֹͣѭ��
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

/*
4.���ٵ�����:
�㷨����:
	1.����һLinkListָ�� p
	2.ѭ��----����p��ΪNULL
		2.1 ��ͷָ��ĵ�ַ����p
		2.2 Lָ��L����һ��Ԫ��
		2.3 �ͷ�p
�������:���ٱ�
*/
int DestroyList(LinkList* L) {
	//��ͷָ�뿪ʼ,�����ͷ����нڵ�
	LinkList p;
	while (p) {
		p = *L; //��ͷָ��ĵ�ַ��ֵ��p
		*L = (*L)->next; //��Lָ����һ��Ԫ��
		free(p);//�ͷ�p
	}
	return OK;
}

/*�жϱ��Ƿ�Ϊ��*/
int IsEmpty(LinkList L) {
	if (L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int ListLength(LinkList L) {
	int i = 0;
	LinkList p = L->next; //Lָ���һ�����
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

/*��ȡ��i��Ԫ�ص�ֵ*/
int GetElem(LinkList L, int i, int* e) {
	int j = 1;
	LinkList p;
	p = L->next;  //��pָ����Ԫ���
	while (j < i&&p) {
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return ERROR;

	}
	*e = p->elem;
	return OK;
}
/*
�㷨����:
	1.����һָ��pָ������ͷ���,��ʼ��j��1��ʼ;
	2.��j<iʱ,�ͱ�������,��p��ָ������ƶ�,����ָ����һ���,j�ۼ�1;
	3.��������ĩβpΪ��,��˵����i����㲻����;
	4.����Ͳ��ҳɹ�,��ϵͳ������һ���ս��s��
	5.������Ԫ��e��ֵ��s->data;
	6.������Ĳ����׼���:s->next=p->next;p->next=s;
	7.���سɹ�.
*/
int ListInsert(LinkList* L, int i, int e) {
	int j = 1;
	LinkList p, s;
	p = *L;
	while (p && j < i) {
		j++;
		p = p->next;
	}

	/*i������*/
	if (!p || j > i) {
		return ERROR;
	}
	s->elem = e;
	s->next = p->next;
	p->next = s;
	(*L)->length++;
	return OK;
}
int ListDelete(LinkList* L, int i, int* e) {
	int j = 1;
	LinkList p, q;
	p = *L;
	while (p && j < i) {
		p = p->next;
		j++;
	}

	/*i������*/
	if (!p || j > i) {
		return ERROR;
	}

	q = p->next;
	p->next = q->next;
	*e = q->elem;
	free(q);
	return OK;
}

/*��ֵ����,����λ�����*/
int LocateElem(LinkList L, int e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while (p && p->elem != e) {
		p = p->next;
		j++;
	}

	if (p) {
		return j;
	}
	else {
		return 0;
	}
}
/*ͷ�巨������*/
void CreateListHead(LinkList* L, int n) {
	LinkList p;
	srand(time(0)); //�������������
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->elem = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

}

void CreateListTail(LinkList* L, int n) {
	LinkList p,r;
	srand(time(0)); //�������������
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->elem = rand() % 100 + 1;
		r->next = p;
	}
	r->next = NULL;
}
