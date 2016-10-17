# include "rpn_calc.h"

int main(int ac, char **av)
{
  if (ac == 2)
  {
    if (is_valid(av[1]))
      rpn_calc(av[1]);
    else
      printf("Error\n");
  }
  else
    printf("Error\n");
  return (0);
}
