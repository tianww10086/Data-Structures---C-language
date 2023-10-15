#include<stdio.h>
#include"head.h"
/*循环队列的示例程序*/
int main() {
	SqQueue QE1;  /*创建一个循环队列结构*/
	int e = 0; //用作传入数据
	while (1) {
		int x;
		showmenu();//输出菜单
		scanf_s("%d", &x);
		if (x == 0) {
			break;
		}
		switch (x)
		{
		case 1: //初始化操作
			if (InitQueue(&QE1)) {
				printf("初始化完成\n");
			}
			break;
		case 2: //执行队列的进队操作
			
			printf("请输入一个值，这个值将进入队列\n");
			scanf_s("%d", &e);
			if (EnQueue(&QE1, e)) {
				printf("插入成功,当前队列的元素为:");
				showQueue(QE1);
				break;
			}
			else {
				printf("队列已满，无法进行进队操作\n");
				break;
			}
		case 3: //执行队列的出队操作
			if (DeQueue(&QE1, &e)) {
				printf("删除成功,当前的队列元素为:");
				showQueue(QE1);
			}
			else {
				printf("队列为空，无法执行出队操作\n");
				break;
			}
			case 4: //
				printf("当前队列的元素为:");
				showQueue(QE1);
				break;
			case 5:
				printf("当前队列的长度为:%d\n", QueueLength(QE1));
				break;
			case 6:
				GetHaed(QE1, &e);
				printf("当前队列的对头元素为:%d\n",e);
				break;
			case 7: //将队列执行清空操作;
				ClearQueue(&QE1);
				break;
		default:
			printf("请输入正确的序号");
			break;
		}
	}
}