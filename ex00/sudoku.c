/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 13:47:19 by aalliot           #+#    #+#             */
/*   Updated: 2014/07/13 14:07:02 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_tab(char **tab);
void	ft_putstr(char *str);
char	solve(char **tab, int p);
int		check_error(char **tab);

int		main(int argc, char **argv)
{
	if (argc == 10)
	{
		if (check_error(&argv[1]))
		{
			solve(&argv[1], 0);
			ft_print_tab(&argv[1]);
		}
		else
			ft_putstr("Erreur\n");
	}
	else
		ft_putstr("Erreur\n");
	return (0);
}
