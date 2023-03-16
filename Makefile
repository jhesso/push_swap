# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:28:20 by jhesso            #+#    #+#              #
#    Updated: 2023/03/16 16:41:18 by jhesso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
SRC_PATH		=	src/
LIBFT_PATH		=	libft/
OBJ_PATH		=	obj/
SRC				=	main.c\
					input_validate.c\
					stack.c stack_utils.c\
					push_swap.c sort.c sort_utils.c move.c cost.c\
					push.c reverse_rotate.c rotate.c swap.c\
					utils.c\
					debug.c
SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJ				=	$(SRC:.c=.o)
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
INCS			=	-I include/

# pretty colors for the messages
GREEN			=	\033[0;32m
BLUE			=	\033[0;34m
RESET			=	\033[0m

all: libft $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_PATH) -lft
	@echo "$(GREEN)done$(RESET)"

libft:
	@$(MAKE) -C $(LIBFT_PATH)

debug:
	@echo "$(BLUE)Compiling $(NAME) for debugging$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS) -L. -lft -o $(NAME) -g -fsanitize=address
	@echo "$(GREEN)done$(RESET)"

clean:
	@echo "$(BLUE)doing some spring cleaning$(RESET)"
	@/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@echo "$(GREEN)done$(RESET)"

fclean: clean
	@echo "$(BLUE)removing $(NAME)$(RESET)"
	@/bin/rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)done$(RESET)"

re: fclean all

.PHONY: all clean fclean re debug libft
