# include "rpn_calc.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		printf("Error\n");
	else
		rpn_calc(av[1]);
	return (0);
}
