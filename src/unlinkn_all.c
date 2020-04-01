/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlinkn_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 21:40:59 by bchaleil          #+#    #+#             */
/*   Updated: 2020/03/31 21:40:59 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_enum_list	unlinkn_all(t_list *list, void (*cb)(void*))
{
	t_node	*node;
	t_node	*tmp_node;

	if (list->size == 0)
		return (LIST_EMPTY);
	node = list->head;
	while (node)
	{
		tmp_node = node->next;
		if (cb)
			cb(node->data);
		unlinkn(list, node);
		node = tmp_node;
	}
	return (LIST_OK);
}
