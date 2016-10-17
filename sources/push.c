# include "c_stack.h"

c_stack *push(c_stack *stack, int n)
{
  c_stack *el;

  el = new_element(n);
  if (!stack)
  {
    stack = el;
    return (stack);
  }
  else
    el->next = stack;
  return (el);
}
