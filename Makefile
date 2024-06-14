# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 01:02:31 by tnakas            #+#    #+#              #
#    Updated: 2024/06/14 15:20:56 by tnakas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME := fractol
CC := cc
CFLAGS := -Wextra -Wall -Werror
LIBMLX := ./MLX42
LIBFT_DIR := ./libft
FT_PRINTF_DIR := ./ft_printf
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT_DIR) \
           -I $(FT_PRINTF_DIR)
LIBS := $(LIBMLX)/build/libmlx42.a -framework Cocoa -framework \
		OpenGL -framework IOKit -Iinclude \
		-lglfw -L"$ENV{HOME}/.brew/include/" \
        $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a
SRC := $(wildcard ./src/*.c)
OBJS_PATH := ./objs
OBJS := $(patsubst ./src/%.c,$(OBJS_PATH)/%.o,$(SRC))

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[1;33m
BLUE := \033[0;34m
RESET := \033[0m

all: MLX42 $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a \
     libmlx $(OBJS) $(NAME)
	@echo "$(GREEN)All compilation targets completed \
	successfully!$(RESET)"

libmlx:
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build \
	&& cmake --build $(LIBMLX)/build -j4 > /dev/null \
	&& echo "$(BLUE)Library MLX42 compiled successfully!$(RESET)"

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)" > /dev/null \
	&& echo "$(BLUE)Library libft compiled successfully!$(RESET)"

$(FT_PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF_DIR) CFLAGS="$(CFLAGS)" > /dev/null \
	&& echo "$(BLUE)Library ft_printf compiled successfully!$(RESET)"

$(OBJS_PATH)/%.o: ./src/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< \
	&& printf "$(YELLOW)Compiling: $(notdir $<)$(RESET)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone \
	https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF_DIR) clean > /dev/null
	@echo "$(RED)Cleaning completed!$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean > /dev/null
	@rm -f $(NAME)
	@echo "$(RED)Full cleaning completed!$(RESET)"

re: fclean all
	@echo "$(YELLOW)Rebuilding completed!$(RESET)"

.PHONY: all clean fclean re libmlx
