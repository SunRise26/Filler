/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_bon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:26:24 by vveselov          #+#    #+#             */
/*   Updated: 2018/03/20 01:55:47 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	head_out(void)
{
	int		i;
	char	*l;

	i = 0;
	while (i++ < 9)
	{
		get_next_line(0, &l);
		ft_putendl(l);
		free(l);
	}
}

void	in_out(char **in, int *sz, int fd)
{
	int		i;
	int		j;

	i = -1;
	while (++i < sz[0])
	{
		j = -1;
		while (++j < sz[1])
		{
			if (in[i][j] == 'X')
				write(fd, RED_FR "X" NORM, 10);
			else if (in[i][j] == 'O')
				write(fd, BLUE_FR "O" NORM, 10);
			else if (in[i][j] == 'x')
				write(fd, RED "x" NORM, 15);
			else if (in[i][j] == 'o')
				write(fd, BLUE "o" NORM, 15);
			else if (in[i][j] == '.')
				write(fd, BLACK "." NORM, 15);
			else
				write(fd, &in[i][j], 1);
		}
		write(fd, "\n", 1);
	}
}

void	get_pr_free(char **l, char f)
{
	if (f == 0 && get_next_line(0, l) > 0)
	{
		ft_putendl(*l);
		free(*l);
	}
	else if (f == 1)
	{
		ft_putendl(*l);
		free(*l);
	}
}

void	main_o(char **l)
{
	char	**map;
	int		*ms;

	map = NULL;
	ms = in_size(*l, 1);
	get_pr_free(l, 1);
	get_pr_free(l, 0);
	map = map_malloc(ms[0], ms[1]);
	map_in(map, ms, 0);
	in_out(map, ms, 1);
	map_clear(map, ms[0]);
	free(ms);
	get_pr_free(l, 0);
	while (**l != '<')
		get_pr_free(l, 0);
}

int		main(int argc, char **argv)
{
	char	*l;
	int		t;

	write(1, "\x1b[8;200;110t\x1b[3;0;0t", 20);
	head_out();
	if (argc > 1)
		t = ft_atoi(argv[1]);
	else
		t = 30000;
	if (t < 0)
		t = 0;
	while (get_next_line(0, &l) > 0)
	{
		if (!ft_strncmp(l, "==", 2))
		{
			get_pr_free(&l, 1);
			get_pr_free(&l, 0);
			return (0);
		}
		usleep(t);
		system("clear");
		main_o(&l);
	}
	return (0);
}
