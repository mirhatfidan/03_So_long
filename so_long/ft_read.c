/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mfidan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:29:31 by mfidan            #+#    #+#             */
/*   Updated: 2022/04/25 17:29:36 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map_y(struct s_elements *g, int fd)
{
	char	*buff;
	int		y;
	int		a;

	a = 1;
	y = -1;
	while (a != 0)
	{
		buff = malloc(sizeof(char) + 1);
		a = read(fd, buff, 1);
		buff[1] = '\0';
		if (buff[0] == '\n')
			y++;
		free(buff);
	}
	g->y_m = y;
}

void	ft_read_map_x(struct s_elements *g, int fd)
{
	char	*buff;
	int		x;
	int		a;

	a = 1;
	x = 0;
	while (a != 0)
	{
		buff = malloc(sizeof(char) + 1);
		a = read(fd, buff, 1);
		buff[1] = '\0';
		if (buff[0] == '\n')
		{
			free(buff);
			break ;
		}
		x++;
		free(buff);
	}
	g->x_m = x;
}

void	ft_write_map(struct s_elements *g, int fd)
{
	int	a;
	int	b;

	a = 0;
	b = g->y_m;
	g->map = malloc(sizeof(char) * (g->y_m * g->x_m));
	while (b > 0)
	{
		g->map[a] = get_next_line(fd);
		b--;
		a++;
	}
}
