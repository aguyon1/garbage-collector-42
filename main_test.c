/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:44:29 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/05 10:29:35 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include <string.h>
#include <unistd.h>

static char	*my_strdup(const char *str)
{
	char	*new;

	new = gc_malloc(strlen(str) + 1, NULL);
	if (new == NULL)
		return (NULL);
	return (strcpy(new, str));
}

static void	putstr_endl(const char *str)
{
	write(1, str, strlen(str));
	write(1, "\n", 1);
}

int	main(void)
{
	char	*str;
	char	*str2;

	str = my_strdup("Bonjour");
	str2 = my_strdup("Hello");
	str = my_strdup("Hola");
	putstr_endl(str);
	putstr_endl(str2);
	return (0);
}
