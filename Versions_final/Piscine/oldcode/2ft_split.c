/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:52:40 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/15 17:17:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cmpstr(char *str, char *charset)
{
	int	n;
	
	n = 0
	while (*charset != '\0')
	{
		while (str[n] != '\0')
		{
			if (str[n] == *charset)
				return n;
		}
	}
	return (-1)
}
	
int	ft_lenstr()
{
}

char	**ft_split(char *str, char *charset)
{
	
	if (ft_cmpstr = 
}


