
#include"stack.h"
int main() {
	Stack Sk;
	int x;
	StackMenu();//����˵�
	scanf_s("%d",& x);
	while (x!=0) {
		
		switch(x) {
		case 1:
			InitStack(&Sk);//ִ�г�ʼ������
			break;
		case 2:
			DestroyStack(&Sk); //ִ������ջ����
			break;
		case 3:
			if (StackEmpty(Sk)) {  //�ж�ջ�Ƿ�Ϊ��
				printf("ջΪ��\n");
				break;
			}
			else {
				printf("��ջ��Ϊ��,");
				printf("��ջ��Ԫ����%d��\n", StackLength(Sk));
				break;
			}
		case 4:
			ClearStack(&Sk);
			printf("��պ��ջ������Ϊ%d\n", StackLength(Sk));
			break;
		case 5:
			GetTop(Sk); 
			break;
		case 6:
			if (Sk.base == NULL) {
				printf("ջ�����ڣ��޷�����\n");
				break;
			}
			int e;
			printf("��������Ҫ��ջ��ֵ:");
			scanf_s("%d", &e);
			Push(&Sk, e);
			showStack(Sk);
			break;
		case 7:
			Pop(&Sk);
			showStack(Sk);
			break;
		case 8:
			printf("��ǰջ��Ԫ����%d��\n", StackLength(Sk));
			break;
		case 9:
			showStack(Sk);
		}
		StackMenu();//����˵�
		scanf_s("%d", &x);
	}
}
