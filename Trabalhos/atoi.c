int     *ft_strncmp(char *dest, char *str, int n)
{       
        if (str[0] == '\0'
        while
}       
u

int     ft_atoi(char *str)
{
        int res;
        int sig;

        sig = 1;
        res = 0;
        while (*str = 32 || str[i] >= 9 && str[i] <= 13)
                str++;
        while (str[i] == 45 || str[i] == 43)
        {
                if (str[i] == 45)
                        sig *= -1;
                i++;
        }
       while (str[i] >= '0' && str[i] <= '9')
        {
                if (sig == 1)
                       res = res * 10 + (str[i] - 48)
        else
                res = res * 10 - (str[i] - 48)
        i++
        }
        return (res)
}

