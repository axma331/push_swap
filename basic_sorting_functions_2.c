/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting_functions_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:08:51 by feschall          #+#    #+#             */
/*   Updated: 2021/06/24 23:52:51 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_four_five(t_structs *s, t_node **s1, t_node **s2)
{
	s->cnt = counter_befor_flags(s, s1);
	while (3 <= s->cnt && s->cnt <= 5 && (*s1)->next->next->next \
							&& !(orderliness(s, s1, s->cnt)))
	{
		while (!(orderliness(s, s1, s->cnt)) && !(*s1)->next->f)
		{
			sort_three_four_five_1(s, s1, s2);
			if (sort_three_four_five_2(s, s1, s2))
				break ;
		}
		while (s->t.t5 || s->t.t6)
			sort_three_four_five_3(s, s1, s2);
	}
}

void	sort_three_four_five_1(t_structs *s, t_node **s1, t_node **s2)
{
	if ((*s1)->id > (*s1)->next->id)
	{
		if (*s2 && (*s2)->next && (*s2)->id < (*s2)->next->id \
											&& !(*s2)->next->f)
		{
			swap_double(s, s1, s2);
			s->t.t7 = (*s2)->f;
			(*s2)->f = (*s2)->next->f;
			(*s2)->next->f = s->t.t7;
		}
		else
			swap(s, s1);
	}
}

int	sort_three_four_five_2(t_structs *s, t_node **s1, t_node **s2)
{
	if (((*s1)->id < (*s1)->next->id) && !(*s1)->next->f \
							&& !(orderliness(s, s1, s->cnt)))
	{
		if (s->cnt == 4 && s->t.t5 >= 1 && s->t.t6 == 1 \
							&& (*s1)->next->id == s->all - 1)
			return (1);
		else if (s->cnt == 5 && s->t.t5 >= 1 && s->t.t6 == 2 \
								&& (*s1)->next->id == s->all - 1)
			return (1);
		if (s->cnt == 4 && ((*s1)->id == s->all - s->cnt) \
								&& (*s1)->next->next && ++s->t.t6)
			rotate(s, s1);
		else if (s->cnt == 5 && ((*s1)->id == s->all - s->cnt \
		|| (*s1)->id == s->all - (s->cnt - 1)) && (*s1)->next->next \
														&& ++s->t.t6)
			rotate(s, s1);
		else if ((*s1)->next->next && !(*s1)->next->next->f && ++s->t.t5)
			push(s, s1, s2);
		else
			return (1);
	}
	return (0);
}

void	sort_three_four_five_3(t_structs *s, t_node **s1, t_node **s2)
{
	if (*s2 && (*s2)->next && ((*s2)->id < (*s2)->next->id) && !(*s2)->f \
														&& !(*s2)->next->f)
		swap(s, s2);
	else if (*s2 && !(*s2)->f && s->t.t5 && s->t.t5--)
	{
		push(s, s2, s1);
		if ((*s1)->id > (*s1)->next->id)
		{
			if (*s2 && (*s2)->next && (*s2)->id < (*s2)->next->id && !(*s2)->f \
															&& !(*s2)->next->f)
				swap_double(s, s1, s2);
			else
				swap(s, s1);
		}
	}
	else if (!s->t.t5 && s->t.t6--)
		rev_rotate(s, s1);
}

void	sort_up_to_five(t_structs *s, t_node **s1, t_node **s2)
{
	s->cnt = counter_befor_flags(s, s1);
	if (s->cnt < 6)
	{
		sort_two(s, s1);
		sort_three(s, s1);
		sort_four(s, s1, s2);
		sort_five(s, s1, s2);
		sort_three_four_five(s, s1, s2);
		if (orderliness(s, s1, s->cnt) && *s2)
		{
			s->all = (*s1)->id;
			return ;
		}
		if (orderliness(s, s1, s->cnt) && !*s2)
			exit (0);
	}
}
