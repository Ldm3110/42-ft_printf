# Pour compiler le projet
# cc *.h libft/libft.h utils/handlers.c *.c

# === COMPILER ====
CC = cc
CCFLAGS = -Wall -Wextra -Werror

# === PRINTF ====
PRINTF_FILES = ft_printf.c utils/handlers.c utils/function_utilities.c
OBJS = $(PRINTF_FILES:.c=.o)
NAME = printf.a

# === LIBFT ===
LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT_OBJS = $(LIBFT_FILES:.c=.o)

# === INCLUDES ===
INCLUDES = $(LIBFT_DIR)

all: $(NAME) ${LIBFT_NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_NAME): $(LIBFT_OBJS)
	ar rcs $(LIBFT_NAME) $(LIBFT_OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -I . -I $(INCLUDES) -c $< -o $@

cleanall: clean fclean

clean:
	@rm -f $(OBJS) $(LIBFT_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(LIBFT_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

