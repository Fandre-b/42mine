#include "pipex.h"

void	**ft_ptrshift(void **ptr, int n_shift)
{//ft_ptrshift
	int		i;
	void	**shifted_str;

	if (!ptr)
		return (ptr);
	shifted_str = ptr;
	i = -1;
	while (shifted_str[++i + n_shift])
		shifted_str[i] = shifted_str[n_shift + i];
	while (n_shift-- >= 0)
		shifted_str[i++] = NULL;
	return (shifted_str);
}

void	*ft_strshift(void *ptr, int n_shift)
{
	int		i;
	char	*shifted_str;

	if (!ptr)
		return (ptr);
	shifted_str = (char *) ptr;
	i = -1;
	while (shifted_str[++i + n_shift])
		shifted_str[i] = shifted_str[n_shift + i];
	while (n_shift-- >= 0)
		shifted_str[i++] = 0;
	return (shifted_str);
}

void	*ft_memshift(void *ptr, int n_shift, int size, int ele_size)
{
	int		i;
	char	*shifted_str;
	int		shift_size;

	if (!ptr)
		return (ptr);
	shifted_str = (char *) ptr;
	if (n_shift > size)
		n_shift = size;
	shift_size = n_shift * ele_size;
	i = -1;
	while (++i < n_shift * ele_size)
		shifted_str[i] = shifted_str[i + n_shift * ele_size];
	while (i < size * ele_size)
		shifted_str[i++] = 0;
	return ((void *) shifted_str);
}


char *ft_strpbrk(char *str, char *chrs)
{
	int i;
	
	i = 0;
	if (!chrs || !str)
		return (NULL);
	while(*str)
	{
		i = -1;
		while (chrs[++i])
		{
			if (*str == chrs[i])
				return (str);
		}
		str++;
	}
	return (NULL);
}

char *ft_strchr(char *str, char ch)
{
	if (!str)
		return (NULL);
	while(*str && *str != ch)
		str++;
	if (!*str)
		return (NULL);
	return (str);
}

int	ft_strchr_idx(char *str, char ch)
{
	char *first_occur;

	first_occur = ft_strchr(str, ch);
	if (!first_occur)
		return (-1);
	else
		return(first_occur - str);
}

int	ft_strpbrk_idx(char *str, char *chrs)
{
	char *first_occur;

	first_occur = ft_strpbrk(str, chrs);
	if (!first_occur)
		return (-1);
	else
		return(first_occur - str);
}
