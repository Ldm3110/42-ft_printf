# Pour compiler le projet
# cc *.h libft/libft.h utils/handlers.c *.c

# === COMPILER ====
CC = cc
CCFLAGS = -Wall -Wextra -Werror

# === PRINTF ====
PRINTF_FILES = ft_printf.c \
			   utils/handlers.c \
			   utils/function_utilities.c \
			   utils/hexa_handlers.c

OBJS = $(PRINTF_FILES:.c=.o)
NAME = libftprintf.a

# === LIBFT ===
LIBFT_DIR = libft
LIBFT_NAME = ./libft/libft.a
#LIBFT_OBJS = $(LIBFT_FILES:.c=.o)

# === INCLUDES ===
INCLUDES = $(LIBFT_DIR)

all: $(NAME) ${LIBFT_NAME}

$(NAME): $(OBJS) $(LIBFT_NAME)
	cp $(LIBFT_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT_NAME): 
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(LIBFT_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(LIBFT_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

