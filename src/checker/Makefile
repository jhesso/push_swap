# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 18:13:23 by jhesso            #+#    #+#              #
#    Updated: 2023/03/16 19:13:22 by jhesso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRC_PATH	=	src/
LIBFT_PATH	=	../../libft/
OBJ_PATH	=	obj/
SRC			=	checker.c operations.c utils.c stack.c stack_utils.c debug.c
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))
INCS		=	-I includes/

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
	@$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_PATH) -lft -o $(NAME) -g -fsanitize=address
	@echo "$(GREEN)done$(RESET)"

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug libft bonus
