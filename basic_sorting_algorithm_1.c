/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting_algorithm_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:07:58 by feschall          #+#    #+#             */
/*   Updated: 2021/06/24 23:55:13 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_basic(t_structs *s, t_node **s1, t_node **s2, int e_id)
{
	s->x.diff = counter_befor_flags(s, s1);
	defining_border_1(s, e_id);
	if (s->x.diff > 5)
	{
		while (*s1 && s->t.t1)
			sort_basic_1(s, s1, s2);
		sort_basic_2(s, s1, s2);
	}
	else
		sort_up_to_five (s, s1, s2);
	s->x.diff = counter_befor_flags(s, s2);
	if (s->x.diff)
		sort_basic_rev(s, s1, s2, s->all);
}

void	sort_basic_rev(t_structs *s, t_node **s1, t_node **s2, int e_id)
{
	defining_border_2(s, e_id);
	if (s->x.diff < 6)
		sort_five_out_s2 (s, s1, s2, s->x.diff);
	else if (*s2 && s->t.t1)
	{
		while (s->t.t1)
			sort_basic_rev_1(s, s1, s2);
		if (counter_befor_flags(s, s1) < 6)
			sort_up_to_five (s, s1, s2);
		sort_basic_rev_2(s, s1, s2);
		if (s->t.t3)
		{
			(*s2)->f = 1;
			while (s->t.t3 && s->t.t3--)
			{
				rev_rotate(s, s1);
				push(s, s1, s2);
			}
			(*s2)->f = 1;
		}
	}
	sort_basic(s, s1, s2, s->all);
}

void	defining_border_1(t_structs *s, int e_id)
{
	ft_bzero(&s->t, sizeof(t_temp));
	s->x.r_b = e_id;
	s->x.l_b = e_id - s->x.diff;
	s->x.m_b = s->x.r_b - s->x.diff / 2;
	s->x.lm_b = (s->x.m_b - s->x.l_b) / 2 + s->x.l_b;
	s->t.t1 = s->x.m_b - s->x.l_b;
	s->t.t4 = s->t.t1;
}

void	defining_border_2(t_structs *s, int e_id)
{
	ft_bzero(&s->t, sizeof(t_temp));
	s->x.l_b = e_id - s->x.diff;
	s->x.r_b = e_id;
	s->x.m_b = s->x.r_b - (s->x.diff - s->x.diff / 2);
	s->x.lm_b = (s->x.m_b - s->x.l_b) / 2 + s->x.l_b;
	s->x.mr_b = (s->x.r_b - s->x.m_b) / 2 + s->x.m_b;
	s->t.t1 = s->x.r_b - s->x.m_b;
	s->t.t4 = s->t.t1;
}
