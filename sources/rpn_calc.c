# include "c_stack.h"

int is_numb(int c)
{
  return (c >= '0' && c <= '9');
}

int is_op(int c)
{
  return (c == '*' || c == '/' || c == '+' || c == '-' || c == '%');
}

int is_valid(char *str)
{
  while (*str)
  {
    if (*str == ' ' || is_numb(*str) || is_op(*str))
      str++;
    else
      return (0);
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
  c_stack *stack = NULL;
  int i;
  int j;
  char ch[50];
  int nr1 = 0;
  int nr2 = 0;
  int t1,t2;

  i = 0;
  while (str[i])
  {
    while (!is_op(str[i]))
    {
      j = 0;
      while (is_numb(str[i]))
      {
	ch[j] = str[i];
	j++;
	i++;
      }
      ch[j] = '\0';
      stack = push(stack, atoi(ch));
      nr1++;
      while (str[i] == ' ')
	i++;
    }
    if (is_op(str[i]))
    {
      t2 = pop(&stack);
      t1 = pop(&stack);
      if (t2 == 0 && str[i] == '/')
      {
	printf("Error\n");
	return;
      }
      stack = push(stack, do_op(t1, t2, str[i]));
      i++;
      nr2++;
    }
    while (str[i] == ' ')
      i++;
  }
  if (--nr1 == nr2)
    printf("%i\n", stack->data);
  else
    printf("Error\n");
}
