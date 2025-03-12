NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = pipex.c utils.c
DEPS = pipex.h
ODIR = obj/
OBJ = $(SRC:%.c=$(ODIR)%.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re libft_comp

all: libft_comp $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

libft_comp :
	$(MAKE) -C $(LIBFT_DIR)

$(ODIR)%.o: %.c Makefile $(DEPS) | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -rf $(ODIR)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft fclean

re:
	fclean
	all
