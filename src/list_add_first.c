/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 20:41:39 by bchaleil          #+#    #+#             */
/*   Updated: 2020/03/31 20:41:39 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_enum_list	list_add_first(t_list *list, void *element)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (LIST_ERR_ALLOC);
	node->data = element;
	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->size += 1;
	return (LIST_OK);
}
