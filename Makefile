# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:44:01 by aaibar-h          #+#    #+#              #
#    Updated: 2023/01/20 13:22:34 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define target library and sources
TARGET = libft.a
DBG_TARGET = libft_debug.a
DBG_BIN = libft_debug.bin
SRCS = $(wildcard ft_*.c)
DBG_SRCS = $(SRCS) libft_tester.c

# Define compiler and its flags
# Release
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# Debug
DBG_CFLAGS = -g -fno-builtin -lbsd

# Object files
OBJS = $(SRCS:.c=.o)
DBG_OBJS = $(SRCS:.c=_debug.o)

# Main rules
# Define PHONY rules
.PHONY: all debug clean fclean re

# Compile all
all: $(TARGET) $(DBG_TARGET)

# Compile code with debug symbols and executable binary
debug: $(DBG_TARGET)
	@$(CC) $(DBG_CFLAGS) -o $(DBG_BIN) $(DBG_SRCS)

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS) $(DBG_OBJS)

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(TARGET) $(DBG_TARGET) $(DBG_BIN)

# Re-make all, same as calling clean && all
re: fclean all

$(TARGET): $(OBJS)
	@echo "Compiling release target"
	@ar rcs $(TARGET) $(OBJS)

$(DBG_TARGET): $(DBG_OBJS)
	@echo "Compiling debug target"
	@ar rcs $(DBG_TARGET) $(DBG_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	
%_debug.o: %.c
	@$(CC) $(DBG_CFLAGS) -o $@ -c $<
