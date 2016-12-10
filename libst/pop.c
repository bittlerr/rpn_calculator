# include "c_stack.h"

int pop(t_stack **stack)
{
  int aux;
  t_stack *tmp;

  aux = 0;
  if (*stack)
  {
    aux = (*stack)->data;
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
  }
  return (aux);
}
