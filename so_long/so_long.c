/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mfidan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:29:50 by mfidan            #+#    #+#             */
/*   Updated: 2022/04/26 17:19:09 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(void)
{
	exit (0);
}

int	draw_main(char *argv, struct s_elements *g)
{
	int	fd;

	ft_draw_item(g);
	fd = open(argv, O_RDONLY);
	g->w_p = mlx_new_window(g->m_p, (g->x_m * 50), (g->y_m * 50), "wizard");
	mlx_hook(g->w_p, 17, 0, key, g);
	ft_draw_map(g);
	mlx_key_hook(g->w_p, ft_key_check, g);
	mlx_loop(g->m_p);
	close(fd);
	return (0);
}

int	map_arg_main(char *argv, struct s_elements *g)
{
	int	fd;

	g->h_s = 0;
	fd = open(argv, O_RDONLY);
	ft_read_map_y(g, fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	ft_read_map_x(g, fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	ft_write_map(g, fd);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_elements	g;

	if (argc == 2)
	{
		if (ft_check_arg(argv[1]))
		{
			map_arg_main(argv[1], &g);
			if (ft_check_map(g.map, g.x_m, g.y_m))
			{
				if (ft_check_item(&g))
					draw_main(argv[1], &g);
			}
		}
	}
}
