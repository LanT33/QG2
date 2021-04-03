#include "SqStack.h"

int main()
{
	int flag = 0;
	SqStack *head = (SqStack*)malloc(sizeof(SqStack));
	head->elem = NULL;
	head->size = 0;
	head->top =-1;
	while(SUCCESS)
	{

    	system("cls");
    	printf(" 顺序栈工具\n--------------------------\n");
        printf(" 1.创建顺序栈               \n");
        printf(" 2.判断顺序栈是否为空       \n");
        printf(" 3.获取栈顶数据             \n");
        printf(" 4.清空顺序栈               \n");
        printf(" 5.销毁顺序栈               \n");
        printf(" 6.检测栈长                 \n");
        printf(" 7.数据入栈                 \n");
        printf(" 8.数据出栈                 \n");
        printf(" 9.退出                     \n");
        printf("--------------------------  \n");
        printf("--------------------------  \n");
        printf("当前链表状态:");
        if(flag)
        {

               printStack(head);
        }
        else
        {
                printf("乜都冇……(什么都没有)\n");
        }
	printf("--------------------------\n");
        printf("输入序号可运行对应功能:");
	 switch(Input())
        {
                case 1:
			if(!flag)
			{
				printf("请输入要创建的栈的大小(正整数）：");
				int k = Input();
				initStack(head,k);
				flag = 1;
				break;
			}
			else
			{
				printf("已有顺序栈，销毁当前栈后可重新创建\n");
				break;
			}
               case 2:
                        if(flag)
                        {
                                isEmptyStack(head);
                        }
                        else
                        {
                                printf("没有栈\n");
                        }
                        break;
                case 3:
			if(flag)
                        {
                        	int j=0;
				getTopStack(head,&j);

                        }
                        else
                        {
                                printf("没有栈\n");
                        }
                        break;
                case 4:
                        if(flag)
                        {
				clearStack(head);
                        }
                        else
                        {
                               printf("没有栈\n");
                        }
                        break;
                case 5:
                        if(flag)
                        {
                                destroyStack(head);
                                flag = 0;
                        }
                        else
                        {
                              printf("没有栈\n");
                        }
                        break;
                case 6:
                        if(flag)
                        {
                        	int z=0;
                                stackLength(head,&z);
                        }
                        else
                        {
                               printf("没有栈\n");
                        }
                        break;
                case 7:
                        if(flag)
                        {
                                int i;
                                printf("请输入要入栈的数据:");
                                i=Input();
                                pushStack(head,i);
                        }
                        else
                        {
                               printf("没有栈\n");
                        }
                        break;
                case 8:
                        if(flag)
                        {
                        	int x=0;
                                popStack(head,&x);
                        }
                        else
                        {
                                printf("没有栈\n");
                        }
                        break;
                case 9:
                        exit(0);
                default:
                        printf("无该项功能\n");
                        break;
        }
        system("pause");
    }
    return 0;
}
