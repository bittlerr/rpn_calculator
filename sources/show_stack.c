# include "c_stack.h"

void show_stack(c_stack *stack)
{
    while (stack)
        {
	      printf("%i ",stack->data);
	          stack = stack->next;
		    }
      printf("\n");
}
