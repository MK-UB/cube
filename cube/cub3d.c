/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:29 by melayoub          #+#    #+#             */
/*   Updated: 2023/10/18 18:32:54 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parser(t_cube *content)
{
	if (!foreign_material(content->lmt->map))
		ft_error("foreing material\n");
	check_top(content->lmt->map);
	check_bottom(content->lmt->map);
	check_sides(content->lmt->map);
	check_dir(content->lmt->map, content);
}

int	main(int ac, char **av)
{
	t_cube	main_game;

	if (ac == 2)
	{
		check_extension(av[1]);
		main_game.cl = ft_calloc(sizeof(t_clr), 1);
		main_game.cp = ft_calloc(sizeof(t_cmp), 1);
		main_game.lmt = ft_calloc(sizeof(t_elem), 1);
		maper(&main_game, av[1]); 
		read_components(&main_game);
		ft_parser(&main_game);
		cub(&main_game);
	}
	else
		ft_error("Missing or too many arguments!\n");
	return (0);
}
