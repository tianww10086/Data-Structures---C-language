#include"LinkList.h"
//这个函数需要表头的地址,
/*算法步骤:
	1.给头指针LinkList分配空间,产生头结点
	2.将头结点置为NULL
	3.将长度置为0*/
int InitList(LinkList* L) {
	*L = (LinkList)malloc(sizeof(Node));/*生成头结点,并使L指向此头结点*/
	if (!(*L)) {
		return ERROR;
	}
	//L是指向头指针的指针，*L即代表头指针,访问头指针指向的结构使用->
	(*L)->next = NULL; //*运算符比->低,要想访问*L的next域,必须先解引用
	(*L)->length = 0;
	return OK;
}
/*
3.清空单链表:
算法步骤:
	1.声明两个LinkList指针,q,p;
	2.p指向第一个元素
	3.循环
		3.1 q指向p的下一个元素
		3.2 释放p
		3.2 p指向q;
	4.把头结点的指针域置为NULL
操作结果:将表L重置为空表
*/
int ClearList(LinkList* L)
{
	//依次释放除头结点外的所有节点,并把头结点的指针域置为空
	LinkList q, p;
	p = (*L)->next; //让p指向头结点的next域-----首元结点
	//当p为null时停止循环
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

/*
4.销毁单链表:
算法步骤:
	1.声明一LinkList指针 p
	2.循环----条件p不为NULL
		2.1 把头指针的地址赋给p
		2.2 L指向L的下一个元素
		2.3 释放p
操作结果:销毁表
*/
int DestroyList(LinkList* L) {
	//从头指针开始,依次释放所有节点
	LinkList p;
	while (p) {
		p = *L; //把头指针的地址赋值给p
		*L = (*L)->next; //让L指向下一个元素
		free(p);//释放p
	}
	return OK;
}

/*判断表是否为空*/
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
	LinkList p = L->next; //L指向第一个结点
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

/*获取第i个元素的值*/
int GetElem(LinkList L, int i, int* e) {
	int j = 1;
	LinkList p;
	p = L->next;  //让p指向首元结点
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
算法步骤:
	1.声明一指针p指向链表头结点,初始化j从1开始;
	2.当j<i时,就遍历链表,让p的指针向后移动,不断指向下一结点,j累加1;
	3.若到链表末尾p为空,则说明第i个结点不存在;
	4.否则就查找成功,在系统中生成一个空结点s；
	5.将数据元素e赋值给s->data;
	6.单链表的插入标准语句:s->next=p->next;p->next=s;
	7.返回成功.
*/
int ListInsert(LinkList* L, int i, int e) {
	int j = 1;
	LinkList p, s;
	p = *L;
	while (p && j < i) {
		j++;
		p = p->next;
	}

	/*i不存在*/
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

	/*i不存在*/
	if (!p || j > i) {
		return ERROR;
	}

	q = p->next;
	p->next = q->next;
	*e = q->elem;
	free(q);
	return OK;
}

/*按值查找,返回位置序号*/
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
/*头插法建立表*/
void CreateListHead(LinkList* L, int n) {
	LinkList p;
	srand(time(0)); //生成随机数种子
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
	srand(time(0)); //生成随机数种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->elem = rand() % 100 + 1;
		r->next = p;
	}
	r->next = NULL;
}
