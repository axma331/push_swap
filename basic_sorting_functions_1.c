/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting_functions_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:08:39 by feschall          #+#    #+#             */
/*   Updated: 2021/06/23 12:22:39 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_structs *s, t_node **s1)
{
	if (s->cnt == 2)
	{
		if ((*s1)->id > (*s1)->next->id)
		{
			swap(s, s1);
			(*s1)->f = 1;
		}
		else
			(*s1)->f = 1;
	}
}

void	sort_three(t_structs *s, t_node **s1)
{
	s->cnt = counter_befor_flags(s, s1);
	while (s->cnt == 3 && !(*s1)->next->next->next)
	{
		s->t.t5 = (*s1)->id - (*s1)->next->id;
		s->t.t6 = (*s1)->next->id - (*s1)->next->next->id;
		if (s->t.t5 == 1 && s->t.t6 == -2)
			swap(s, s1);
		else if (s->t.t5 == -1 && s->t.t6 == 2)
			rev_rotate(s, s1);
		else if (s->t.t5 == -2 && s->t.t6 == 1)
		{
			rev_rotate(s, s1);
			swap(s, s1);
		}
		else if (s->t.t5 == 1 && s->t.t6 == 1)
		{
			rotate(s, s1);
			swap(s, s1);
		}
		else if (s->t.t5 == 2 && s->t.t6 == -1)
			rotate(s, s1);
		else if (s->t.t5 == -1 && s->t.t6 == -1)
			break ;
	}
}

void	sort_four(t_structs *s, t_node **s1, t_node **s2)
{
	if (s->cnt == 4 && !(*s1)->next->next->next->next)
	{
		while (!orderliness(s, s1, s->cnt))
		{
			if (((*s1)->id == s->all - 4) && ++s->t.t7)
				push(s, s1, s2);
			if (s->t.t7 != 1 && ((*s1)->id == s->all - 1 \
				|| (*s1)->id == s->all - 2 || (*s1)->id == s->all - 3))
				rotate(s, s1);
			if (s->t.t7 == 1)
			{
				sort_three(s, s1);
				while (s->t.t7 --)
					push(s, s2, s1);
			}
		}
	}
}

void	sort_five(t_structs *s, t_node **s1, t_node **s2)
{
	if (s->cnt == 5 && !(*s1)->next->next->next->next->next)
	{
		while (!orderliness(s, s1, s->cnt))
		{
			if (((*s1)->id == s->all - 5 || (*s1)->id == s->all - 4) \
														&& ++s->t.t7)
				push(s, s1, s2);
			if (s->t.t7 != 2 && ((*s1)->id == s->all - 1 \
				|| (*s1)->id == s->all - 2 || (*s1)->id == s->all - 3))
				rotate(s, s1);
			if (s->t.t7 == 2)
			{
				sort_three(s, s1);
				while (s->t.t7 --)
					push(s, s2, s1);
				if ((*s1)->id > (*s1)->next->id)
					swap(s, s1);
			}
		}
	}
}

void	sort_five_out_s2(t_structs *s, t_node **s1, t_node **s2, size_t cnt)
{
	s->t.t5 = cnt;
	while (cnt--)
	{
		if (*s2 && (*s2)->next && !(*s2)->next->f \
						&& (*s2)->id < (*s2)->next->id)
		{
			if (*s1 && (*s1)->next && !(*s1)->next->f \
							&& (*s1)->id > (*s1)->next->id)
				swap_double(s, s1, s2);
			else
				swap(s, s2);
		}
		else if ((*s1)->id > (*s1)->next->id)
			swap(s, s1);
		if (s->t.t5 > 3 && cnt == 1 && (*s2)->id == s->all - 1 && ++s->t.t6)
			rotate(s, s1);
		push (s, s2, s1);
	}
	while (s->t.t6--)
		rev_rotate(s, s1);
	if ((*s1)->id > (*s1)->next->id)
		swap(s, s1);
}
