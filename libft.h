/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:49:15 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/11 15:39:22 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_atoi(const char *nptr);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, const char *src, int size);
int		ft_strlcat(char *dst, const char *src, int size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, int len);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	ft_bzero(void *s, int n);
void	*ft_memset(void *s, int c, int n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memmove(void *dst, const void *src, int n);



#endif
