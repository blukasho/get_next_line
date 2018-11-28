# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 12:56:17 by blukasho          #+#    #+#              #
#*   Updated: 2018/11/05 00:29:17 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS = ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strlen_chr.c\
	   ft_strndup.c ft_strnew.c ft_memset.c ft_memalloc.c

OBJ = ft_strdel.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_strlen_chr.o\
	  ft_strndup.o ft_strnew.o ft_memset.o ft_memalloc.o

GCC = gcc -Wall -Wextra -Werror -I includes -std=c99

NAME = libft.a

all: $(NAME)

$(NAME):
	$(GCC) -c $(SRCS)
	ar -rv $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all makelib clean fclean re
