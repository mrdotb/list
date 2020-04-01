/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:25:27 by bchaleil          #+#    #+#             */
/*   Updated: 2020/04/02 02:25:27 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_enum_list	list_remove_all(t_list *list)
{
	if (unlinkn_all(list, NULL) == LIST_OK)
	{
		list->head = NULL;
		list->tail = NULL;
		return (LIST_OK);
	}
	return (LIST_EMPTY);
}
