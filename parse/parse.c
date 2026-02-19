#include "../cub3d.h"

init_data(t_data *data)
{
	data->rgb = NULL;
}

check_zero_orizontally_after_n()
{

}

check_zero_vertically_after_n()
{

}

check_zero_orizontally_after_space()
{

}

check_zero_vertically_after_space()
{

}

check_zero_orizontally_before_n()
{

}

check_zero_vertically_before_n()
{

}

check_zero_orizontally_before_space()
{

}

check_zero_vertically_before_space()
{

}

check_zero_vertically_before_end()
{

}

int	spot_map_in_file()
{
	int		fd;
	char	*line;
	int		line_i;

	fd = open();
	line = get_next_line(fd)
	line_i = 0;
	while (line[0] != )
	{
		line = get_next_line(fd);
		line_i++;
	}
	return (line_i);
}

int	count_map_rows()
{
	int		fd;
	char	*line;
	int		line_n;
	int		i;

	fd = open();
	i = 0;
	while (i < spot_map_in_file())
		line = get_next_line(fd);
	line_n = 0;
	while (line)
	{
		line = get_next_line(fd);
		line_n++;
	}
	return (line_n);
}

create_map_matrix()
{
	int		fd;
	char	*line;
	char	**map_mat;

	map_mat[0] = line;
	while (line)
	{
		line = get_next_line(fd);
		map_mat[i] = line;
	}
	map_mat[i] = NULL;
}


// Si puo usare get_next_line given that usa una statica?