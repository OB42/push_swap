# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2017/11/30 10:33:39 by obenazzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, push_swap, checker, clean, fclean, re

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LFT_PATH = ./ft_printf/
INC_NAME = push_swap.h
SRC_NAME = get_next_line/get_next_line.c op_ab.c op_x.c \
fill_stack.c print_stack.c stack.c stack_sorting.c stack_utils.c \
real_mode.c arr_sort.c error.c ft_split_arg.c pr_malloc.c ft_atoi_check.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(OBJ_NAME) push_swap.o checker.o
OBJPS = $(OBJ_NAME) push_swap.o
OBJCH = $(OBJ_NAME) checker.o

all: checker push_swap

push_swap: $(OBJPS)
	@echo
	@make -C $(LFT_PATH)
	$(CC) $(CC_FLAGS) -o push_swap $(OBJPS) -lm -L $(LFT_PATH) -lft

checker: $(OBJCH)
	@echo
	@make -C $(LFT_PATH)
	$(CC) $(CC_FLAGS) -o checker $(OBJCH) -lm -L $(LFT_PATH) -lft

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f checker
	@rm -f push_swap

re: fclean all
