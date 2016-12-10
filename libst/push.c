# include "c_stack.h"

t_stack *push(t_stack *stack, int n)
{
  t_stack *el;

  el = nou(n);
  if (!stack)
  {
    stack = el;
    return (stack);
  }
  else
    el->next = stack;
  return (el);
}
