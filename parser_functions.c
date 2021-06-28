/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:09:14 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 19:05:59 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero_k_pos(t_node *s1)
{
	while (s1)
	{
		s1->k = 0;
		s1->f = 0;
		s1 = s1->next;
	}
}

void	sort_id_by_val(t_structs *s, t_node *s1, int size)
{
	int	i;

	s->tmp1 = s1;
	i = size;
	while (i-- && s->tmp1->next)
	{
		s->tmp2 = s->tmp1->next;
		while (s->tmp2)
		{
			if (s->tmp2->val < s->tmp1->val)
			{
				s->t.t1 = s->tmp1->val;
				s->t.t2 = s->tmp1->f;
				s->tmp1->val = s->tmp2->val;
				s->tmp1->f = s->tmp2->f;
				s->tmp2->val = s->t.t1;
				s->tmp2->f = s->t.t2;
			}
			s->tmp2 = s->tmp2->next;
		}
		s->tmp1 = s->tmp1->next;
	}
}

void	sort_val_by_pas(t_structs *s, t_node *s1, int size)
{
	s->tmp1 = s1;
	s->t.t4 = size;
	while (s->t.t4-- && s->tmp1->next)
	{
		s->tmp2 = s->tmp1->next;
		while (s->tmp2)
		{
			if (s->tmp2->f < s->tmp1->f)
			{
				s->t.t1 = s->tmp1->f;
				s->t.t2 = s->tmp1->id;
				s->t.t3 = s->tmp1->val;
				s->tmp1->f = s->tmp2->f;
				s->tmp1->id = s->tmp2->id;
				s->tmp1->val = s->tmp2->val;
				s->tmp2->f = s->t.t1;
				s->tmp2->id = s->t.t2;
				s->tmp2->val = s->t.t3;
			}
			s->tmp2 = s->tmp2->next;
		}
		s->tmp1 = s->tmp1->next;
	}
	zero_k_pos (s1);
}

void	pars_argv (t_structs *s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		ft_bzero(&s->t, sizeof(t_temp));
		if (ft_strchr(argv[i], '.'))
			output_and_exit("Error");
		while (argv[i][s->t.t1])
			if (ft_isalpha(argv[i][s->t.t1++]))
				output_and_exit("Error");
		while (++s->t.t2 != i)
			if (ft_atoi_o(argv[i]) == ft_atoi_o(argv[s->t.t2]))
				output_and_exit("Error");
		while (argv[i][s->t.t3])
			if (argv[i][s->t.t3++] == '-' && !ft_isdigit(argv[i][s->t.t3]))
				output_and_exit("Error");
		while (argv[i][s->t.t4])
			if (argv[i][s->t.t4++] == '+' && !ft_isdigit(argv[i][s->t.t4]))
				output_and_exit("Error");
	}
}

void	parsing_input(t_structs *s, t_node **s1, t_node **s2, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(s, s1);
	else if (!ft_strcmp(line, "sb"))
		swap(s, s2);
	else if (!ft_strcmp(line, "ss"))
		swap_double(s, s1, s2);
	else if (!ft_strcmp(line, "pa"))
		push(s, s2, s1);
	else if (!ft_strcmp(line, "pb"))
		push(s, s1, s2);
	else if (!ft_strcmp(line, "ra"))
		rotate(s, s1);
	else if (!ft_strcmp(line, "rb"))
		rotate(s, s2);
	else if (!ft_strcmp(line, "rr"))
		rotate_double(s, s1, s2);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate(s, s1);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate(s, s2);
	else if (!ft_strcmp(line, "rrr"))
		rev_rotate_double(s, s1, s2);
	else
		output_and_exit("Error");
}
