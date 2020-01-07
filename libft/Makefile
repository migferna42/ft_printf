# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 16:26:57 by migferna          #+#    #+#              #
#    Updated: 2020/01/07 19:39:26 by migferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS		= ft_atoi.c					\
			  ft_bzero.c				\
			  ft_calloc.c				\
			  ft_isalnum.c				\
			  ft_isalpha.c				\
			  ft_isascii.c				\
			  ft_isdigit.c				\
			  ft_isprint.c				\
			  ft_itoa.c					\
			  ft_memccpy.c				\
			  ft_memchr.c				\
			  ft_memcmp.c				\
			  ft_memcpy.c				\
			  ft_memmove.c				\
			  ft_memset.c				\
			  ft_putchar_fd.c			\
			  ft_putendl_fd.c			\
			  ft_putnbr_fd.c			\
			  ft_putstr_fd.c			\
			  ft_putnbrlong_fd.c		\
			  ft_split.c				\
			  ft_strchr.c				\
			  ft_strdup.c				\
			  ft_strjoin.c				\
			  ft_strlcat.c				\
			  ft_strlcpy.c				\
			  ft_strlen.c				\
			  ft_strmapi.c				\
			  ft_strncmp.c				\
			  ft_strcmp.c				\
			  ft_strnstr.c				\
			  ft_strrchr.c				\
			  ft_strtrim.c				\
			  ft_substr.c				\
			  ft_tolower.c				\
			  ft_toupper.c				
SRCS_BONUS	= ft_lstadd_back_bonus.c	\
			  ft_lstadd_front_bonus.c 	\
			  ft_lstclear_bonus.c 		\
			  ft_lstdelone_bonus.c 		\
			  ft_lstiter_bonus.c 		\
			  ft_lstlast_bonus.c 		\
			  ft_lstmap_bonus.c 		\
			  ft_lstnew_bonus.c 		\
			  ft_lstsize_bonus.c

OBJS	= $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

CFLAGS += -Wall -Werror -Wextra -g
LFLAGS += -I.

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

bonus:		$(OBJS) $(OBJS_BONUS)
			$(AR) $(NAME) $(OBJS_BONUS)
			$(RANLIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)

clean:
			$(RM) ${OBJS} $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
