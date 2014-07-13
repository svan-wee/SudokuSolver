/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 16:41:18 by aalliot           #+#    #+#             */
/*   Updated: 2014/07/13 15:03:34 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	chk_line(char n, unsigned char y, char **tab);
char	chk_colo(char n, unsigned char x, char **tab);
char	chk_square(char n, unsigned char x, unsigned char y, char **tab);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_tab(char **tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			ft_putchar(tab[y][x]);
			if (x < 8)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

char	solve(char **tab, int p)
{
	unsigned char	y;
	unsigned char	x;
	char			n;

	y = p / 9;
	x = p % 9;
	n = 1 + '0';
	if (p == 81)
		return (1);
	if (tab[y][x] != '.')
		return (solve(tab, p + 1));
	while (n < (10 + '0'))
	{
		if (chk_line(n, y, tab) && chk_colo(n, x, tab)
				&& chk_square(n, x, y, tab))
		{
			tab[y][x] = n;
			if (solve(tab, p + 1))
				return (1);
		}
		n++;
	}
	tab[y][x] = '.';
	return (0);
}

int		check_error(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		if (ft_strlen(tab[i]) != 9)
		{
			return (0);
		}
		while (j < 9)
		{
			if ((tab[i][j] < '0' || tab[i][j] > '9') && tab[i][j] != '.')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
