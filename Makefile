# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:44:01 by alexaib           #+#    #+#              #
#    Updated: 2023/01/14 19:24:43 by alexaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define target library and sources
TARGET = libft.a
DBG_TARGET = libft_debug.a
SRCS = ft_isalnum.c  ft_isascii.c  ft_isprint.c  ft_strlcat.c ft_strlen.c ft_isalpha.c  ft_isdigit.c  ft_strchr.c   ft_strlcpy.c

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

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

$(DBG_TARGET): $(DBG_OBJS)
	ar rcs $(DBG_TARGET) $(DBG_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%_debug.o: %.c
	$(CC) $(DBG_CFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET) $(OBJS) $(DBG_TARGET) $(DBG_OBJS)
