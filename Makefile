# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:44:01 by aaibar-h          #+#    #+#              #
#    Updated: 2023/02/05 23:21:45 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME = libft.a

# Make directories
TEST_DIR = .tests
INCLUDE = .

# Sources
SRCS_BONUS = $(wildcard ft_*_bonus.c)
SRCS = $(filter-out $(SRCS_BONUS), $(wildcard ft_*.c))
# Debug target library and sources
DBG_NAME = libft_debug.a
DBG_BIN = libft_debug.bin
DBG_TESTERS = $(wildcard $(TEST_DIR)/tt_*.c)
DBG_SRCS = $(SRCS) $(SRCS_BONUS) $(DBG_TESTERS)

# Compiler and flags
# Release
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# Debug
DBG_CFLAGS = -g -lbsd

# Object files
OBJS = $(SRCS:.c=.o)
DBG_OBJS = $(SRCS:.c=_debug.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Main rules
# Define PHONY rules
.PHONY: clean fclean re

# Compile all
all: $(NAME) bonus

# Compile code with debug symbols and executable binary
debug: $(DBG_NAME)
	@$(CC) $(DBG_CFLAGS) -I $(INCLUDE) -o $(DBG_BIN) $(DBG_SRCS)

# Compile the bonus functions
bonus: $(NAME) $(OBJS_BONUS)
	@echo "Compiling bonus target"
	@ar rcs $(NAME) $(OBJS_BONUS)

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS) $(DBG_OBJS) $(OBJS_BONUS)

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(NAME) $(DBG_NAME) $(DBG_BIN)

# Re-make all, same as calling clean && all
re: fclean all

# File compiling rules
$(NAME): $(OBJS)
	@echo "Compiling release target"
	@ar rcs $(NAME) $(OBJS)

$(DBG_NAME): $(DBG_OBJS)
	@echo "Compiling debug target"
	@ar rcs $(DBG_NAME) $(DBG_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

%_debug.o: %.c
	@$(CC) $(DBG_CFLAGS) -o $@ -c $<
