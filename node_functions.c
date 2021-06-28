/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:09:04 by feschall          #+#    #+#             */
/*   Updated: 2021/06/24 20:35:41 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int set_id, int set_date, int set_b)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit (0);
	node->id = set_id;
	node->f = set_id;
	node->k = set_b;
	node->val = set_date;
	node->next = NULL;
	return (node);
}

void	add_befor_node(t_node **node, int set_id, int set_date, int set_b)
{
	t_node	*new_node;

	new_node = create_node(set_id, set_date, set_b);
	new_node->next = *node;
	*node = new_node;
}

void	add_after_node(t_node **node, int set_id, int set_date, int set_b)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = create_node(set_id, set_date, set_b);
	if (*node)
	{
		tmp = *node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*node = new_node;
}
