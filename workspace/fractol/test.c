/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:27:23 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/03 20:27:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

# define WIDTH 800
# define LENGTH 800

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    (void)mlx_win;
	mlx_loop(mlx);
}
