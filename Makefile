NAME			=	push_swap
BONUS_NAME		=	checker
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
SRC_PATH		=	src/
OBJ_PATH		=	obj/
SRC				=	main.c\
					input_validate.c\
					stack.c stack_utils.c\
					push_swap.c sort.c sort_utils.c move.c cost.c\
					push.c reverse_rotate.c rotate.c swap.c\
					utils.c\
					debug.c
BONUS			=	bonus/main_bonus.c\
					bonus/read_operations_bonus.c\
					input_validate.c\
					stack.c stack_utils.c\
					utils.c
SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJ				=	$(SRC:.c=.o)
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
BONUS_OBJ		=	$(BONUS: .c=.o)
BONUS_OBJS		=	$(addprefix $(OBJ_PATH), $(BONUS_OBJ))
INCS			=	-I ./include/
BONUSES			=	$(addprefix $(SRC_PATH), $(BONUS))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. -lft

bonus: $(BONUS_NAME)

$(BONUS_NAME):
	$(CC) $(CFLAGS) $(BONUSES) -o $(BONUS_NAME) -L. -lft

debug:
	$(CC) $(CFLAGS) $(SRCS) -L. -lft -g -o $(NAME)

leaks:
	$(CC) $(CFLAGS) $(SRCS) -L. -lft -o $(NAME) -g -fsanitize=address

bonus_debug:
	$(CC) $(CFLAGS) $(SRCS) -L. -lft -o $(BONUS_NAME) -g

bonus_leaks:
	$(CC) $(CFLAGS) $(BONUSES) -L. -lft -o $(BONUS_NAME) -fsanitize=address

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re debug leaks bonus
