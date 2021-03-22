# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 14:13:24 by ouseqqam          #+#    #+#              #
#    Updated: 2019/10/27 14:46:18 by ouseqqam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

FLAGS = -Wall -Werror -Wextra

mlx = -lmlx -framework OpenGL -framework AppKit

FILE = get_next_line.c  ft_check.c ft_read.c bresnham.c print_map.c iso.c event.c ft_free.c main.c ft_putendl.c ft_strnew.c ft_bzero.c ft_strjoin.c ft_strsub.c ft_atoi.c ft_strchr.c ft_strlen.c ft_strdup.c ft_strsplit.c menu.c
SRC = $(FILE:.c=.o)

all:$(NAME)

$(NAME): $(SRC)
	          @cc  $(FLAGS) $(mlx) -o  $(NAME)  $(FILE)
clean:
	          @rm -f $(SRC)

fclean: clean
	          @rm -f $(NAME)

re: fclean all
