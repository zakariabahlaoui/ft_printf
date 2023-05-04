NAME = libftprintf.a
CC_FLAGS = -Wall -Werror -Wextra
OBJECT_FILES= \
	ft_printf.o  ft_putnbr.o ft_putchar.o ft_print_hex.o \
	ft_putpointer.o ft_putunsigned.o  ft_putstr.o ft_strlen.o

CC = gcc

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)

fclean: clean 
	rm -f $(NAME)

re: fclean all
