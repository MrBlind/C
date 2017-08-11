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

int PriCal(char c)
{
	if (c == '-' || c == '+')return 1;
	if (c == '*' || c == '/')return 2;
	if (c == '(' || c == ')')return 3;
	return false;
}

int main()
{
	MStack *ms;
	MStack *msn;
	msn = InitStack();
	ms = InitStack();
	char above = 9;//保存上一次的输入值，检测输入算式是否合法
	char c;
	char num;
	int e;
	c = getchar();
	//以下是将普通中缀表达式改为后缀表达式
	while (1)
	{
		e = 0;
		//if (c == '\n')
		//{
			//if (!(above != ')' || (above <= '9' && above >= '0')))
			//{
			//	printf("输入算式有错，请检查后重新运行此程序！");
			//	return -1;
			//}
			//while (ms->top != -1)
			//{
			//	PopStack(ms, &c);
			//	PushStack(msn, c);
			//}
			//break;
		//}
		if (c <= '9' && c >= '0')
		{
			if (ms->top != -1)
			{
				if (above != '+' && above != '-' && above != '*' && above != '/' && above != '(')
				{
					printf("输入算式有错，请检查后重新运行此程序！");
					return -1;
				}
			}
			while (c <= '9' && c >= '0')
			{
				e = e * 10 + c - '0';
				above = c;
				c = getchar();
			}
			PushStack(msn, (char)(e + '0'));
		}
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (!(above != ')' || (above <= '9' && above >= '0')))
			{
				printf("输入算式有错，请检查后重新运行此程序！");
				return -1;
			}
			if (ms->top == -1)
				PushStack(ms, c);
			else if (PriCal(ms->data[ms->top]) >= PriCal(c))
			{
				while (PriCal(ms->data[ms->top]) >= PriCal(c))
				{
					if (ms->data[ms->top] == '(')break;
					num = c;
					PopStack(ms, &num);
					PushStack(msn, num);
				}
				PushStack(ms, c);
			}
			else PushStack(ms, c);
		}
		if (c == '(' || c == ')')
		{
			if (c == '(')
			{
				if (above != '+' &&above != '-' &&above != '*' &&above != '/'&&ms->top != -1)
				{
					printf("输入算式有错，请检查后重新运行此程序！");
					return -1;
				}
				PushStack(ms, c);
			}
			if (c == ')')
			{
				if (above < '0' || above > '9')
				{
					printf("输入算式有错，请检查后重新运行此程序！");
					return -1;
				}
				while (c != '(')
				{
					PopStack(ms, &c);
					if (c != '(')
						PushStack(msn, c);
				}
			}
		}
		above = c;
		if (c == '\n')break;
		else c = getchar();
	}
	while (msn->top != -1)
	{
		PopStack(msn, &c);
		PushStack(ms, c);
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
	PushStack(ms, '9');*/
	//以下是计算部分
	while (ms->top != -1)
	{
		if (ms->data[ms->top] <= '0' + 255 && ms->data[ms->top] >= '0')//原本数据范围是'0'-'9'，如果要计算10以外则需要加大为'0'-'0'+255
		{
			PopStack(ms, &c);
			PushStack(msn, c);
		}
		if (ms->data[ms->top] == '+')
		{
			PopStack(ms, &c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (int)(num - '0') + (int)(c - '0') + '0';
			PushStack(msn, num);
		}
		if (ms->data[ms->top] == '-')
		{
			PopStack(ms, &c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (int)(num - '0') - (int)(c - '0') + '0';
			PushStack(msn, num);
		}
		if (ms->data[ms->top] == '/')
		{
			PopStack(ms, &c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (char)(int)(num - '0') / (int)(c - '0') + '0';
			PushStack(msn, num);
		}
		if (ms->data[ms->top] == '*')
		{
			PopStack(ms, &c);
			PopStack(msn, &c);
			PopStack(msn, &num);
			num = (int)(c - '0')*(int)(num - '0') + '0';
			PushStack(msn, num);
		}
	}
	printf("%d", msn->data[msn->top] - '0');
	return 0;
}
