/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:53:16 by vveselov          #+#    #+#             */
/*   Updated: 2018/03/20 00:30:18 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		dist_ch(int xy[2], int xy1[2])
{
	int		i[2];

	i[0] = xy[0] - xy1[0];
	if (i[0] < 0)
		i[0] *= -1;
	i[1] = xy[1] - xy1[1];
	if (i[1] < 1)
		i[1] *= -1;
	return (i[0] + i[1]);
}

int		tok_val(t_map map, int y, int x)
{
	int		col;
	int		i;
	int		j;

	col = 0;
	i = -1;
	while (++i < map.ts[0] && col < 2)
	{
		j = -1;
		while (++j < map.ts[1] && col < 2)
			if (map.token[i][j] == '*' && map.pl == map.map[i + y][j + x])
				col++;
			else if (map.token[i][j] == '*' && map.map[i + y][j + x] != '.')
				return (0);
	}
	if (col == 1)
		return (1);
	return (0);
}

int		tm_dist_ch(t_map map, int goal[2])
{
	int	i[2];
	int	tmp;
	int	res;

	i[0] = -1;
	res = -1;
	while (++i[0] < map.ms[0] && (i[1] = -1))
		while (++i[1] < map.ms[1])
			if (map.map[i[0]][i[1]] == map.op)
			{
				tmp = dist_ch(i, goal);
				if (res < 0 || res > tmp)
					res = tmp;
			}
	return (res);
}

int		tok_dist_ch(t_map map, int xy[2])
{
	int	i[2];
	int goal[2];
	int	tmp;
	int	res;

	i[0] = -1;
	res = -1;
	while (++i[0] < map.ts[0] && (i[1] = -1))
		while (++i[1] < map.ts[1])
			if (map.token[i[0]][i[1]] == '*')
			{
				goal[0] = i[0] + xy[0];
				goal[1] = i[1] + xy[1];
				tmp = tm_dist_ch(map, goal);
				if (res < 0 || res > tmp)
					res = tmp;
			}
	return (res);
}

void	brute_f2(t_map map, int goal[2])
{
	int		xy[2];
	int		best_dist;
	int		tmp;

	xy[0] = -1;
	best_dist = -1;
	while (map.ts[0] + ++xy[0] <= map.ms[0])
	{
		xy[1] = -1;
		while (map.ts[1] + ++xy[1] <= map.ms[1])
			if (tok_val(map, xy[0], xy[1]) > 0)
			{
				tmp = tok_dist_ch(map, xy);
				if (best_dist < 0 || tmp < best_dist)
				{
					best_dist = tmp;
					goal[0] = xy[0];
					goal[1] = xy[1];
				}
			}
	}
}
