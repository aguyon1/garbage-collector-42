/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:42:48 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/05 10:00:18 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>
# include <stddef.h>

# define GCALLOC 1
# define GCFREE 2

typedef struct s_garbage_list	t_garbage_list;

struct s_garbage_list
{
	struct s_garbage_list	*next;
	void					(*del)(void *);
	char					memory[1];
};

/* LIBRARY FUNCTIONS */
void			*gc_malloc(size_t size, void *del);
void			gc_freeall(void) __attribute__((destructor));

/*	UTILS	*/
void			glist_addfront(t_garbage_list **glist, t_garbage_list *node);
t_garbage_list	*glistnew(size_t size, void *del);
void			glistclear(t_garbage_list **list);
t_garbage_list	*get_gcnode(void *memory);

#endif