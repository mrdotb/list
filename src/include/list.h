/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:11:46 by bchaleil          #+#    #+#             */
/*   Updated: 2020/03/31 18:11:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

/*
** A doubly linked list. List is a sequential structure that
** supports insertion, deletion and lookup from both ends in
** constant time, while the worst case is O(n/2) at the middle
** of the list.
*/

typedef struct		s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_list
{
	size_t			size;
	t_node			*head;
	t_node			*tail;
}					t_list;

typedef struct		s_list_iter
{
	size_t			index;
	t_list			*list;
	t_node			*last;
	t_node			*next;
}					t_list_iter;

typedef enum		e_list
{
	LIST_OK = 0,
	LIST_ERR_ALLOC = 1,
	LIST_ITER_END = 2,
	LIST_EMPTY = 3,
}					t_enum_list;

t_enum_list			list_new(t_list **out);

void				list_destroy(t_list *list);
void				list_destroy_cb(t_list *list, void (*cb)(void*));
t_enum_list			list_remove_all(t_list *list);
t_enum_list			list_remove_all_cb(t_list *list, void (*cb)(void*));
void				*unlinkn(t_list *list, t_node *node);
t_enum_list			unlinkn_all(t_list *list, void (*cb)(void*));

t_enum_list			list_add_first(t_list *list, void *element);
t_enum_list			list_add_last(t_list *list, void *element);
t_enum_list			list_add_at(t_list *list, void *element, size_t index);
t_enum_list			list_add_first(t_list *list, void *element);

size_t				list_size(t_list *list);

#endif
