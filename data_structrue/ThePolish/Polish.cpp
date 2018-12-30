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
		printf("ջ�����");
		return;
	}
	ms->data[++ms->top] = e;
}

void PopStack(MStack *ms, char *e)
{
	if (ms->top == -1)
	{
		printf("ջ�գ�");
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
	char above = 9;//������һ�ε�����ֵ�����������ʽ�Ƿ�Ϸ�
	char c;
	char num;
	int e;
	c = getchar();
	//�����ǽ���ͨ��׺���ʽ��Ϊ��׺���ʽ
	while (1)
	{
		e = 0;
		//if (c == '\n')
		//{
			//if (!(above != ')' || (above <= '9' && above >= '0')))
			//{
			//	printf("������ʽ�д�������������д˳���");
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
					printf("������ʽ�д�������������д˳���");
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
				printf("������ʽ�д�������������д˳���");
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
					printf("������ʽ�д�������������д˳���");
					return -1;
				}
				PushStack(ms, c);
			}
			if (c == ')')
			{
				if (above < '0' || above > '9')
				{
					printf("������ʽ�д�������������д˳���");
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
	//�����Ǽ��㲿��
	while (ms->top != -1)
	{
		if (ms->data[ms->top] <= '0' + 255 && ms->data[ms->top] >= '0')//ԭ�����ݷ�Χ��'0'-'9'�����Ҫ����10��������Ҫ�Ӵ�Ϊ'0'-'0'+255
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
