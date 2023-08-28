/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:44:29 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/28 22:55:42 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static char	*my_strdup(const char *str)
{
	return (strcpy(xmalloc(strlen(str) + 1), str));
}

// static void	putstr_endl(const char *str)
// {
// 	write(1, str, strlen(str));
// 	write(1, "\n", 1);
// }

// void	dummy(void)
// {
// 	char *str = malloc(1000);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	*str2;

// 	str = my_strdup("Bonjour");
// 	str2 = my_strdup("Hello");
// 	str = my_strdup("Hola");
// 	putstr_endl(str);
// 	putstr_endl(str2);
// 	dummy();
// 	return (0);
// }

int main(void)
{
	char *str1 = my_strdup("un");
	char *str2 = my_strdup("deux");
	char *str3 = my_strdup("trois");

	puts(str1);
	puts(str2);
	puts(str3);

	xfree(str1);
	xfree(str2);
	xfree(str3);
}
