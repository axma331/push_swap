/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:10:19 by feschall          #+#    #+#             */
/*   Updated: 2021/06/24 14:34:53 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_structs *s, t_node **s1)
{
	if (!*s1 || !(*s1)->next)
		return ;
	s->tmp1 = (*s1)->next->next;
	s->tmp2 = (*s1);
	*s1 = (*s1)->next;
	(*s1)->next = s->tmp2;
	(*s1)->next->next = s->tmp1;
	if (s->o == -1)
		s->o += 2;
	else if (s->o == 1)
		s->o += 3;
	else
		s->o = 2 + (*s1)->k;
	output_result(s);
}

void	rotate(t_structs *s, t_node **s1)
{
	if (!*s1 || !(*s1)->next || !(*s1)->next->next)
		return ;
	s->tmp1 = *s1;
	s->tmp2 = s->tmp1->next;
	while ((*s1)->next)
		*s1 = (*s1)->next;
	s->tmp1->next = NULL;
	(*s1)->next = s->tmp1;
	*s1 = s->tmp2;
	if (s->o == -4)
		s->o += 5;
	else if (s->o == 1)
		s->o += 6;
	else
		s->o = 5 + (*s1)->k;
	output_result(s);
}

void	rev_rotate(t_structs *s, t_node **s1)
{
	if (!*s1 || !(*s1)->next || !(*s1)->next->next)
		return ;
	s->tmp1 = *s1;
	while ((*s1)->next)
		*s1 = (*s1)->next;
	s->tmp2 = s->tmp1;
	while (s->tmp1->next->next)
		s->tmp1 = s->tmp1->next;
	s->tmp1->next = NULL;
	s->tmp1 = s->tmp2;
	if (!(*s1)->next)
		(*s1)->next = s->tmp1;
	if (s->o == -7)
		s->o += 8;
	else if (s->o == 1)
		s->o += 9;
	else
		s->o = 8 + (*s1)->k;
	output_result(s);
}

void	push(t_structs *s, t_node **out_s, t_node **in_s)
{
	if (!*out_s)
		return ;
	s->tmp1 = *out_s;
	s->tmp2 = (*out_s)->next;
	s->tmp1->next = NULL;
	add_befor_node(in_s, (*s->tmp1).id, (*s->tmp1).val, (*s->tmp1).k);
	*out_s = s->tmp2;
	if (!(*in_s)->k)
		(*in_s)->k = 1;
	else
		(*in_s)->k = 0;
	s->o = 11 + (*in_s)->k;
	output_result(s);
	s->o = 0;
	if (*out_s)
		(*in_s)->f = 0;
	else
		(*in_s)->f = 0;
	free (s->tmp1);
}
