# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:44:01 by alexaib           #+#    #+#              #
#    Updated: 2023/01/14 20:12:42 by alexaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define target library and sources
TARGET = libft.a
DBG_TARGET = libft_debug.a
DBG_BIN = libft_debug.bin
SRCS = $(wildcard ft_*.c)
DBG_SRCS = $(SRCS)
DBG_SRCS += libft_tester.c

# Define compiler and its flags
# Release
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# Debug
DBG_CFLAGS = -g -fno-builtin -lbsd

# Object files
OBJS = $(SRCS:.c=.o)
DBG_OBJS = $(SRCS:.c=_debug.o)

all: $(TARGET) $(DBG_TARGET)

debug: $(DBG_TARGET)
	$(CC) $(DBG_CFLAGS) -o $(DBG_BIN) $(DBG_SRCS)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

$(DBG_TARGET): $(DBG_OBJS)
	ar rcs $(DBG_TARGET) $(DBG_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%_debug.o: %.c
	$(CC) $(DBG_CFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET) $(OBJS) $(DBG_TARGET) $(DBG_OBJS) $(DBG_BIN)
