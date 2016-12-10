CC = gcc

SRC = main.c rpn_calc.c

FLAGS = -Wall -Wextra -Werror

NAME = rpn_calculator

LI = -I./libst
LL = -L./libst -lst
LST = ./libst/libst.a

SD = ./src/
ID = ./includes/
OD = ./obj/

OBJ = $(addprefix $(OD), $(SRC:.c=.o))

all: $(NAME)

obj: 
		mkdir -p $(OD)

$(OD)%.o:$(SD)%.c
		$(CC) $(FLAGS) -o $@ -c $< $(LI) -I $(ID)

libst: $(LST)

$(LST):
		make -C ./libst

$(NAME): obj libst $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LL)

clean:
		rm -rf $(OD)
			make fclean -C ./libst

fclean: clean
		rm -rf $(NAME)
			make fclean -C ./libst

re: fclean all
