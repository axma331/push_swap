/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:10:26 by feschall          #+#    #+#             */
/*   Updated: 2021/06/24 14:35:09 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_double(t_structs *s, t_node **s1, t_node **s2)
{
	s->o = -1;
	swap(s, s1);
	swap(s, s2);
	s->o = 0;
}

void	rotate_double(t_structs *s, t_node **s1, t_node **s2)
{
	s->o = -4;
	rotate(s, s1);
	rotate(s, s2);
	s->o = 0;
}

void	rev_rotate_double(t_structs *s, t_node **s1, t_node **s2)
{
	s->o = -7;
	rev_rotate(s, s1);
	rev_rotate(s, s2);
	s->o = 0;
}
