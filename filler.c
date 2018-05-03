/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:54:08 by vveselov          #+#    #+#             */
/*   Updated: 2018/03/20 00:30:20 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	xy_out(t_map *map)
{
	int		xy[2];
	char	*s;
	char	buff[255];
	int		i[2];

	xy[0] = 0;
	xy[1] = 0;
	brute_f2(*map, xy);
	map_clear(map->token, (map->ts)[0]);
	map_clear(map->map, (map->ms)[0]);
	free(map->ts);
	free(map->ms);
	i[0] = -1;
	s = ft_itoa(xy[0]);
	while (s[++i[0]])
		buff[i[0]] = s[i[0]];
	buff[i[0]++] = ' ';
	i[1] = -1;
	free(s);
	s = ft_itoa(xy[1]);
	while (s[++i[1]])
		buff[i[0]++] = s[i[1]];
	buff[i[0]] = '\0';
	free(s);
	ft_putendl(buff);
}

int		main(void)
{
	t_map	map;

	map.map = NULL;
	map.token = NULL;
	pl_check(&map);
	while (1)
	{
		map.ms = map_size(1);
		map.map = map_malloc(map.ms[0], map.ms[1]);
		map_in(map.map, map.ms, 4);
		map.ts = map_size(0);
		map.token = map_malloc(map.ts[0], map.ts[1]);
		map_in(map.token, map.ts, 0);
		xy_out(&map);
	}
	return (0);
}
