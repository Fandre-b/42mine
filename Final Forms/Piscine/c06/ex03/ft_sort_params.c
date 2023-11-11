/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:06:11 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/13 15:21:17 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write (1, &str[i++], 1);
	}
	write (1, "\n", 1);
}

void	ft_str_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

char	**ft_strbublesorter(char *argv[])
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (argv[++k])
	{
		i = 1;
		while (argv[++i])
		{
			j = 0;
			while (argv[i][j] != '\0' || argv[i][j] != '\0')
			{
				if (argv[i][j] > argv[i - 1][j])
				{
					ft_str_swap(&argv[i - 1], &argv[i]);
					break ;
				}
				j++;
			}
		}
	}
	return (argv);
}

int	main(int argc, char *argv[])
{
	ft_strbublesorter(argv);
	while (argc > 1)
	{
		ft_putstr(argv[argc - 1]);
		argc--;
	}
	return (0);
}
