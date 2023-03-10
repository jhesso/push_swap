NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRC_PATH	=	src/
OBJ_PATH	=	obj/
SRC			=	main.c\
				input_validate.c\
				stack.c stack_utils.c\
				push_swap.c sort.c sort_utils.c move.c cost.c\
				push.c reverse_rotate.c rotate.c swap.c\
				utils.c\
				debug.c
SRCS	=		$(addprefix $(SRC_PATH), $(SRC))
OBJ		=		$(SRC:.c=.o)
OBJS	=		$(addprefix $(OBJ_PATH), $(OBJ))
INCS	=		-I ./include/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. -lft

debug:
	$(CC) $(CFLAGS) $(SRCS) -L. -lft -g -o $(NAME)

leaks:
	$(CC) $(CFLAGS) $(SRCS) -L. -lft -o $(NAME) -fsanitize=address

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
