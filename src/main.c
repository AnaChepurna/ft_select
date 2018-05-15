/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:58:00 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/15 14:58:02 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void	clear(void)
{
	manage_term(RE_SET);
	manage_interface(FREE, NULL);
}

void	process(char **argv)
{
	t_interface *in;

	in = manage_interface(42, NULL);
	manage_interface(INIT, argv);
	manage_interface(FRESH, NULL);
	start_signal_handling();
	parse_controls(in);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" source ... source\n", 2);
	}
	manage_term(INIT);
	manage_term(SET);
	process(++argv);
	return (0);
}
