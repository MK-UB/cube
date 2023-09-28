/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:40:21 by melayoub          #+#    #+#             */
/*   Updated: 2023/09/28 01:47:16 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char *alloc_n_trim(char *line)
{
	int		start;
	int		end;
	int		i;

	i = 0;
	while (is_white_space(line[i]))
		i++;
	if (!line[i])
		return (line);
	start = i;
	end = ft_strlen(line) - 1;
	while (is_white_space(line[end]))
		end--;
	return (ft_strjoin(ft_substr(line, start, (end + 1) - start), "\n"));
	// if(!is_white_space(line[i]))
	// 	ft_error("ERROR: incorrect dir syntax!");
}


void	maper(t_cube	*content, char	*av)
{
	char	*line;
	char	*all_lines = 0;
	int		fd;
	char	*res = 0;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR: Map not found!");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = alloc_n_trim(line);
		if (!line)
			continue ;
		all_lines = ft_strjoin(res, line);
		free(line);
		// if (res)
		// 	free(res);
		res = all_lines;
	}
	content->lmt->file = ft_split(res, '\n');
	free(all_lines);
}