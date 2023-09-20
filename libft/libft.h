/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:19:11 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/18 14:42:04 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_isblank(int c);
int	ft_isspace(int c);
int	ft_isalnum(int c);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(char *str, int c);
char	*ft_strcpy(char *dst, const char *src);
//size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strncat(char *dst, const char *src, size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
char	*ft_strrchr(const char *str, int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif
