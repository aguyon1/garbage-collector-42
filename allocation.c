/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:42:38 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/28 22:36:08 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"

static void	handle_alloc(t_memory_list *node, t_alloc_flag flag)
{
	static t_memory_list	*memory_list = NULL;

	if (flag & ALLOC)
		memory_list_add(&memory_list, node);
	else if (flag & FREEALL)
		memory_list_clear(&memory_list);
	else if (flag & FREE)
		memory_list = node;
}

void	*xmalloc(size_t size)
{
	t_memory_list	*node;

	node = memory_list_new(size, NULL);
	if (node == NULL)
		return (NULL);
	handle_alloc(node, ALLOC);
	return (node->memory);
}

void	*xmalloc_del(size_t size, void *del)
{
	t_memory_list	*node;

	node = memory_list_new(size, del);
	if (node == NULL)
		exit(1);
	handle_alloc(node, ALLOC);
	return (node->memory);
}

void	xfree_all(void)
{
	handle_alloc(NULL, FREEALL);
}

void	xfree(void *ptr)
{
	t_memory_list	*node;
	t_memory_list	*prev;
	t_memory_list	*next;

	if (ptr == NULL)
		return ;
	node = memory_list_get_node(ptr);
	prev = node->prev;
	next = node->next;
	if (node->del)
		node->del(node->memory);
	free(node);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (prev == NULL)
		handle_alloc(next, FREE);
}
