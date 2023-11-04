/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addicional_toi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:58:42 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/04 20:15:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static size_t	ft_numsize(unsigned int n, unsigned int base)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static size_t	ft_numsize_adress(unsigned long int n)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	size_t	num_size;
	char	*str;

	num_size = ft_numsize(n, 10);
	str = (char *) malloc (sizeof(char) * (num_size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[num_size] = '\0';
	while (n != 0)
	{
		if (n < 0)
			str[--num_size] = (char)(-(n % 10) + '0');
		else
			str[--num_size] = (char)((n % 10) + '0');
		n /= 16;
	}
	return (str);
}

char	*ft_htoa(unsigned int n, char type)
{//can maybe remove this function
	size_t	num_size;
	char	*str;

	num_size = ft_numsize(n, 16);
	str = (char *) malloc (sizeof(char) * (num_size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[num_size] = '\0';
	while (n != 0)
	{
        if (n % 16 <= 9)
                str[--num_size] =(char)(n % 16 + '0');
        else
        {
            if (type == 'x')
                str[--num_size] = (char)(n % base - 10 + 'a');
            if (type == 'X')
                str[--num_size] = (char)(n % base - 10 + 'A');
        }
        n /= 16;
    }
	return (str);
}

char	*ft_addr(unsigned long int *num)
{//if i can get reed of unsigned int or somwthing i can maybe remove this function
	size_t	num_size;
	char	*str;

	num_size = ft_numsize_adress(num);
	str = (char *) malloc (sizeof(char) * (num_size + 1));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	str[num_size] = '\0';
	while (num != 0)
	{
        if (num % 16 <= 9)
                str[--num_size] =(char)(num % 16 + '0');
        else
                str[--num_size] = (char)(num % 16 - 10 + 'a');
        num /= 16;
    }
	return (str);
}
