/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:44:29 by aguyon            #+#    #+#             */
/*   Updated: 2023/08/29 01:33:57 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static char	*xstrdup(const char *str)
{
	return (strcpy(xmalloc(strlen(str) + 1), str));
}

void	putstr(const char *str)
{
	write(1, str, strlen(str));
}

int	main(void)
{
	char *const	str1 = xstrdup("un");
	char *const	str2 = xstrdup("deux");
	char *const	str3 = xstrdup("trois");

	puts(str1);
	puts(str2);
	puts(str3);
	xfree(str1);
	xfree(str2);
	xfree(str3);
}
