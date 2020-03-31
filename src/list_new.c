/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 19:32:28 by bchaleil          #+#    #+#             */
/*   Updated: 2020/03/31 19:35:13 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_enum_list	list_new(t_list **out)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (LIST_ERR_ALLOC);
	list->size = 0;
	*out = list;
	return (LIST_OK);
}
