#include"stdio.h"
#include"stdlib.h"
#include"memory.h"

#define MAXSIZE 100

typedef struct MStack
{
	char data[MAXSIZE];
	int top;
};

MStack *InitStack()
{
	MStack *ms;
	ms = (MStack*)malloc(sizeof(MStack));
	memset(ms->data, 0, MAXSIZE);
	ms->top = -1;
	return ms;
}

void PushStack(MStack *ms, char e)
{
	if (ms->top == MAXSIZE - 1)
	{
		printf("栈满溢出");
		return;
	}
	ms->data[++ms->top] = e;
}

void PopStack(MStack *ms, char *e)
{
	if (ms->top == -1)
	{
		printf("栈空！");
		return;
	}
	*e = ms->data[ms->top--];
}

int main()
{
	MStack *ms;
	MStack *msn;
	msn = InitStack();
	ms = InitStack();
	int e = 1;
	char c;
	char num;
	c = getchar();
	while (1)
	{
        if (c == '\n')
        break;
        PushStack(ms, c);
        c = getchar();
	}
	/*PushStack(ms, '+');
	PushStack(ms, '/');
	PushStack(ms, '2');
	PushStack(ms, '8');
	PushStack(ms, '+');
	PushStack(ms, '*');
	PushStack(ms, '3');
	PushStack(ms, '-');
	PushStack(ms, '1');
	PushStack(ms, '3');
	PushStack(ms, '9');
	//以下是计算部分
	while (ms->top != -1)
	{
		if (ms->data[ms->top] <= '9' && ms->data[ms->top] >= '0')
		{
			PopStack(ms, &c);
			PushStack(msn, c);
		}
		if (ms->data[ms->top] == '+')
		{
		    PopStack(ms,&c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (int)(num - '0') + (int)(c - '0') + '0';
			PushStack(msn, num);
		}
		if (ms->data[ms->top] == '-')
		{
		    PopStack(ms,&c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (int)(num - '0') - (int)(c - '0') + '0';
			PushStack(msn, num);
		}
		if (ms->data[ms->top] == '/')
		{
		    PopStack(ms,&c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (char)(int)(num - '0') / (int)(c - '0') + '0';
			PushStack(msn, num);
		}
		if (ms->data[ms->top] == '*')
		{
		    PopStack(ms,&c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (int)(c - '0')*(int)(num - '0') + '0';
			PushStack(msn, num);
		}
	}
	printf("%d", msn->data[msn->top] - '0');*/
	return 0;
}
