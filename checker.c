/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:09:24 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 19:05:32 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_structs	s;
	char		*line;

	ft_bzero(&s, sizeof(t_structs));
	pars_argv(&s, argc, argv);
	if (argc > 2)
	{
		while (argc > 1 && --argc)
			add_after_node(&s.a, s.cnt++, ft_atoi_o(*++argv), 0);
		sort_id_by_val(&s, s.a, s.cnt);
		sort_val_by_pas(&s, s.a, s.cnt);
		s.all = s.cnt;
	}
	s.flg_c = 1;
	while (get_next_line(0, &line))
	{
		parsing_input(&s, &s.a, &s.b, line);
		free(line);
	}
	if ((orderliness(&s, &s.a, s.all)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
