#include "../../cub3d.h"

// init_data(t_data *data)
// {
// 	data->rgb = NULL;
// }

// check_zero_orizontally_after_n()
// {

// }

// check_zero_vertically_after_n()
// {

// }

// check_zero_orizontally_after_space()
// {

// }

// check_zero_vertically_after_space()
// {

// }

// check_zero_orizontally_before_n()
// {

// }

// check_zero_vertically_before_n()
// {

// }

// check_zero_orizontally_before_space()
// {

// }

// check_zero_vertically_before_space()
// {

// }

// check_zero_vertically_before_end()
// {

// }

bool	wall_after_only_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] && str[i] == '1')
		return (true);
	else
		return (false);
}

int	spot_map_in_file(char **file, int rows_count)
{
	int		line_i;

	line_i = 0;
	while (line_i < rows_count && file[line_i] && !wall_after_only_spaces(file[line_i]))
		line_i++;
	if (line_i == rows_count)
	{
		ft_putstr_fd("Error\nImpossible to find a map in the file\n", 2);
		return (-1);
	}
	return (line_i);
}

int	count_map_rows(char **file, int rows_count)
{
	int	i;
	int	count;

	i = spot_map_in_file(file, rows_count);
	if (i == -1)
		return (-1);
	count = 0;
	while (file[i])
	{
		if (file[i][0] != '\0' && file[i][0] != '\n')
			count++;
		i++;
	}
	return (count);
}

char	**create_map_matrix(char **file, int rows_count)
{
	char	**map_mat;
	int		i;
	int		map_i;
	int		map_rows;

	map_rows = count_map_rows(file, rows_count);
	if (map_rows == -1)
		return (NULL);
	map_mat = malloc((sizeof(char *)) * (map_rows + 1));
	if (!map_mat)
		return (NULL);
	i = spot_map_in_file(file, rows_count);
	map_i = 0;
	while (i < rows_count && file[i])
	{
		if (file[i][0] != '\0' && file[i][0] != '\n')
		{
			map_mat[map_i] = ft_strdup(file[i]);
			map_i++;
		}
		i++;
	}
	map_mat[map_i] = NULL;
	return (map_mat);
}

// check_map()
// {

// }

char	**read_file(int fd, int rows_count)
{
	char	*line;
	char	**file;
	int		i;

	file = malloc(sizeof(char *) * (rows_count + 1));
	if (!file)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)// && i < rows_count)
	{
		file[i] = line;
		i++;
		line = get_next_line(fd);
	}
	file[i] = NULL;
	close(fd);
	return (file);
}

int	count_rows(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		//free(line);
		line = get_next_line(fd);
	}
	//close(fd);
	return (count);
}
