/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mfidan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:29:19 by mfidan            #+#    #+#             */
/*   Updated: 2022/05/30 14:00:44 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(struct s_elements *g, int y, int x)
{
	mlx_put_image_to_window
	(g->m_p, g->w_p, g->b_i, (g->p_x * 50), g->p_y * 50);
	mlx_put_image_to_window
	(g->m_p, g->w_p, g->p_i, ((g->p_x + x) * 50), ((g->p_y + y) * 50));
	g->map[g->p_y][g->p_x] = '0';
	g->p_y += y;
	g->p_x += x;
	g->h_s++;
	ft_printf("\033[2K\r\033[0;34mHamle Sayısı : %d\n", g->h_s);
}

void	ft_check_move(struct s_elements *g, int y, int x)
{
	if (g->map[g->p_y + y][g->p_x + x] == '0')
		ft_move(g, y, x);
	else if (g->map[g->p_y + y][g->p_x + x] == 'C')
	{
		ft_move(g, y, x);
		g->c_c--;
	}
	else if (g->map[g->p_y + y][g->p_x + x] == 'E' && g->c_c != 0)
		ft_printf("\033[2K\r\033[0;33mUse your brain!\n");
	else if (g->map[g->p_y + y][g->p_x + x] == 'E' && g->c_c == 0)
	{
		ft_move(g, y, x);
		ft_printf("\033[2K\r\033[0;32mYOU WON BTCH!\n");
		mlx_destroy_window(g->m_p, g->w_p);
		exit (0);
	}
	else if (g->map[g->p_y + y][g->p_x + x] == 'N')
	{
		ft_printf("\033[2K\r\033[0;31mLOSER!!\n");
		mlx_destroy_window(g->m_p, g->w_p);
		exit (0);
	}
	else if (g->map[g->p_y + y][g->p_x + x] == '1')
		ft_printf("\033[2K\r\033[0;33mARE YOU BLIND?\n");
}

int	ft_key_check(int keycode, struct s_elements *g)
{
	if (keycode == EVENT_W)
		ft_check_move(g, -1, 0);
	else if (keycode == EVENT_A)
		ft_check_move(g, 0, -1);
	else if (keycode == EVENT_S)
		ft_check_move(g, 1, 0);
	else if (keycode == EVENT_D)
		ft_check_move(g, 0, 1);
	else if (keycode == 53)
	{
		mlx_destroy_window(g->m_p, g->w_p);
		exit (0);
	}
	return (0);
}
