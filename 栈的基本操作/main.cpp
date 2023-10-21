
#include"stack.h"
int main() {
	Stack Sk;
	int x;
	StackMenu();//输出菜单
	scanf_s("%d",& x);
	while (x!=0) {
		
		switch(x) {
		case 1:
			InitStack(&Sk);//执行初始化操作
			break;
		case 2:
			DestroyStack(&Sk); //执行销毁栈操作
			break;
		case 3:
			if (StackEmpty(Sk)) {  //判断栈是否为空
				printf("栈为空\n");
				break;
			}
			else {
				printf("此栈不为空,");
				printf("此栈的元素有%d个\n", StackLength(Sk));
				break;
			}
		case 4:
			ClearStack(&Sk);
			printf("清空后的栈，长度为%d\n", StackLength(Sk));
			break;
		case 5:
			GetTop(Sk); 
			break;
		case 6:
			if (Sk.base == NULL) {
				printf("栈不存在，无法操作\n");
				break;
			}
			int e;
			printf("请输入你要入栈的值:");
			scanf_s("%d", &e);
			Push(&Sk, e);
			showStack(Sk);
			break;
		case 7:
			Pop(&Sk);
			showStack(Sk);
			break;
		case 8:
			printf("当前栈的元素有%d个\n", StackLength(Sk));
			break;
		case 9:
			showStack(Sk);
		}
		StackMenu();//输出菜单
		scanf_s("%d", &x);
	}
}
