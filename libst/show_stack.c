# include "c_stack.h"

void show(t_stack *st)
{
	while (st)
		printf("%i\n", pop(&st));
}
