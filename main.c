#include "cub3d.h"

bool	check_argument(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nMissing argument for map file (.cub)\n", 2);
		return (false);
	}
	if (ft_strlen(argv[1]) < 5)
	{
		ft_putstr_fd("Error\nEither file has wrong extension or it has no name\n", 2);
		return (false);
	}
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0)
	{
		ft_putstr_fd("Error\nFile is not a cub file\n", 2);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	rows_count;
	t_game *g;

	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (1);
	if (!check_arument(argc, argv))
		return (free_game(g), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nError in file opening\n", 2);
		return (free_game(g), 1);
	}
	rows_count = count_rows(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nError in file opening\n", 2);
		return (free_game(g), 1);
	}
	g->file_mat = read_file(fd, rows_count);
	if (!g->file_mat)
		return (free_game(g), 1);
	g->map_mat = create_map_matrix(g->file_mat, rows_count);
	if (!g->map_mat)
		return (free_game(g), 1);
	return (free_game(g), 0);
}
