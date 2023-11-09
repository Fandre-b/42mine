static int ft_get_width(char *str_flags)
{
    int len = ft_strlen(str_flags) - 1;
    int res = -1;

    while (len >= 0)
    {
        if (ft_isdigit(str_flags[len]))
        {
            int start = len;
            while (len >= 0 && ft_isdigit(str_flags[len]))
                len--;
            res = ft_atoi(&str_flags[len + 1]);
            if (len >= 0 && str_flags[len] == '.')
                len--;
            if (len >= 0 && str_flags[len] == '0' && !ft_isdigit(str_flags[len - 1]))
                res = -res;
            break;
        }
        len--;
    }
    return (res);
}