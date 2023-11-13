/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:12:49 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/12 18:45:30 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// -0.#12345678
int main(void)
{
    int count = 0;

    printf("minha:\n");
	count = ft_printf("|.%c.%c.%c.|\n", '0', 1, '1');
        printf("count = %d\n", count);
    count = ft_printf("|.%c.%c.%c.|\n", '2', '1', 0);
        printf("count = %d\n", count);
    count = ft_printf("|.%c.%c.%c.|\n", 0, '1', '2');
        printf("count = %d\n\n", count);
    printf("original:\n");
	count = printf("|.%c.%c.%c.|\n", '0', 1, '1');
        printf("count = %d\n", count);
    count = printf("|.%c.%c.%c.|\n", '2', '1', 0);
        printf("count = %d\n", count);
    count = printf("|.%c.%c.%c.|\n", 0, '1', '2');
        printf("count = %d\n", count);
    return (0);

}
