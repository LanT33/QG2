#include "LinkStack.h"



int main()
{
	int flag = 0;
	LinkStack* head = (LinkStack*)malloc(sizeof(StackNode));
	head->top = NULL;
	head->count = 0;
	while(SUCCESS)
	{

    	system("cls");
    	printf(" 链栈工具\n--------------------------\n");
        printf(" 1.创建栈               \n");
        printf(" 2.判断栈是否为空       \n");
        printf(" 3.获取栈顶数据             \n");
        printf(" 4.清空序栈               \n");
        printf(" 5.销毁序栈               \n");
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
				initLStack(head);
				flag = 1;
				break;
			}
			else
			{
				printf("已有栈，销毁当前栈后可重新创建\n");
				break;
			}
               case 2:
                        if(flag)
                        {
                                isEmptyLStack(head);
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
				getTopLStack(head,&j);

                        }
                        else
                        {
                                printf("没有栈\n");
                        }
                        break;
                case 4:
                        if(flag)
                        {
				clearLStack(head);
                        }
                        else
                        {
                               printf("没有栈\n");
                        }
                        break;
                case 5:
                        if(flag)
                        {
                                destroyLStack(head);
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
                                LStackLength(head,&z);
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
                                pushLStack(head,i);
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
                                popLStack(head,&x);
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
