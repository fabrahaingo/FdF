# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frahaing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 17:34:05 by frahaing          #+#    #+#              #
#    Updated: 2018/02/15 17:34:06 by frahaing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

SRC =		

OBJ =		$(SRC:.c=.o)

FLAG =		-Wall -Werror -Wextra -g

INC =		includes/

MAIN =		main.c

all :		$(NAME)

$(NAME) : $(OBJ)
			@$(MAKE) -C libft/ all
			@gcc -o $(NAME) $(FLAG) $(MAIN) $(SRC) -I $(INC) libft/libft.a

%.o: %.c
			@gcc -c $< -o $@ $(FLAG)

clean :
			@rm -f $(OBJ)
			@$(MAKE) -C libft/ clean

fclean :	clean
			@rm -f $(NAME)
			@$(MAKE) -C libft/ fclean

re :		fclean all
