/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:56:05 by vveselov          #+#    #+#             */
/*   Updated: 2018/03/20 01:41:18 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLER_H
# define __FILLER_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# define RED_FR "\x1b[41m"
# define BLUE_FR "\x1b[44m"
# define BLACK_FR "\x1b[40m"
# define RED "\x1b[31m" BLACK_FR
# define BLUE "\x1b[34m" BLACK_FR
# define BLACK "\x1b[30m" BLACK_FR
# define NORM "\x1b[0m"

typedef struct	s_map
{
	char		pl;
	char		op;
	int			*ms;
	char		**map;
	int			*ts;
	char		**token;
}				t_map;

void			map_clear(char **map, int y);
int				*in_size(char *l, char f);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			pl_check(t_map *map);
int				*map_size(char f);
char			**map_malloc(int x, int y);
void			map_in(char **map, int *ms, int k);
void			brute_f2(t_map map, int goal[2]);
int				tok_val(t_map map, int y, int x);
void			ft_putendl(char *s);

#endif
