#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != 0)
	{
		write(1, &str[i++], 1);
	}
	write (1, "\n", 1);
}

char    **ft_strbublesorter(char *argv[])
{
	char    *temp;
	int     i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 1;
	while(argv[++k])
		i = 1;
		while(argv[++i])
		{
			j = 0;
			while (argv[i][j] != '\0' || argv[i][j] != '\0')
			{
				if (argv[i][j] > argv[i - 1][j])
				{
					temp = argv[i - 1];
					argv[i - 1] = argv[i];
					argv[i] = temp;
					break ;
				}
				j++;
			}
		}
	return (argv);
}

int     main(int argc, char *argv[])
{
	ft_strbublesorter(argv);
	while (argc > 1)
	{
		ft_putstr(argv[argc-1]);
		argc--;
	}
	return (0);
}