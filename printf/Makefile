 
NAME = libftprintf.a

HEADER = ft_printf.h

CFLAGS = cc -Wall -Wextra -Werror

.DEFAULT_GOAL := all

SRCS += ft_printf.c
SRCS += ft_put_hex.c
SRCS += ft_put_nbr.c
SRCS += ft_put_un.c
SRCS += ft_putchar.c
SRCS += ft_putptr.c
SRCS += ft_putstr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJS): %.o: %.c $(HEADER)
	$(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
