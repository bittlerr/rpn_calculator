# include "c_stack.h"

c_stack *new_element(int n)
{
  c_stack *aux;

  aux = (c_stack*)malloc(sizeof(c_stack));
  aux->data = n;
  aux->next = NULL;
  return (aux);
}
