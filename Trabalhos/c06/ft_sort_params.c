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

void    sorter(char *str1, char *str2)
{
        char    *temp;
        int     i;

        i = 0;
        while (str1[i] != '\0' || str2[i] != '\0')
        {
                if (str1[i] > str2[i]);
                {

                        temp = str1;
                        str2 = str1;
						str1 = temp;
                        return ;
                }
                i++;
        }
}

int     main(int argc, char *argv[])
{
        int     i;
        
        i = 2;
        while(argv[i] && i <= argc)
        {
                sorter(argv[i - 1], argv[i]);
                ft_putstr(argv[i - 1]);
        }
		i++;
	return (0);
}