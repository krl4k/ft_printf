#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 08:42:18 by fgrisell          #+#    #+#              #
#    Updated: 2020/11/19 11:05:09 by fgrisell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -c

SRC =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
	   ft_memmove.c ft_memchr.c ft_memcmp.c\
	   ft_strlen.c ft_strlcpy.c ft_strlcat.c\
	   ft_strchr.c ft_strrchr.c\
	   ft_strnstr.c ft_strncmp.c\
	   ft_atoi.c\
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
	   ft_calloc.c ft_strdup.c\
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_uint_fd.c ft_putnbr_base.c\
	   ft_strcpy.c ft_strchr_int.c \
	   ft_lennbr.c \

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
			

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: all	$(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
