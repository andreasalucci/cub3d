#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <stdint.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define TABSIZE 8
# define MLX_ERROR 30
# define CEILING_COLOR 0x0000FF
# define FLOOR_COLOR 3110932

// parsing
typedef struct s_iso_res {
	float	x;
	float	y;
	float	z;
}		t_iso_res;

typedef struct s_color {
	float	c0;
	float	c1;
	float	step;
}		t_color;

enum e_texEnum{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_copy
{
	int		*i;
	int		*j;
	bool	r_wall;
	char	*src;
	char	*dst;
}		t_copy;

// Raycaster
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

// mlx
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	win_img;
	t_img	north_img;
	int		north_img_width;
	int		north_img_height;
	t_img	east_img;
	int		east_img_width;
	int		east_img_height;
	t_img	south_img;
	int		south_img_width;
	int		south_img_height;
	t_img	west_img;
	int		west_img_width;
	int		west_img_height;
}	t_mlx;

typedef struct s_data
{
	t_mlx			mlx;
	double			fov;
	double			half_fov;
	double			player_x;
	double			player_y;
	double			player_angle;
	double			ray_angle;
	double			ray_increment_angle;
	double			ray_x;
	double			ray_y;
	int				ray_count;
	int				wall_height;
	int				sky_direction;

	char			*no_path;
	char			*ea_path;
	char			*so_path;
	char			*we_path;
	char			dir;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	char			**rgb;
	char			**generic;
	char			**elements;
	char			**file_map;
	char			**map_cp;
	char			**map_flood;
	char			*line;
	void			*no_vptr;
	void			*so_vptr;
	void			*we_vptr;
	void			*ea_vptr;
	char			*file;
	float			pos_x;
	float			pos_y;
	int				file_size;
	int				bg_line;
	int				bg_column;
	int				p_spawn;
	int				p_posx;
	int				p_posy;
	int				map_start;
	int				magic[6];
	unsigned char	f_r;
	unsigned char	f_g;
	unsigned char	f_b;
	unsigned char	c_r;
	unsigned char	c_g;
	unsigned char	c_b;
	uint32_t		ceiling_color;
	uint32_t		floor_color;
}	t_data;

typedef struct s_game
{
	char **file_mat;
	char **map_mat;
}		t_game;

#endif