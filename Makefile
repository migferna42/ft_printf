NAME = libftprintf.a

SRCS = 

OBJS = $(SRCS:.c=.o)

CC = CC
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
