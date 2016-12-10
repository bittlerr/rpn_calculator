# include "c_stack.h"

int is_s(int ch)
{
		return (ch == '-' || ch == '+');
}

int is_n(int ch)
{
		return ((ch >= '0') && (ch <= '9'));
}

int is_op(int op)
{
	return ((op == '*') || (op == '/') || (op == '+') || (op == '-')
			|| (op == '%'));
}

int is_v(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!(is_op(str[i]) || is_n(str[i]) || is_s(str[i])
					|| str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int do_op(int a, int b, int c)
{
  if (c == '*')
    return (a * b);
  if (c == '/')
    return (a / b);
  if (c == '+')
    return (a + b);
  if (c == '-')
    return (a - b);
  return (a % b);
}

void rpn_calc(char *str)
{
	char *buff = (char*)malloc(sizeof(char) * 60);
	int i;
	int nr;
	int nr1;
	int nr2;
	int nrop;
	int nrn;
	t_stack *st = NULL;

	i = 0;
	nrop = 0;
	nrn = 0;
	if (is_v(str))
	{
		while (str[i])
		{
			if (((i - 1 != 0) && str[i-1] == ' ' && is_s(str[i])
			&& is_n(str[i+1])) || ((i - 1 < 0) && is_s(str[i])
				&& is_n(str[i+1]))	|| is_n(str[i]))
			{
				nr = 0;
				if (is_s(str[i]))
					buff[nr++] = str[i++];
				while (is_n(str[i]))
					buff[nr++] = str[i++];
				buff[nr] = '\0';
				st = push(st, atoi(buff));
				nrn++;
			}
			else if (((i - 1 != 0) && str[i-1] != ' '
					&& is_s(str[i]) && is_n(str[i+1])))
			{
				printf("Error\n");
				return;
			}
			if (is_op(str[i]) && (i - 1 > -1) && str[i - 1] == ' '
					&& !is_n(str[i+1]))
			{
				nrop++;
				if (nrop > nrn - 1)
				{
					printf("Error\n");
					return;
				}
				nr1 = pop(&st);
				nr2 = pop(&st);
				if (nr1 == 0 && (str[i] == '/' ||
							str[i] == '%'))
				{
					printf("Error\n");
					return;
				}
				st = push(st, do_op(nr2, nr1, str[i]));
			}
			if (is_op(str[i]) && (i - 1 > -1) && is_n(str[i -1])
					&& is_n(str[i+1]))
			{
				printf("Error\n");
				return;
			}
			if (is_op(str[i]) && (i - 1 > -1) && is_n(str[i -1])
					&& str[i+1] == ' ')
			{
				printf("Error\n");
				return;
			}
			i++;
		}
		if (nrop == nrn - 1)
			show(st);
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
}
