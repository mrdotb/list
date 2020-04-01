/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy_cb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:20:30 by bchaleil          #+#    #+#             */
/*   Updated: 2020/04/02 02:20:30 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_destroy_cb(t_list *list, void (*cb)(void*))
{
	if (list->size > 0)
		list_remove_all_cb(list, cb);
	free(list);
}
