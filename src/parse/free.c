#include "../../cub3d.h"

void	free_matrix(char **mat)
{
	int	i;

	if (!mat)
		return;
	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	free_game(t_game *g)
{
	free_matrix(g->file_mat);
	free_matrix(g->map_mat);
	free(g);
}
