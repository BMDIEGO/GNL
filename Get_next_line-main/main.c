/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:44 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 12:35:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int			fd;
	static char	*line;

	fd = open("hola.txt", 0);
	if (fd == 0)
		return (0);
	line = get_next_line(fd);
	printf("\n");
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		printf("\n");
		free(line);
	}
	close(fd);
	return (0);
}
