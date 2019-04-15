# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariperez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 14:43:48 by ariperez          #+#    #+#              #
#    Updated: 2019/04/02 19:37:17 by ariperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re main norme

NAME	=	libftprintf.a

SRC_DIR =	./srcs
INC_DIR =	./includes
OBJ_DIR =	./objs
LIB_DIR	=	./libft

INC_NAME=	libftprintf.h
SRC_NAME=	ft_printf.c parsing.c tools.c print_speci.c
OBJ_NAME=	$(SRC_NAME:.c=.o)
LIB_NAME=	ft_strlen.c ft_strcpy.c ft_strcat.c ft_atoi.c \
			ft_itoa.c ft_putchar.c ft_putstr.c ft_putstr_fd.c \
			ft_convert_base.c ft_strjoinfree.c ft_strdup.c
LIB_OBJ	=	$(LIB_NAME:.c=.o)

INC		=	$(addprefix $(INC_DIR)/, $(INC_NAME))
SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ		=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
LIB		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME))
OBJLIB	=	$(addprefix $(OBJ_DIR)/, $(LIB_OBJ))

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "\033[1;41m#################################################################################\033[0m"
	@echo "\033[1;33m   FFFFFFF TTTTTTT               PPPPPP  RRRRRR  IIIII NN   NN TTTTTTT FFFFFFF \033[0m"
	@echo "\033[1;33m   FF        TTT                 PP   PP RR   RR  III  NNN  NN   TTT   FF      \033[0m"
	@echo "\033[1;33m   FFFF      TTT                 PPPPPP  RRRRRR   III  NN N NN   TTT   FFFF    \033[0m"
	@echo "\033[1;33m   FF        TTT                 PP      RR  RR   III  NN  NNN   TTT   FF      \033[0m"
	@echo "\033[1;33m   FF        TTT     _________   PP      RR   RR IIIII NN   NN   TTT   FF      \033[0m"
	@echo "\033[1;41m#################################################################################\033[0m"
	@gcc -c $(FLAGS) $(SRC) $(LIB)
	@mv $(OBJ_NAME) $(LIB_OBJ) $(OBJ_DIR)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@echo "\033[1;32mlibftprintf is ready.\033[0m"

clean:
	@rm -f $(OBJ) $(OBJLIB)
	@echo "\033[1;31mObject files has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f test
	@echo "\033[1;31mlibftprintf library has been deleted.\033[0m"

re: fclean all

main:
	@gcc $(SRC) $(NAME) -o test
	@echo "Test main has been created."

norme:
	@echo "\033[1;33mNorminette\033[0m"
	@norminette $(INC) $(LIB) $(SRC)
