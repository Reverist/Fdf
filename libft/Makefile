# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 14:59:32 by akrivosh          #+#    #+#              #
#    Updated: 2018/11/17 13:47:59 by akrivosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = 

NAME = libft.a

SCRS = ft_itoa.c       ft_memcmp.c     ft_putnbr.c     ft_strdel.c     ft_strncat.c    ft_strsub.c \
ft_lstadd.c     ft_memcpy.c     ft_putnbr_fd.c  ft_strdup.c     ft_strncmp.c    ft_strtrim.c \
ft_atoi.c       ft_lstdel.c     ft_memdel.c     ft_putstr.c     ft_strequ.c     ft_strncpy.c    ft_swap.c \
ft_bzero.c      ft_lstdelone.c  ft_memmove.c    ft_putstr_fd.c  ft_striter.c    ft_strndup.c    ft_tolower.c \
ft_invchar.c    ft_lstiter.c    ft_memset.c     ft_sqrt.c       ft_striteri.c   ft_strnequ.c    ft_toupper.c \
ft_isalnum.c    ft_lstmap.c     ft_power.c      ft_strcat.c     ft_strjoin.c    ft_strnew.c \
ft_isalpha.c    ft_lstnew.c     ft_putchar.c    ft_strchr.c     ft_strlcat.c    ft_strnstr.c \
ft_isascii.c    ft_memalloc.c   ft_putchar_fd.c ft_strclr.c     ft_strlen.c     ft_strrchr.c \
ft_isdigit.c    ft_memccpy.c    ft_putendl.c    ft_strcmp.c     ft_strmap.c     ft_strsplit.c \
ft_isprint.c    ft_memchr.c     ft_putendl_fd.c ft_strcpy.c     ft_strmapi.c    ft_strstr.c get_next_line.c

INC = libft.h

OBJS = $(SCRS:.c=.o)
%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS) -I $(INC)

all: $(NAME)
 
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
 
clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
