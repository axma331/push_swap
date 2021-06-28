/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:09:09 by feschall          #+#    #+#             */
/*   Updated: 2021/06/24 14:39:34 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output_error(char *s)
{
	write (2, s, ft_strlen(s));
	write (2, "\n", 1);
	exit (0);
}

void	output_result(t_structs *s)
{
	if (!s->flg_c)
	{
		if (s->o == 2)
			write (1, "sa\n", 3);
		else if (s->o == 3)
			write (1, "sb\n", 3);
		else if (s->o == 4)
			write (1, "ss\n", 3);
		else if (s->o == 5)
			write (1, "ra\n", 3);
		else if (s->o == 6)
			write (1, "rb\n", 3);
		else if (s->o == 7)
			write (1, "rr\n", 3);
		else if (s->o == 8)
			write (1, "rra\n", 4);
		else if (s->o == 9)
			write (1, "rrb\n", 4);
		else if (s->o == 10)
			write (1, "rrr\n", 4);
		else if (s->o == 11)
			write (1, "pa\n", 3);
		else if (s->o == 12)
			write (1, "pb\n", 3);
	}
}
