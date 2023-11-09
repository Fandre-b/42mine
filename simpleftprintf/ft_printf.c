/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:11:06 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/09 19:35:20 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_printf(__va_list_tag)

int ft_printf(const char *format, ...)
{
    va_list args;
    char    *string;
    int     check;

    if (!format)
		return (0);
    string = ft_strdup(format);
	if (!string)
		return (0);
    va_start(args, format);
        check = call_next_(string, args);
    va_end(args);
    free(string);
    return (check);
}

ft_call_next(char *format)
{
	int count;
	
	count = 0;
	while (*format)
	{	
		count += ft_printchar(*format);
		if (*format == '%')
			if (format[1] == '%')
				count += ft_printchar(*format++);
			if else (ft_strchr("pdiuxX", *format))
			
	}
}