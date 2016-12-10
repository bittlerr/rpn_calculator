# include "c_stack.h"

t_stack		*nou(int data)
{
	t_stack	*aux = (t_stack*)malloc(sizeof(t_stack));

	aux->data = data;
	aux->next = NULL;
	return (aux);
}
