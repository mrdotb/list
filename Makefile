CC       = gcc
CFLAGS   = -Wall -Werror -Wextra -g
NAME     = list.a
INCLUDE = -I ./src/include
MUNIT = -I ./test/munit

# Get system and set specific flags accordingly
ARCH = $(shell uname -m)
OS   = $(shell uname -s)

SRC = \
			list_add_first.c \
			list_add_last.c \
			list_destroy.c \
			list_destroy_cb.c \
			list_new.c \
			list_remove_all.c \
			list_remove_all_cb.c \
			list_size.c \
			unlinkn.c \
			unlinkn_all.c

TEST = \
			 test/munit/munit.c \
			 test/list.c

OBJ = $(SRC:%.c=obj/%.o)

all: obj $(NAME)

$(NAME):	$(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) $(INCLUDE) $(MUNIT) $(TEST) $(NAME) -lm -o runtest
	./runtest

.PHONY: clean fclean re
