/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:09:24 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 18:52:36 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_structs	s;

	ft_bzero(&s, sizeof(t_structs));
	if (argc > 1)
		pars_argv(&s, argc, argv);
	if (argc > 2)
	{
		while (argc > 1 && --argc)
			add_after_node(&s.a, s.cnt++, ft_atoi_o(*++argv), 0);
		sort_id_by_val(&s, s.a, s.cnt);
		sort_val_by_pas(&s, s.a, s.cnt);
		s.all = s.cnt;
		if (orderliness(&s, &s.a, s.all) && !s.b)
			exit (0);
		sort_basic(&s, &s.a, &s.b, s.all);
	}
	return (0);
}
