# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 01:06:07 by lyanga            #+#    #+#              #
#    Updated: 2025/10/05 15:02:52 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name and output directory
NAME        =   fractol
OUTDIR      =   .

# Compiler and flags
CC          =   cc
CFLAGS      =   -Wall -Werror -Wextra -std=gnu89
DEBUG_FLAGS =   -g -O0
RM          =   rm -f

# Source files and objects
SRCS        =   main.c \
				init.c mandelbrot.c julia.c mouse_and_keys.c utils.c draw.c burning_ship.c validate.c ft_atod.c
OBJS        =   $(SRCS:.c=.o)

# For bonus
BONUS_DIR	= bonus/
BONUS_SRCS  =   main_bonus.c \
				init_bonus.c mandelbrot_bonus.c julia_bonus.c mouse_and_keys_bonus.c utils_bonus.c draw_bonus.c burning_ship_bonus.c validate_bonus.c ft_atod_bonus.c
BONUS_DIR_SRCS = $(addprefix $(BONUS_DIR),$(BONUS_SRCS))			
BONUS_OBJS  =   $(BONUS_DIR_SRCS:.c=.o)

# Directories for external libraries
LIBFT_DIR   =   libft
MINILIBX_DIR =  minilibx-linux

# Library names and flags
LIBFT       =   $(LIBFT_DIR)/libft.a
MINILIBX    =   $(MINILIBX_DIR)/libmlx.a
MLX_FLAGS   =   -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_FLAGS =   -L$(LIBFT_DIR) -lft

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

bonus: $(LIBFT) $(MINILIBX) $(BONUS_OBJS);
	echo $(BONUS_SRCS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

# Compile C files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR)/headers -I$(MINILIBX_DIR)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build minilibx
$(MINILIBX):
	make -C $(MINILIBX_DIR)

# Clean object files
clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

# Full clean (removes executable and object files)
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild the project
re: fclean all

# Phony targets to prevent conflicts with files of the same name
.PHONY: fractol all clean fclean re libft minilibx bonus