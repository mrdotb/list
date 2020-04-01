/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_all_cb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:32:01 by bchaleil          #+#    #+#             */
/*   Updated: 2020/04/02 02:32:01 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_enum_list	list_remove_all_cb(t_list *list, void (*cb)(void*))
{
	if (unlinkn_all(list, cb) == LIST_OK)
	{
		list->head = NULL;
		list->tail = NULL;
		return (LIST_OK);
	}
	return (LIST_EMPTY);

}
