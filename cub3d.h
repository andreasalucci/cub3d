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
