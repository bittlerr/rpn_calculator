#ifndef C_STACK_H
# define C_STACK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct c_list
{
	int		data;
	struct c_list	*next;
} c_stack;

c_stack *new_element(int n);
c_stack *push(c_stack *stack, int n);
int	pop(c_stack **stack);
void	show_stack(c_stack *stack);

#endif
