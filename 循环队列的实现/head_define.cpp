#include<stdio.h>
#include"head.h"
#include<malloc.h>
//初始化一个空队列
Status InitQueue(SqQueue* Q) {
	//创建一个空队列，让它们的头尾指针为0即可
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//返回队列的长度
int QueueLength(SqQueue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;

}

/*若队列未满，则插入元素e为Q的新的队尾元素*/
Status EnQueue(SqQueue* Q, QElemtype e) {
	//满足条件，则队列满,无法进行进队操作，返回错误值0
	if ((Q->rear + 1) % MAXSIZE == Q->front) { /*队满的条件*/
		return ERROR;
	}

	Q->data[Q->rear] = e;/*将元素e赋给队尾*/
	Q->rear = (Q->rear + 1) % MAXSIZE; /*rear+1向后移动一位，%MAXSIZE确保rear不会超过队列的最大值*/
	return OK;
}

/*若队列不空，则删除Q中队头元素，用e返回其值*/
Status DeQueue(SqQueue* Q, QElemtype* e) {
	/*队空的判断*/
	if (Q->front == Q->rear) {
		return ERROR;
	}
	*e = Q->data[Q->front]; //先把值保存在e里
	Q->front = (Q->front + 1) % MAXSIZE; //然后让头指针下标移动一位
	return OK;
}
/*将队列清空*/
Status ClearQueue(SqQueue* Q) {
	Q->front = Q->rear = 0;
	return OK;
}
//判断队列是否为空,为空返回true，否则返回false
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
/*若队列存在且非空，用e返回队列Q的队头元素*/
Status GetHaed(SqQueue Q, QElemtype* e) {
	/*队列空则返回错误*/
	if (Q.front ==Q.rear) {
		return ERROR;
	}
	*e = Q.data[Q.front];
	return OK;
}
//查看队列里的所有元素
Status showQueue(SqQueue Q) {
	/*若队列为空则返回错误*/
	if (QueueEmpty(Q)) {
		return ERROR;
	}
	printf("Queue show:");
	while (Q.front!=Q.rear) {
		//队列本身是连续的，队头和队尾之间，不存在空白，只需要让循环从队头走到队尾即可。
		printf("%d ", Q.data[Q.front]);
		Q.front++;
		Q.front = Q.front % MAXSIZE;
	}
	printf("\n");
	return OK;
}
/*菜单*/
void showmenu() {
	printf("-------队列操作菜单-----\n");
	printf("使用说明：请输入序号运行其对应功能\n");
	printf("1——初始化一个空队列\n");
	printf("2——为队列表尾赋值\n");
	printf("3——从表头删除一个值\n");
	printf("4——查看表里面的值\n");
	printf("5——返回表的长度\n");
	printf("6——获取队列的队头元素\n");
	printf("7——将队列清空.\n");
	printf("0——退出操作\n");
}




/*链队列的操作*/
/*插入元素e为Q的新的队尾元素*/
Status EnQueue(LinkQueue* Q, QElemtype e) {
	//创建一个新结点
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode)); //给这个指针分配QNode结点大小的空间
	s->data = e; /*赋值data域*/
	s->next = NULL; /*由于是队尾，它的next指针指向空*/
	Q->rear->next = s;/*先把拥有元素e的新结点s赋值给原队尾结点的后继*/
	Q->rear = s; /*把当前的s设置为队尾结点，rear指向s*/
	return OK;
}

/*若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR*/
Status DeQueue(LinkQueue* Q, QElemtype* e) {
	QueuePtr p; //创建一个结点，保存被删除的结点并将其释放
	p= Q->front->next;/*队头结点是头结点的下一个元素，将欲删除的队头结点暂存给p*/
	p->data = *e; /*将欲删除的队头结点赋值给e*/
	Q->front->next = p->next; /*将原队头结点的后继P->next赋值给头结点后继*/
	if (Q->rear == p) {
		Q->rear = Q->front;/*若队头就是队尾，则删除后将rear指向头结点*/
	}
	free(p); //释放p结点
	return OK;
}