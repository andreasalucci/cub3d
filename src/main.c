#include "../cub3d.h"

bool	check_argument(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error\nMissing argument for map file (.cub)\n", 2);
		return (false);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments\n", 2);
		return (false);
	}
	if (ft_strlen(argv[1]) < 5)
	{
		ft_putstr_fd("Error\nEither file has wrong extension or has no name\n", 2);
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
	if (!check_argument(argc, argv))
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
	// if (!check_map(g->map_mat))
	// 	return (free_game(g), 1);
	int i = 0;
	while (g->map_mat[i])
	{
		int j = 0;
		while (g->map_mat[i][j] != '\n' && g->map_mat[i][j] != '\0')
		{
			write(1, &g->map_mat[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (free_game(g), 0);
}
