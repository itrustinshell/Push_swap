
NAME = push_swap
ARCH = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCH)
	$(CC) $< -o $@

$(ARCH) : $(OBJS)
	$(MAKE_LIB) $(ARCH) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean :
	rm -f $(OBJS) $(ARCH)

fclean : clean
	rm -f $(NAME)

re : fclean all
