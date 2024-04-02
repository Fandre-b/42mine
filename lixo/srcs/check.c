/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:48:12 by mpais-go          #+#    #+#             */
/*   Updated: 2024/04/02 17:21:20 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_number(int n_play, int n_exit, int n_collect)
{
	if (n_play != 1)
	{
		ft_error_msg(ERROR_NPLAY);
		return (0);
	}
	if (n_exit != 1)
	{
		ft_error_msg(ERROR_NEXIT);
		return (0);
	}
	if (n_collect == 0)
	{
		ft_error_msg(ERROR_NCOLLECT);
		return (0);
	}
	return (n_collect);
}

int	check_tokens(char *singleline)
{
	int	i;
	int	n_play;
	int	n_exit;
	int	n_collect;

	i = -1;
	n_play = 0;
	n_exit = 0;
	n_collect = 0;
	while (singleline[++i])
	{
		if (singleline[i] == 'P')
			n_play += 1;
		else if (singleline[i] == 'E')
			n_exit += 1;
		else if (singleline[i] == 'C')
			n_collect += 1;
		else if (singleline[i] != '\n' && singleline[i] != '1' 
			&& singleline[i] != '0' && singleline[i] != 'G')
		{
			ft_error_msg(ERROR_INVCHAR);
			return (0);
		}
	}
	return (check_number(n_play, n_exit, n_collect));
}

int	check_nl_and_tokens(char *singleline)
{
	if (ft_strnstr(singleline, "\n\n", ft_strlen(singleline)))
	{
		ft_error_msg(ERROR_NEWLINE);
		return (0);
	}
	return (check_tokens(singleline));
}

int	is_rect(t_map *map)
{
	int	j;

	j = 0;
	map->width = (int)ft_strlen(map->matrix[0]);
	while (map->matrix[j])
	{
		if (map->width != (int)ft_strlen(map->matrix[j]))
		{
			ft_error_msg(ERROR_WIDTH);
			return (0);
		}
		j++;
	}
	map->height = j;
	return (1);
}

int	is_closed(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.width)
	{
		if (map.matrix[0][i] != '1' || map.matrix[map.height - 1][i] != '1')
		{
			ft_error_msg(ERROR_NCLOSED);
			return (0);
		}
		i++;
	}
	j = 1;
	while (j < map.height - 1)
	{
		if (map.matrix[j][0] != '1' || map.matrix[j][map.width - 1] != '1')
		{
			ft_error_msg(ERROR_NCLOSED);
			return (0);
		}
		j++;
	}
	return (1);
}
