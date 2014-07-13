/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 16:02:59 by aalliot           #+#    #+#             */
/*   Updated: 2014/07/13 15:27:00 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	chk_line(char n, unsigned char y, char **tab)
{
	unsigned char	x;

	x = 0;
	while (x < 9)
	{
		if (tab[y][x] == n)
			return (0);
		x++;
	}
	return (1);
}

char	chk_colo(char n, unsigned char x, char **tab)
{
	unsigned char		y;

	y = 0;
	while (y < 9)
	{
		if (tab[y][x] == n)
			return (0);
		y++;
	}
	return (1);
}

char	chk_square(char n, unsigned char x, unsigned char y, char **tab)
{
	unsigned char	x2;
	unsigned char	y2;

	x2 = x - (x % 3);
	y2 = y - (y % 3);
	x = x2;
	y = y2;
	while (y < y2 + 3)
	{
		while (x < x2 + 3)
		{
			if (tab[y][x] == n)
				return (0);
			x++;
		}
		x = x2;
		y++;
	}
	return (1);
}
