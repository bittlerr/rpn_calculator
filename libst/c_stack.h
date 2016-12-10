#ifndef C_STACK_H
# define C_STACK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int		data;
	struct s_list	*next;
} t_stack;

t_stack *nou(int n);
t_stack *push(t_stack *stack, int n);
int	pop(t_stack **stack);
void	show(t_stack *stack);

#endif
