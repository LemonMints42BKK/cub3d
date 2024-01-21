/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:46:33 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/21 17:32:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_y(t_ray ray, int *y1, int *y2, int index)
{
	if (index == 0)
	{
		*y1 = 0;
		*y2 = ray.wall_y_start - 1;
	}
	else if (index == 1)
	{
		*y1 = ray.wall_y_start;
		*y2 = ray.wall_y_end;
	}
	else if (index == 2)
	{
		*y1 = ray.wall_y_end + 1;
		*y2 = WINDOW_HEIGHT - 1;
	}
}

void	cub3d_render(t_main *ms, t_vp *vp)
{
	int		y[2];
	int		x[2];
	int		i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		x[0] = i;
		x[1] = i;
		get_y(ms->ray[i], &y[0], &y[1], 0);
		drawline(vp->bgimg, x, y, ms->ceiling_color);
		get_y(ms->ray[i], &y[0], &y[1], 1);
		draw_wall(ms, i, y, &ms->ray[i]);
		get_y(ms->ray[i], &y[0], &y[1], 2);
		drawline(vp->bgimg, x, y, ms->floor_color);
		i++;
	}
	mlx_put_image_to_window(vp->mlx, vp->win, vp->bgimg->img, 0, 0);
}
