/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:28 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 13:12:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Lee del archivo hasta encontrar un salto de línea o EOF
char	*read_until_jump(char *s_buffer, int fd)
{
    char	*tr_buffer;
    int		leido;

    tr_buffer = ft_calloc_gnl (1, BUFFER_SIZE + 1);
    if (!tr_buffer)
        return (NULL);
    while (!ft_strchr(s_buffer, 10))
    {
        leido = read (fd, tr_buffer, BUFFER_SIZE);
        if (leido < 0)
        {
            free(s_buffer);
            free(tr_buffer);
            return (NULL);
        }
        if (leido == 0)
            break ;
        tr_buffer[leido] = 0;
        s_buffer = ft_strjoin_gnl(s_buffer, tr_buffer);
    }
    free(tr_buffer);
    return (s_buffer);
}

// Extrae una línea completa del buffer
char	*full_line(char *s_buffer)
{
    char	*linea;
    int		i;
    int		j;

    i = 0;
    if (!s_buffer[i])
        return (NULL);
    while (s_buffer[i] != 10 && s_buffer[i])
        ++i;
    linea = ft_calloc_gnl(1, i + 2);
    if (!linea)
        return (NULL);
    j = 0;
    while (j <= i)
    {
        linea[j] = s_buffer[j];
        ++j;
    }
    return (linea);
}

// Resta el buffer después de extraer una línea
char	*rest_buffer(char *s_buffer)
{
    int		i;
    int		j;
    char	*new_buffer;

    i = 0;
    while (s_buffer[i] && s_buffer[i] != '\n')
        i++;
    if (!s_buffer[i])
    {
        free(s_buffer);
        return (NULL);
    }
    new_buffer = ft_calloc_gnl((ft_strlen(s_buffer) - i + 1), sizeof(char));
    i += 1;
    j = 0;
    while (s_buffer[i - 1])
    {
        new_buffer[j] = s_buffer[i];
        ++i;
        ++j;
    }
    free(s_buffer);
    return (new_buffer);
}

// Función principal para obtener la siguiente línea de un archivo
char	*get_next_line(int fd)
{
    static char	*s_buffer;
    char		*linea;

    if (!s_buffer)
        s_buffer = ft_calloc_gnl (1, BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    s_buffer = read_until_jump(s_buffer, fd);
    if (!s_buffer)
        return (NULL);
    linea = full_line(s_buffer);
    s_buffer = rest_buffer(s_buffer);
    return (linea);
}
