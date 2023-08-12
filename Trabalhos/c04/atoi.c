
int     ft_atoi(char *str)
{
        int     res;
        int     sig;
        int     i;

        sig = -1;
        res = 0;
        i = 0;
        while (*str == 32 || (*str > 8 && *str < 14))
                str++;
        while (str[i] == 45 || str[i] == 43)
        {
                if (str[i++] == 45)
                        sig *= -1;
        }
        while (str[i] >= '0' && str[i] <= '9')
                res = res * 10 - (str[i++] - 48);
        return (sig * res)
}

