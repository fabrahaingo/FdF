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

SRC =		srcs/parse_map.c \
			srcs/put_error.c \
			srcs/get_fullmap.c \
			srcs/rendering/rendering.c \
			srcs/rendering/draw_line.c \
			srcs/rendering/fill_pixel.c \
			srcs/rendering/modify_pix.c

OBJ =		$(SRC:.c=.o)

FLAG =		-Wall -Werror -Wextra -g

INC =		includes/

MAIN =		srcs/main.c

all :		$(NAME)

$(NAME) : $(OBJ)
			@$(MAKE) -C libft/ all
			@gcc -o $(NAME) $(FLAG) $(MAIN) $(SRC) -I $(INC) libft/libft.a -L \
			/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

%.o: %.c
			@gcc -c $< -o $@ $(FLAG)

clean :
			@rm -f $(OBJ)
			@$(MAKE) -C libft/ clean

fclean :	clean
			@rm -f $(NAME)
			@$(MAKE) -C libft/ fclean

re :		fclean all
