/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:05:43 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 12:36:42 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/Libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line_bonus.h"

# define ERROR_OPEN "Error opening file.\n"
# define ERROR_READ "Error reading file.\n"
# define ERROR_WIDTH "Error, lines with different width file.\n"
# define ERROR_NEWLINE "Error, extra new lines.\n"
# define ERROR_INVCHAR "Error, invalid character.\n"
# define ERROR_NPLAY "Error, invalid number of players.\n"
# define ERROR_NEXIT "Error, invalid number of exits.\n"
# define ERROR_NCOLLECT "Error, invalid number of collectables.\n"
# define ERROR_NCLOSED "Error, the map is not limited by walls.\n"
# define ERROR_FF "Error, impossible map.\n"

# define COLLECTIBLE "./images/collectible.xpm"
# define EXIT "./images/exit.xpm"
# define FLOOR "./images/floor.xpm"
# define UPAC_O "./images/upac_o.xpm"
# define UPAC_C "./images/upac_c.xpm"
# define RPAC_O "./images/rpac_o.xpm"
# define RPAC_C "./images/rpac_c.xpm"
# define DPAC_O "./images/dpac_o.xpm"
# define DPAC_C "./images/dpac_c.xpm"
# define LPAC_O "./images/lpac_o.xpm"
# define LPAC_C "./images/lpac_c.xpm"
# define ENEMY_U "./images/enemy_u.xpm"
# define ENEMY_D "./images/enemy_d.xpm"

# define BRDSGLWALL "./images/brdsglwall.xpm"
# define NOBRDWALL "./images/nobrdwall.xpm"
# define UVERT "./images/uvert.xpm"
# define RVERT "./images/rvert.xpm"
# define DVERT "./images/dvert.xpm"
# define LVERT "./images/lvert.xpm"
# define NECORNER "./images/necorner.xpm"
# define SECORNER "./images/secorner.xpm"
# define SOCORNER "./images/socorner.xpm"
# define NOCORNER "./images/nocorner.xpm"
# define DBLVRTWALL "./images/dblvrtwall.xpm"
# define DBLHRZWALL "./images/dblhrzwall.xpm"
# define UWALL "./images/uwall.xpm"
# define RWALL "./images/rwall.xpm"
# define DWALL "./images/dwall.xpm"
# define LWALL "./images/lwall.xpm"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_image {
	void	*upac[2];
	void	*rpac[2];
	void	*dpac[2];
	void	*lpac[2];
	void	*enemy[2];
	void	*collect;
	void	*exit;
	void	*floor;
	void	*brdsglwall;
	void	*nobrdwall;
	void	*uvert;
	void	*rvert;
	void	*dvert;
	void	*lvert;
	void	*necorner;
	void	*secorner;
	void	*socorner;
	void	*nocorner;	
	void	*dblvrtwall;
	void	*dblhrzwall;
	void	*uwall;
	void	*rwall;
	void	*dwall;
	void	*lwall;
}				t_image;

typedef struct s_player {
	int		pos_ply[2];
	int		colected;
	int		moves;
	void	*last_img;
}				t_player;

typedef struct s_map {
	char		**matrix;
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	int			nbr_c;
	int			flag_exit;
	int			og_exit[2];
	t_player	player;
	t_image		images;
}				t_map;

//units
void	*ft_error_msg(char *msg);
void	init_player(t_map *map);
void	flood_fill(int x, int y, char **mapa);
void	free_matrix(char **map);
void	print_n_moves(t_map *map);
//moves
void	move_up(t_map *map, int *i);
void	move_left(t_map *map, int *i);
void	move_down(t_map *map, int *i);
void	move_right(t_map *map, int *i);
int		enemy_jumps(t_map *map);
//aux_walls
void	auxfinalwall_img_to_window(t_map map, int x, int y);
//check
int		check_nl_and_tokens(char *singleline);
int		is_rect(t_map *map);
int		is_closed(t_map map);
//images
void	window_xpm_to_img(t_map *map);
int		put_image_to_window(t_map map, void *image, int x, int y);
void	img_to_window(t_map *map, int x, int y);
//end_game
void	end_game(t_map *map);
int		exit_button(t_map *map);
void	*end_game_msg(t_map map, char *msg);
//parser
void	get_map(char *path, t_map *map);
int		validate_map(t_map *map);
#endif