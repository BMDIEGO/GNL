/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:21 by marvin            #+#    #+#             */
/*   Updated: 2024/12/17 13:38:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Une dos cadenas de caracteres (s1 y s2) en una nueva cadena.
char	*ft_strjoin_gnl(char *s1, char *s2)
{
    int		tamanototal;
    char	*resultado;
    int		i;
    int		j;

    i = 0;
    tamanototal = ft_strlen(s1) + ft_strlen(s2);
    resultado = malloc((tamanototal + 1));
    if (!resultado || !s1 || !s2)
        return (NULL);
    while (s1[i] != 0)
    {
        resultado[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != 0)
    {
        resultado[i] = s2[j];
        i++;
        j++;
    }
    resultado[tamanototal] = 0;
    free (s1);
    return (resultado);
}

// Calcula la longitud de una cadena de caracteres.
size_t	ft_strlen(char *s)
{
    int	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

// Asigna memoria para un array de nmemb elementos de tamaño size y la inicializa a cero.
char	*ft_calloc_gnl(size_t nmemb, size_t size)
{
    char	*resultado;
    size_t	i;
    size_t	longitud;

    longitud = size * nmemb;
    resultado = malloc(longitud);
    if (!resultado)
        return (NULL);
    i = 0;
    while (i < longitud)
    {
        resultado[i] = 0;
        ++i;
    }
    return (resultado);
}

// Función busca el primer carácter c en la cadena s y devuelve un puntero a esa posición.
char	*ft_strchr(char *s, int c)
{
    char	*str;

    str = s;
    while (*str != c && *str != 0)
        str++;
    if (*str == c)
        return (str);
    else
        return (NULL);
}
