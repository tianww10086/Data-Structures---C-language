#include<stdio.h>
#include"head.h"
/*ѭ�����е�ʾ������*/
int main() {
	SqQueue QE1;  /*����һ��ѭ�����нṹ*/
	int e = 0; //������������
	while (1) {
		int x;
		showmenu();//����˵�
		scanf_s("%d", &x);
		if (x == 0) {
			break;
		}
		switch (x)
		{
		case 1: //��ʼ������
			if (InitQueue(&QE1)) {
				printf("��ʼ�����\n");
			}
			break;
		case 2: //ִ�ж��еĽ��Ӳ���
			
			printf("������һ��ֵ�����ֵ���������\n");
			scanf_s("%d", &e);
			if (EnQueue(&QE1, e)) {
				printf("����ɹ�,��ǰ���е�Ԫ��Ϊ:");
				showQueue(QE1);
				break;
			}
			else {
				printf("�����������޷����н��Ӳ���\n");
				break;
			}
		case 3: //ִ�ж��еĳ��Ӳ���
			if (DeQueue(&QE1, &e)) {
				printf("ɾ���ɹ�,��ǰ�Ķ���Ԫ��Ϊ:");
				showQueue(QE1);
			}
			else {
				printf("����Ϊ�գ��޷�ִ�г��Ӳ���\n");
				break;
			}
			case 4: //
				printf("��ǰ���е�Ԫ��Ϊ:");
				showQueue(QE1);
				break;
			case 5:
				printf("��ǰ���еĳ���Ϊ:%d\n", QueueLength(QE1));
				break;
			case 6:
				GetHaed(QE1, &e);
				printf("��ǰ���еĶ�ͷԪ��Ϊ:%d\n",e);
				break;
			case 7: //������ִ����ղ���;
				ClearQueue(&QE1);
				break;
		default:
			printf("��������ȷ�����");
			break;
		}
	}
}