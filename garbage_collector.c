/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:42:38 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/05 09:50:07 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

static void	handle_alloc(t_garbage_list *node, int option)
{
	static t_garbage_list	*garbage_list = NULL;

	if (option == GCALLOC)
		glist_addfront(&garbage_list, node);
	else if (option == GCFREE)
		glistclear(&garbage_list);
}

void	*gc_malloc(size_t size, void *del)
{
	t_garbage_list	*node;

	node = glistnew(size, del);
	if (node == NULL)
		return (NULL);
	handle_alloc(node, GCALLOC);
	return (node->memory);
}

void	gc_freeall(void)
{
	handle_alloc(NULL, GCFREE);
}
