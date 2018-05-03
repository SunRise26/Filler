/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:46:35 by vveselov          #+#    #+#             */
/*   Updated: 2018/03/20 00:30:17 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	pl_check(t_map *map)
{
	char	*l;

	get_next_line(0, &l);
	if (!ft_strncmp("$$$ exec p1", l, 11))
	{
		map->pl = 'O';
		map->op = 'X';
	}
	else if (!ft_strncmp("$$$ exec p2", l, 11))
	{
		map->pl = 'X';
		map->op = 'O';
	}
	else
		exit(0);
	free(l);
}

int		*map_size(char f)
{
	int		*m;
	char	*l;
	int		i;

	i = 0;
	if (get_next_line(0, &l) <= 0)
		exit(0);
	m = (int *)malloc(sizeof(int) * 2);
	while (l[i] != ' ')
		i++;
	m[0] = ft_atoi(&l[i++]);
	while (l[i] != ' ')
		i++;
	m[1] = ft_atoi(&l[i]);
	free(l);
	if (f == 1)
	{
		get_next_line(0, &l);
		free(l);
	}
	return (m);
}

char	**map_malloc(int x, int y)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * x);
	while (x--)
		map[x] = (char *)malloc(sizeof(char) * (y + 1));
	return (map);
}

void	map_in(char **map, int *ms, int k)
{
	int		j;
	int		i;
	char	*l;

	j = -1;
	while (++j < ms[0])
	{
		get_next_line(0, &l);
		i = -1;
		while (++i < ms[1])
			map[j][i] = l[i + k];
		map[j][i] = '\0';
		free(l);
	}
}

void	map_clear(char **map, int y)
{
	int		i;

	i = -1;
	while (++i < y)
		free(map[i]);
	free(map);
}
