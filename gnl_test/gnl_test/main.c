/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:44 by marvin            #+#    #+#             */
/*   Updated: 2024/12/12 15:09:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int			fd;
	static char	*line;

	fd = open("hola.txt", O_RDONLY); // Cambia el modo de apertura a O_RDONLY
	if (fd < 0) // Verifica si el archivo se abrió correctamente
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line); // Imprime la línea sin un salto de línea adicional
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
