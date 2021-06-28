/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting_algorithm_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:08:31 by feschall          #+#    #+#             */
/*   Updated: 2021/06/23 11:49:29 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_basic_1(t_structs *s, t_node **s1, t_node **s2)
{
	if ((s->x.l_b <= (*s1)->id && (*s1)->id < s->x.m_b) && s->t.t1--)
	{
		push(s, s1, s2);
		if (!s->flg_b && (s->x.l_b <= (*s2)->id && (*s2)->id < s->x.lm_b) \
												&& (*s2)->next && ++s->t.t3)
		{
			if ((*s2)->next->next && !(s->x.l_b <= (*s2)->next->id \
									&& (*s2)->next->id < s->x.lm_b))
				rotate(s, s2);
			else if (!(*s2)->next->next && !(s->x.l_b <= (*s2)->next->id \
										&& (*s2)->next->id < s->x.lm_b))
				swap(s, s2);
		}
		else if (!s->flg_b && (*s2)->next && !(s->x.lm_b <= (*s2)->next->id \
											&& (*s2)->next->id < s->x.m_b))
			(*s2)->next->f = 1;
		else if (s->flg_b && s->t.t4 > 5 && (s->x.lm_b <= (*s2)->id \
				&& (*s2)->id < s->x.m_b) && (*s2)->next && ++s->t.t3)
			rotate(s, s2);
	}
	if (s->t.t1 && !(s->x.l_b <= (*s1)->id && (*s1)->id < s->x.m_b) \
														&& ++s->t.t2)
		rotate(s, s1);
}

void	sort_basic_2(t_structs *s, t_node **s1, t_node **s2)
{
	(*s2)->f = 1;
	while (s->flg_b && s->t.t3--)
		rev_rotate(s, s2);
	(*s2)->f = 1;
	s->flg_b = 1;
	while (search_flags(s, s1) && s->t.t2--)
		rev_rotate(s, s1);
	sort_basic(s, s1, s2, s->x.r_b);
}

void	sort_basic_rev_1(t_structs *s, t_node **s1, t_node **s2)
{
	if ((s->x.m_b <= (*s2)->id && (*s2)->id < s->x.r_b) && s->t.t1--)
	{
		if (s->t.t4 < 6)
		{
			if (!(*s2)->next->f && (*s2)->id < (*s2)->next->id)
			{
				if (*s1 && (*s1)->next && !(*s1)->next->f \
							&& (*s1)->id > (*s1)->next->id)
					swap_double(s, s1, s2);
				else
					swap(s, s2);
			}
			else if (s->t.t4 < 4 && (*s1)->id > (*s1)->next->id)
				swap(s, s1);
			push(s, s2, s1);
		}
		else
			push(s, s2, s1);
		if (s->t.t4 > 5 && (s->x.m_b <= (*s1)->id && (*s1)->id < s->x.mr_b) \
															&& ++s->t.t3)
			rotate(s, s1);
	}
	if (s->t.t1 && !(s->x.m_b <= (*s2)->id && (*s2)->id < s->x.r_b) \
														&& ++s->t.t2)
		rotate(s, s2);
}

void	sort_basic_rev_2(t_structs *s, t_node **s1, t_node **s2)
{
	if (s->t.t2)
	{
		s->t.t9 = s->t.t3;
		while (s->t.t2 && s->t.t2--)
		{
			if (s->t.t3 && s->t.t3-- && ++s->t.t8)
				rev_rotate_double(s, s1, s2);
			else
				rev_rotate(s, s2);
			(*s2)->f = 0;
			if (!s->t.t2 && s->t.t9 < 6 && s->t.t3 && s->t.t3-- && ++s->t.t8)
				rev_rotate(s, s1);
			if (s->t.t9 && s->t.t9 < 6 && s->t.t3 == 0)
			{
				sort_up_to_five (s, s1, s2);
				s->t.t9 = 0;
			}
		}
		(*s2)->f = 1;
		while (s->t.t3 && s->t.t3-- && ++s->t.t8)
			rev_rotate(s, s1);
		while (s->t.t9 > 5 && s->t.t8 && s->t.t8--)
			push(s, s1, s2);
		(*s2)->f = 1;
	}
}
