CC       = gcc
CFLAGS   = -Wall -Werror -Wextra -g
NAME     = list.a
INCLUDES = -I ./src/include

# Get system and set specific flags accordingly
ARCH = $(shell uname -m)
OS   = $(shell uname -s)

SRC = \
			list_add_first.c \
			list_add_last.c \
			list_new.c \
			list_size.c

OBJ = $(SRC:%.c=obj/%.o)

all: obj $(NAME)

$(NAME):	$(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
