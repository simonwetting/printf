NAME = libftprintf.a
FILENAMES = ft_printf utils
OBJECTS = $(FILENAMES:%=%.o)
FILES = $(FILENAMES:%=%.c)
CFLAGS = -Wall -Werror -Wextra -g

all: $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	cc -c $(CFLAGS) $(FILES)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

crun: re
	cc $(CFLAGS) main.c libftprintf.a; ./a.out