/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:19:11 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 13:40:53 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	    ft_isalpha(int c);
int	    ft_isdigit(int c);
int	    ft_isascii(int c);
int	    ft_isprint(int c);
int	    ft_isblank(int c);
int	    ft_isspace(int c);
int	    ft_isalnum(int c);
int	    ft_tolower(int c);
int	    ft_toupper(int c);
size_t	ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *str, int fd);
int     ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strdup(const char *src);
int     ft_atoi(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
void    *ft_calloc(size_t nmemb, size_t size);
void    ft_bzero(void *str, size_t size);
void    *ft_memset(void *str, int c, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
void    *ft_memchr(const void *str, int c, size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	ft_putendl_fd(char *str, int fd);
char    *ft_itoa(int num);
void    ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t end);
char    **ft_split(const char *str, char c);


#endif
