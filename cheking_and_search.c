/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking_and_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:08:56 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 01:17:38 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	orderliness(t_structs *s, t_node **s1, int cnt_s1)
{
	int	cnt;

	cnt = 1;
	s->tmp1 = *s1;
	while (s->tmp1->next && cnt != cnt_s1)
	{
		if (s->tmp1->next->id - s->tmp1->id == 1)
		{
			cnt++;
			s->tmp1 = s->tmp1->next;
			if (cnt == cnt_s1)
			{
				(*s1)->f = 1;
				return (1);
			}
		}
		else
			break ;
	}
	return (0);
}

int	search_flags(t_structs *s, t_node **s1)
{
	s->tmp1 = *s1;
	while (s->tmp1->next)
	{
		if (s->tmp1->next->f == 1)
			return (1);
		s->tmp1 = s->tmp1->next;
	}
	return (0);
}

int	counter_befor_flags(t_structs *s, t_node **s1)
{
	int	i;

	i = 1;
	s->tmp1 = *s1;
	while (s->tmp1->next && !s->tmp1->next->f)
	{
		i++;
		s->tmp1 = s->tmp1->next;
		if (s->tmp1->next && s->tmp1->next->f && !s->tmp1->next->next)
			i++;
	}
	return (i);
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
