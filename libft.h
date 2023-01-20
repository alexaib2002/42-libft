/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:49:15 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/20 17:22:55 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# ifndef CAPS_PAD
#  define CAPS_PAD 'a' - 'A'
# endif
# ifndef NUMS_PAD
#  define NUMS_PAD '0'
# endif

/*******************
* Checker functions
*****************/

/**
 * @brief Checks if given character is an alphabetic character
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isalpha(int c);
/**
 * @brief Checks if given character is a digit (0-9)
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isdigit(int c);
/**
 * @brief Checks if given character is an alphanumeric character, equivalent to
 * (isalpha(c) || isdigit(c)
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isalnum(int c);
/**
 * @brief Checks if given character is a valid ASCII one
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isascii(int c);
/**
 * @brief Checks if given character is printable (displays something on screen)
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isprint(int c);
/**
 * @brief Checks if given character is an uppercase letter
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isupper(int c);
/**
 * @brief Checks if given character is a lowercase letter
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_islower(int c);

/******************
* String functions
****************/

/**
 * @brief Calculates the length of a given string, excluding the NUL character
 * @param s Given string
 * @return Total length of the string
 */
int		ft_strlen(const char *s);
/**
 * @brief Copies up to (size - 1) a NUL-terminated source string, into a given
 *  destination, NUL-terminating the result.
 * @param dst Pointer to destination
 * @param src Source string
 * @param size Byte number about to copy, including the NUL terminator
 * @return Total length of the string attempted to create on dst. This value
 * should be validated against the real size of dst, for detecting truncation
 */
int		ft_strlcpy(char *dst, const char *src, int size);
/**
 * @brief Appends the NUL-terminated string src to the end of NUL-terminated
 * string dst. At most, (size - strlen(dst) - 1) bytes will be appended,
 * NUL-terminating the result afterwards.
 * @param dst NUL-terminated destination string
 * @param src NUL-terminated source string
 * @param size Byte number of the source string
 * @return Total length of the string attempted to create. Note that if after
 * traversing size characters without finding the NUL char, size will be
 * considered as the string size, and the dst string won't be NUL-terminated.
 */
int		ft_strlcat(char *dst, const char *src, int size);
/**
 * @brief Tries to locate the first occurrence of a character in a given string.
 * Note that NUL terminator is considered as part of the string.
 * @param s String about to be probed
 * @param c Searched character
 * @return Returns a pointer to the matched character, or NULL if it's not
 * found.
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief Tries to locate the last occurrence of a character in a given string.
 * Note that NUL terminator is considered as part of the string.
 * @param s String about to be probed
 * @param c Searched character
 * @return Returns a pointer to the matched character, or NULL if it's not
 * found.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief Locates the first occurrence of the NUL-terminated string 'little'
 * in the string 'big', searching at most 'len' characters, nor characters after
 * a NUL terminator.
 * @param big String where the search will be performed
 * @param little String to be found on 'big'
 * @param len Number of characters that should be searched
 * @return Pointer to the first character of the first occurrence of little on
 * big.
 * Big when little is an empty string, or NULL when little is not found on
 * 'big'.
 */
char	*ft_strnstr(const char *big, const char *little, int len);
/**
 * @brief Compares two strings 's1' and 's2' up to at most 'n' bytes.
 * @param s1 First string
 * @param s2 Second string
 * @param n Number of bytes to be compared.
 * @return 0 if s1 and s2 are equal.
 * Negative value if s1 is less than s2.
 * Positive value if s1 is greater than s2.
 * Note that this implementation will return the arithmetic result of the last
 * compared byte substraction between s1 and s2.
 */
int		ft_strncmp(const char *s1, const char *s2, int n);
/**
 * @brief Given a string, converts it to an integer.
 * @param nptr pointer to string about to be converted
 * @return Converted value, or 0 in case of error.
 */
int		ft_atoi(const char *nptr);
/**
 * @brief Generates a string from a given signed integer. The resulting string
 * is generated with malloc.
 * @param n Given signed integer
 * @return Resulting string, or NULL if malloc fails. If some error happens
 * during conversion, the resulting string will be the number up until that
 * point (can be an empty string).
 */
char	*ft_itoa(int n);
/**
 * @brief Converts a valid lower-case letter referenced by the char to its
 * corresponding upper-case one.
 * @param c Given character
 * @return The converted letter, or 'c' if the conversion was not possible
 */
int		ft_toupper(int c);
/**
 * @brief Converts a valid upper-case letter referenced by the char to its
 * corresponding lower-case one.
 * @param c Given character
 * @return The converted letter, or 'c' if the conversion was not possible
 */
int		ft_tolower(int c);
/**
 * @brief Duplicate a string, allocating memory for it with malloc.
 * @param s1 String to be duplicated
 * @return Pointer to the duplicated string, or NULL if the allocation failed.
 */
char	*ft_strdup(const char *s1);
/**
 * @brief Returns a new string created from the original string 's' with an
 * offset delimited by 'start' with 'len' characters. If 'len' is greater than
 * the size of 's', the resulting substring will be ended by the NUL terminator
 * of 's'.
 * @param s String for creating the substring
 * @param start Substring offset
 * @param len Length of substring
 * @return Pointer to the new string. NULL when memory cannot be allocated.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len);
/**
 * @brief Concatenates two strings 's1' and 's2' into a new one allocated with
 * malloc.
 * @param s1 First string
 * @param s2 Last string
 * @return Pointer to the new string. NULL when memory cannot be allocated.
 */
char	*ft_strjoin(const char *s1, const char *s2);
/**
 * @brief
 * @param s1
 * @param set
 * @return
 */
char	*ft_strtrim(const char *s1, const char *set);
/**
 * @brief
 * @param s
 * @param c
 * @return
 */
char	*ft_split(const char *s, char *c);
/**
 * @brief
 * @param s
 * @param f
 * @return
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_striteri(char *s, void (*f)(unsigned int, char*));

/******************
* Memory functions
****************/

/**
 * @brief Erases data in the 'n' bytes of memory, starting at the location
 * pointed by 's', by writing zeroes to that area.
 * @param s Memory location about to be erased
 * @param n Byte number to be erased
 */
void	ft_bzero(void *s, int n);
/**
 * @brief Fills memory referenced by 's' with a constant byte 'c' up to 'n'
 * bytes.
 * @param s Memory area to be filled
 * @param c Constant byte
 * @param n Number of bytes to be filled
 * @return Pointer to the filled memory area 's'.
 */
void	*ft_memset(void *s, int c, int n);
/**
 * @brief Searches memory location 's' for the first ocurrence of byte 'c',
 * up to 'n' bytes.
 * @param s Memory area to be searched
 * @param c Given byte
 * @param n Number of bytes about to be searched.
 * @return Pointer to the matching byte, or NULL if the byte was not
 * found.
 */
void	*ft_memchr(const void *s, int c, int n);
/**
 * @brief Copies the first 'n' bytes from memory area 'src' to memory area
 * 'dest'.
 * Note the memory areas should not overlap. ft_memmove should be used on that
 * case.
 * @param dst Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes about to be copied.
 * @return Pointer to 'dst'.
 */
void	*ft_memcpy(void *dst, const void *src, int n);
/**
 * @brief Compares the first 'n' bytes, interpreted as unsigned char of the
 * memory areas s1 and s2.
 * @param s1 First memory area
 * @param s2 Second memory area
 * @param n Number of bytes to compare
 * @return Integer resulting from the difference between the pair of bytes
 * differing in s1 and s2.
 */
int		ft_memcmp(const void *s1, const void *s2, int n);
/**
 * @brief Copies 'n' bytes from memory area pointed by 'src' to memory area
 * 'dst'. Memory areas can overlap; initially the copy goes into a
 * temporary array without any overlapping and afterwards its moved to 'dest'.
 *
 * Note that this doesn't remove the src data, as such the src pointer
 * should be considered as unreliable after calling this function.
 * @param dst Destination memory area
 * @param src Source memory area
 * @param n Number of bytes about to be moved
 * @return Pointer to 'dst' memory area.
 */
void	*ft_memmove(void *dst, const void *src, int n);
/**
 * @brief Allocates memory for an array of 'count' elements, each of them
 * 'size' bytes long, and initializes all its bits to zero. Checks for integers
 * overflows with given parameters and zero values
 * @param count Number of elements to be allocated
 * @param size Size of each element
 * @return Pointer to the allocated memory, or NULL if the allocation failed.
 */
void	*ft_calloc(size_t count, size_t size);

/***************************
* File descriptor functions
*************************/

/**
 * @brief
 * @param c
 * @param fd
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief
 * @param s
 * @param fd
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief
 * @param s
 * @param fd
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief
 * @param n
 * @param fd
 */
void	ft_putnbr_fd(int n, int fd);

#endif
