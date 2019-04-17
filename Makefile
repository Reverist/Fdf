CC = gcc

NAME = fdf

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADERS = incl

SOURCES =	hooka.c \
			image.c \
			main.c \
			matrices.c \
			menu.c \
			parse_n_process.c \
			point.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@$(CC) -g $(FLAGS) -L $(LIBFT) -lft -o $@ $^ -lmlx -framework OpenGL -framework AppKit

obj:
		@mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
		@$(CC) -g $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
		@rm -f $(OBJS)
		@make clean -C $(LIBFT)
		@rm -rf $(DIR_O)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re: fclean all
