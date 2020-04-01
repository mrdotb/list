/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlinkn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 21:29:28 by bchaleil          #+#    #+#             */
/*   Updated: 2020/03/31 21:29:28 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*unlinkn(t_list *list, t_node *node)
{
	void	*data;

	data = node->data;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->prev == NULL)
		list->head = node->next;
	if (node->next == NULL)
		list->tail = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node);
	list->size -= 1;
	return (data);
}
