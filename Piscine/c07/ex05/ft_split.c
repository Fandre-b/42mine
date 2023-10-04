#include <stdio.h>
#include <stdlib.h>

int ft_countword(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			i++;
		if (str[i] > 32 && str[i] < 127)
		{
			count++;
			while (str[i] > 32 && str[i] < 127)
				i++;
		}
	}
	return (count);
}

int	ft_wordlen(char *str)
{
	int	i;
	int	count;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	count = 0;
	while (str[i] > 32 && str[i] < 127)
	{
		i++;
		count++;
	}
	return (count);
}

char    **str_split(char *str)
{
	int	i;
	int	j;
	int	k;
	char    **matrix = NULL;

	matrix = (char **) malloc (sizeof(char *) * (ft_countword(str) + 1));
	if(!matrix)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{    	
		while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			//na vez de espacos pode ser check
			i++;
		if(str[i] > 32 && str[i] < 127)
		{    
			j = 0;
			matrix[k] = (char *) malloc(sizeof (char) * (ft_wordlen(&str[i]) + 1));
			while (str[i] > 32 && str[i] < 127)
				matrix [k][j++] = str[i++];
			matrix [k][j] = '\0';
			k++;
		}
		else
			i++;
			//string continua se char n for nem espaco nem printable
	}
	matrix [k] = NULL;
	return (matrix);
}

int	main(void)
{
	char	*str = "    vamos la  testar    isto  ";
	char	**matrix = NULL;
	int	i;

	matrix = str_split(str);
	i = 0;
	while (i < ft_countword(str))
		printf("%s\n", matrix[i++]);
	free (matrix);
	matrix = NULL;
	return (0);
}
