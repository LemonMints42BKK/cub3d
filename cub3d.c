/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/21 19:12:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/game_setup.h"

int	check_invalid_filedata(char *maps_path, t_map *map, t_player *p)
{
	if (invalid_filepath(maps_path, "maps/", ".cub"))
		return (ft_putstr_fd(GREEN"Used: maps/<filename>.cub\n"RESET, 2), \
		EXIT_FAILURE);
	if (explicit_error(rd_mapdata(maps_path, map, p)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	raycaster_loop(t_main *main)
{
	t_vp	*vars;

	vars = (*main).viewport;
	init_ray(main);
	cub3d_render(main, main->viewport);
	mlx_hook(vars->win, 17, 0, cub3d_exit, main);
	mlx_hook(vars->win, 2, 0, bottons, main);
	mlx_loop(vars->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main_struc;

	(void)argv;
	init_main_struct(&main_struc);
	if (argc != 2)
		return (perror(GREEN"USED: ./cud3d maps/<filename>.cub"RESET), \
		EXIT_FAILURE);
	if (is_invalid_input(argv[1], &main_struc))
		return (cub3d_exit(&main_struc), EXIT_FAILURE);
	if (set_main_struct(&main_struc))
		return (cub3d_exit(&main_struc), EXIT_FAILURE);
	raycaster_loop(&main_struc);
	return (cub3d_exit(&main_struc), EXIT_SUCCESS);
}
