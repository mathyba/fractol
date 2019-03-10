# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emuckens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 17:52:27 by emuckens          #+#    #+#              #
#    Updated: 2018/06/30 04:05:21 by emuckens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRCS_GEN := button.c color.c display.c fractalize.c ft_itoa_cust.c key.c main.c env.c window.c image.c select_fractal.c
SRCS_FRACTALS := $(addprefix fractals/, barnsley.c burningship.c geonerd.c julia.c mandelbrot.c spiral.c tricorn.c)
SRCS := $(SRCS_GEN) \
	   $(SRCS_FRACTALS)

BIN := $(addprefix srcs/, $(patsubst %.c, %.o, $(SRCS)))

HEAD := includes/fractol.h
HEADDIR := includes

LIBFT := libft/libft.a
LIBFTDIR := libft/
MLX := mlx/libmlx.a
MLXDIR := mlx/

FLAGS := -Wall -Werror -Wextra
FSANI := -fsanitize=address -g
FRAMEWORKS := -framework OpenGL -framework AppKit

.PHONY: all clean fclean re simple debug

$(NAME): $(HEAD) $(LIBFT) $(BIN) $(MLX)
	@echo "\033[22;35mbuilding $(NAME)...\033[0m"
	@gcc   $(FLAGS) -o $(NAME) $(BIN) -lmlx -L $(MLXDIR) -lft -L $(LIBFTDIR) -lpthread $(FRAMEWORKS)
	@echo "\033[01;32m$(NAME) READY ! Enjoy :)\033[0m"

$(LIBFT):
	@make -s -C $(LIBFTDIR)

$(MLX):
	@make -s -C $(MLXDIR)

%.o: %.c
	@echo "\033[01;30m$(NAME)\033[0m : generating $@"
	@gcc -I $(HEADDIR) -I $(LIBFTDIR)/includes $(FLAGS) -o $@ -c $^

all:
	@make -s -C $(LIBFTDIR)
	@make -s $(NAME)

clean:
	@echo "cleaning $(NAME) binaries..."
	@rm -f $(BIN)
	@make clean -C $(LIBFTDIR)
	@echo "\033[01;34mBinaries removed from all folders.\n\033[0m"

fclean: clean
	@echo "cleaning $(NAME) executable..."
	@rm -f $(NAME)
	@echo "cleaning $(LIBFT) executable..."
	@rm -f $(LIBFT)
	@echo "cleaning $(MLX) executable..."
	@rm -f $(MLX)
	@echo "\033[01;34mAll directories now clean.\n\033[0m"

re:
	@make -s fclean
	@make -s all

simple:
	@echo "cleaning $(NAME) binaries..."
	@rm -f $(BIN)
	@make all
	@echo "cleaning $(NAME) binaries..."
	@rm -f $(BIN)
	@echo "\033[01;34mBinaries removed from all folders.\n\033[0m"


debug: $(BIN) $(HEAD)
	@echo "\033[01;31mbuilding $(NAME) in DEBUG MODE...\033[0m"
	@gcc $(FLAGS) $(FSANI) -o $(NAME) $(BIN) -lmlx -L $(MLXDIR) -lft -L $(LIBFTDIR) -lpthread $(FRAMEWORKS)
	@echo "\033[01;32m$(NAME) READY ! Enjoy :)\033[0m"
