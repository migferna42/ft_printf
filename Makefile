NAME = libftprintf.a

LIB_DIR 	= 	libft/
LIB_FILES	=	ft_atoi.c		\
				ft_bzero.c		\
				ft_calloc.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_itoa.c		\
				ft_memccpy.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_putchar_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_split.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_strjoin.c	\
				ft_strlcat.c	\
				ft_strlcpy.c	\
				ft_strlen.c		\
				ft_strmapi.c	\
				ft_strncmp.c	\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_strtrim.c	\
				ft_substr.c		\
				ft_tolower.c	\
				ft_toupper.c	 

SRC_DIR = 		src/
SRC_FILES =		ft_printf.c 	\
				handle_flags.c	\
				print_string.c	\
				print_integer.c

LIB = $(addprefix $(LIB_DIR), $(LIB_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRC_FILES:.c=.o) $(LIB_FILES:.c:.o)

LFLAGS = -Iincludes/
FLAGS = -Wall -Wextra -Werror

CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

all:	$(NAME)

$(NAME):
			@$(CC) -c $(FLAGS) $(SRC) $(LIB) $(LFLAGS)
			@$(AR) $(NAME) $(OBJS)
clean:		
	$(RM) $(OBJS)

fclean:	clean

re: fclean clean

.PHONY: all clean fclean re
