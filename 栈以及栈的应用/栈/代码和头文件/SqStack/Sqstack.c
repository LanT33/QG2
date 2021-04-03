#include "SqStack.h"

Status initStack(SqStack *s,int sizes)//初始化栈
{
	s->elem=(ElemType *)malloc(sizeof(ElemType));
	if(s->elem==NULL)
	{
		printf("内存不足,创建失败。");
		return ERROR;
	}
	if(sizes<=0)
	{
		printf("栈大小要大于零。");
		return ERROR;
	}
	s->size=sizes;
	s->top=-1;
	printf("请输入栈区数据。");
	for(int i=0;i<sizes;i++)
	{
		s->elem[i]=Input();
		if(i==sizes-1)
		{
			printf("到顶了\n");//加个是否扩展栈空间？
			s->top = i;
			break;
		}
		printf("请输入下一个数据:");
	}

	printf("成功创建\n");
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
	if(s == NULL|| s->top==-1)
	{
		printf("栈为空。\n");
		return SUCCESS;
	}
		printf("栈非空。\n");
		return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)
{
	if(s == NULL|| s->size==0)
	{
		printf("还未创建栈\n");
		return ERROR;
	}
	if(s->top == -1)
	{
		printf("栈以空");
		return ERROR;
	}
	*e = s->elem[s->top];
	printf("栈顶数据为%d",*e);
	return SUCCESS;
}

Status clearStack(SqStack *s)
{
	if(s == NULL|| s->top==-1)
	{
		printf("栈已经是空的了。\n");
		return ERROR;
	}
	s->top =-1;
	printf("清空完毕。\n");
	return SUCCESS;
}

Status destroyStack(SqStack *s)
{
	if(s == NULL|| s->size==0)
	{
		printf("还没有创建栈。\n");
		return ERROR;
	}
		s->size=0;
		free(s->elem);
		s->elem = NULL;
		printf("完成。\n");
		return SUCCESS;
}


Status stackLength(SqStack *s,int *length)
{
	if(s == NULL|| s->top==-1)
	{
		printf("还没有创建栈。\n");
		return ERROR;
	}
	* length =s->size;
	printf("栈的长度为%d",*length);
	return SUCCESS;
}


Status pushStack(SqStack *s,ElemType data)
{
	if(s == NULL|| s->size==0)
	{
		printf("还没有创建栈。\n");
		return ERROR;
	}
	if(s->top == s->size-1)
	{
		printf("栈已经满了。\n");
		return ERROR;
	}

	s->elem[++s->top]=data;
	printf("入栈成功。\n");
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)
{
	if(s == NULL|| s->size==0)
	{
		printf("还没有创建栈.\n");
		return ERROR;
	}
	if(s->top == -1)
	{
		printf("栈已经空了。\n");
		return ERROR;
	}
	*data = s->elem[s->top--];
	printf("数据%d已出栈",*data);
	return SUCCESS;
}


void printStack(SqStack *s)
{
	for(int i=0;i<=s->top;i++)
	{
		printf("%d|",s->elem[i]);
	}
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
			printf("请重新输入整数:");
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

