#include<stdio.h>
#include"head.h"
#include<malloc.h>
//��ʼ��һ���ն���
Status InitQueue(SqQueue* Q) {
	//����һ���ն��У������ǵ�ͷβָ��Ϊ0����
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//���ض��еĳ���
int QueueLength(SqQueue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;

}

/*������δ���������Ԫ��eΪQ���µĶ�βԪ��*/
Status EnQueue(SqQueue* Q, QElemtype e) {
	//�����������������,�޷����н��Ӳ��������ش���ֵ0
	if ((Q->rear + 1) % MAXSIZE == Q->front) { /*����������*/
		return ERROR;
	}

	Q->data[Q->rear] = e;/*��Ԫ��e������β*/
	Q->rear = (Q->rear + 1) % MAXSIZE; /*rear+1����ƶ�һλ��%MAXSIZEȷ��rear���ᳬ�����е����ֵ*/
	return OK;
}

/*�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ*/
Status DeQueue(SqQueue* Q, QElemtype* e) {
	/*�ӿյ��ж�*/
	if (Q->front == Q->rear) {
		return ERROR;
	}
	*e = Q->data[Q->front]; //�Ȱ�ֵ������e��
	Q->front = (Q->front + 1) % MAXSIZE; //Ȼ����ͷָ���±��ƶ�һλ
	return OK;
}
/*���������*/
Status ClearQueue(SqQueue* Q) {
	Q->front = Q->rear = 0;
	return OK;
}
//�ж϶����Ƿ�Ϊ��,Ϊ�շ���true�����򷵻�false
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
/*�����д����ҷǿգ���e���ض���Q�Ķ�ͷԪ��*/
Status GetHaed(SqQueue Q, QElemtype* e) {
	/*���п��򷵻ش���*/
	if (Q.front ==Q.rear) {
		return ERROR;
	}
	*e = Q.data[Q.front];
	return OK;
}
//�鿴�����������Ԫ��
Status showQueue(SqQueue Q) {
	/*������Ϊ���򷵻ش���*/
	if (QueueEmpty(Q)) {
		return ERROR;
	}
	printf("Queue show:");
	while (Q.front!=Q.rear) {
		//���б����������ģ���ͷ�Ͷ�β֮�䣬�����ڿհף�ֻ��Ҫ��ѭ���Ӷ�ͷ�ߵ���β���ɡ�
		printf("%d ", Q.data[Q.front]);
		Q.front++;
		Q.front = Q.front % MAXSIZE;
	}
	printf("\n");
	return OK;
}
/*�˵�*/
void showmenu() {
	printf("-------���в����˵�-----\n");
	printf("ʹ��˵��������������������Ӧ����\n");
	printf("1������ʼ��һ���ն���\n");
	printf("2����Ϊ���б�β��ֵ\n");
	printf("3�����ӱ�ͷɾ��һ��ֵ\n");
	printf("4�����鿴�������ֵ\n");
	printf("5�������ر�ĳ���\n");
	printf("6������ȡ���еĶ�ͷԪ��\n");
	printf("7�������������.\n");
	printf("0�����˳�����\n");
}




/*�����еĲ���*/
/*����Ԫ��eΪQ���µĶ�βԪ��*/
Status EnQueue(LinkQueue* Q, QElemtype e) {
	//����һ���½��
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode)); //�����ָ�����QNode����С�Ŀռ�
	s->data = e; /*��ֵdata��*/
	s->next = NULL; /*�����Ƕ�β������nextָ��ָ���*/
	Q->rear->next = s;/*�Ȱ�ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ��*/
	Q->rear = s; /*�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s*/
	return OK;
}

/*�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status DeQueue(LinkQueue* Q, QElemtype* e) {
	QueuePtr p; //����һ����㣬���汻ɾ���Ľ�㲢�����ͷ�
	p= Q->front->next;/*��ͷ�����ͷ������һ��Ԫ�أ�����ɾ���Ķ�ͷ����ݴ��p*/
	p->data = *e; /*����ɾ���Ķ�ͷ��㸳ֵ��e*/
	Q->front->next = p->next; /*��ԭ��ͷ���ĺ��P->next��ֵ��ͷ�����*/
	if (Q->rear == p) {
		Q->rear = Q->front;/*����ͷ���Ƕ�β����ɾ����rearָ��ͷ���*/
	}
	free(p); //�ͷ�p���
	return OK;
}