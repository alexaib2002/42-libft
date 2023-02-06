# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:44:01 by aaibar-h          #+#    #+#              #
#    Updated: 2023/02/06 18:34:33 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME = libft.a
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Sources
SRCS = $(filter-out $(SRCS_BONUS), $(wildcard ft_*.c))
SRCS_BONUS = $(wildcard ft_*_bonus.c)

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

# Main rules
# Define PHONY rules
.PHONY: bonus clean fclean re

# Compile all
all: $(NAME)

# Compile the bonus functions
bonus: $(NAME)
	@echo "Compiling bonus target"
	@make $(NAME) SRCS="$(SRCS) $(SRCS_BONUS)"

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS) $(OBJS_BONUS)

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(NAME)

# Re-make all, same as calling clean && all
re: fclean all

# File compiling rules
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
