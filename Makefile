EXF = rpn_calculator

IPTH = includes

SPTH = sources

FILES = *.c

OBJS = *.o

LBA = includes/c_stack.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all:
	$(CC) -c $(FLAGS) $(SPTH)/$(FILES) -I $(IPTH)
	ar rvs $(LBA) *.o
	$(CC) -o $(EXF) main.c $(LBA) -I $(IPTH)

clean:
	@rm $(OBJS)

fclean: clean
	@rm $(EXF)

re:
	fclean
	all
