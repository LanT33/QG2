#include "LinkStack.h"





Status initLStack(LinkStack *s)//函数外开辟空间
{

	printf("请输入要创建的栈的大小(正整数）：");
	s->count = Input();
	printf("请输入栈区数据。");
	for(int i=0;i<s->count;i++)
	{

		LinkStackPtr line=(LinkStackPtr)malloc(sizeof(StackNode));
		//新节点与头节点建立逻辑关系
		if(i == 0)
		{
			s->top = line;
			s->top->data = Input();
			s->top->next = NULL;
			printf("\n请输入下一个数据:");
			continue;
		}
		line->next = s->top;
		line->data =Input();
		//更新头指针的指向
		s->top=line;
		printf("\n请输入下一个数据:");
	}
	printf("创建成功。\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
	if(s == NULL|| s->count==0)
	{
		printf("还未创建栈\n");
		return ERROR;
	}
	else if(s->top==NULL)
	{
		printf("栈为空。\n");
		return SUCCESS;
	}
		printf("栈非空。\n");
		return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s == NULL|| s->count==0)
	{
		printf("还未创建栈\n");
		return ERROR;
	}
	if(s->top == NULL)
	{
		printf("栈以空");
		return ERROR;
	}
	*e = s->top->data;
	printf("栈顶数据为%d",*e);
	return SUCCESS;
}
Status clearLStack(LinkStack *s)
{
	if(s->top == NULL|| s->count == 0)
	{
		printf("栈已经是空的了。\n");
		return ERROR;
	}
	LinkStackPtr temp;
	while(s->top!=NULL)
	{
		temp=s->top->next;
		s->top->data=0;
		s->top=temp;
	}
	printf("清空完毕。\n");
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{	LinkStackPtr temp;
	while(s->top!=NULL)
	{
		temp=s->top->next;
		free(s->top);
		s->top=temp;
	}
	s->count=0;
	printf("完成。\n");
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)
{
	if(s->top == NULL|| s->count==0)
	{
		printf("还没有创建栈。\n");
		return ERROR;
	}
	*length = s->count;
	printf("栈的长度为%d",*length);
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->top == NULL|| s->count==0)
	{
		printf("还没有创建栈。\n");
		return ERROR;
	}

	LinkStackPtr temp;
	temp=s->top;
	for(int i=0;i<s->count;i++)
	{

		s->top=s->top->next;
		if(i+1==s->count)
		{

			printf("栈已经满了。\n");
			return ERROR;
	 	}
	 	if(s->top==NULL)
		break;
	}
	s->top=temp;
	LinkStackPtr line=(LinkStackPtr)malloc(sizeof(StackNode));
	line->next = s->top;
	line->data =data;
	//更新头指针的指向
	s->top=line;
	printf("入栈成功。\n");
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)
{
	if(s == NULL||s->count==0)
	{
		printf("还没有创建栈。\n");
		return ERROR;
	}
	if(s->top == NULL)
	{
		printf("栈以空\n");
		return ERROR;
	}
	*data=s->top->data;
	LinkStackPtr temp;
	temp=s->top->next;
	free(s->top);
	//更新头指针的指向
	s->top=temp;
	printf("数据%d出栈成功。\n",*data);
	return SUCCESS;
}

/* printStack(LinkStack *s)
{


	LinkStackPtr temp;
	temp=s->top;
	for(int i=0;i<=s->count;i++)
	{
		printf("%d|",s->top->data);
		s->top=s->top->next;
	}
	s->top=temp;
	return ;
}*/

void printStack(LinkStack * s)
{
	StackNode * p = NULL;

	for (p = s->top; p; p = p->next)
	{
		printf("|%d", p->data);
	}
	printf("\n");
	return ;
}


int Input()
{
	int num = 0;
	int status = 0;
	char str[100];
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		int i;
		for (i=0;str[i]!='\0';i++)
		{

			if (i == 0)
			{
				if (str[i]=='-'||str[i]=='+')
					continue;
			}
			else
			{
				if (str[i] < '0' || str[i] > '9')
				{
					status = ERROR;
				}
			}
		}
		if (status == ERROR)
		{
			printf("请重新正整数输入:");
		}
		else
		{
			 i = 0;
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0)
				{
					if (str[i] == '-' || str[i] == '+')
					{
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else
				{
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-')
			{
				num = -num;
			}
			// Check if the number entered is out of bounds.
			if (i>=10)
			{
				printf("超出范围，请重新输入:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}
