/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:42:38 by vveselov          #+#    #+#             */
/*   Updated: 2018/03/20 00:30:16 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_itoa(int n)
{
	int		ct;
	int		l;
	char	*ret;
	int		min;

	ct = 0;
	l = n;
	min = 1;
	while (++ct && l / 10 != 0)
		l /= 10;
	if (n < 0 && ++ct)
		min = -1;
	ret = (char *)malloc(sizeof(char) * (ct + 1));
	if (!ret)
		return (NULL);
	ret[ct--] = '\0';
	while (ct != -1)
	{
		ret[ct] = '0' + min * (n % 10);
		n /= 10;
		ct--;
	}
	if (min == -1)
		ret[0] = '-';
	return (ret);
}

int		ft_atoi(const char *str)
{
	int	min;
	int	ret;

	min = 1;
	ret = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (--str && (*(str + 1) == '-' || (*(str + 1) == '+')) && ++str)
		(*str == '-') ? (min = -1) : 0;
	while (*(++str) >= '0' && *str <= '9' && *str)
		ret = ret * 10 + (*str - 48) * (long long)min;
	return ((int)ret);
}

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!n)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (--n && *s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putendl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

int		*in_size(char *l, char f)
{
	int		*m;
	int		i;

	i = 0;
	m = (int *)malloc(sizeof(int) * 2);
	while (l[i] != ' ')
		i++;
	m[0] = ft_atoi(&l[i++]);
	while (l[i] != ' ')
		i++;
	m[1] = ft_atoi(&l[i]);
	if (f)
		m[1] += 4;
	return (m);
}
