/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:48:23 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/05 10:28:21 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_garbage_list	*glist_addfront(t_garbage_list **glist, t_garbage_list *node)
{
	if (*glist != NULL)
		node->next = *glist;
	*glist = node;
}

t_garbage_list	*glistnew(size_t size, void *del)
{
	t_garbage_list	*new;

	new = malloc(sizeof(t_garbage_list) + size - 1);
	if (new == NULL)
		return (NULL);
	*new = (t_garbage_list){.next = NULL, .del = del};
	return (new);
}

void	glistclear(t_garbage_list **list)
{
	t_garbage_list	*current;
	t_garbage_list	*next;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		if (current->del)
			current->del(current->memory);
		free(current);
		current = next;
	}
	*list = NULL;
}

t_garbage_list	*get_gcnode(void *memory)
{
	return (memory - offsetof(t_garbage_list, memory));
}
