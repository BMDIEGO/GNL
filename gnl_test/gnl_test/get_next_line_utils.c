/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:21 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 13:14:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Esta función une dos cadenas de caracteres (s1 y s2) en una nueva cadena.
char	*ft_strjoin_gnl(char *s1, char *s2)
{
    int		tamanototal; // Variable para almacenar la longitud total de la nueva cadena.
    char	*resultado; // Puntero para la nueva cadena resultante.
    int		i; // Índice para recorrer s1.
    int		j; // Índice para recorrer s2.

    i = 0;
    tamanototal = ft_strlen(s1) + ft_strlen(s2); // Calcula la longitud total de la nueva cadena.
    resultado = malloc((tamanototal + 1)); // Asigna memoria para la nueva cadena.
    if (!resultado || !s1 || !s2) // Verifica si la asignación de memoria fue exitosa y si s1 y s2 no son NULL.
        return (NULL);
    while (s1[i] != 0) // Copia s1 en la nueva cadena.
    {
        resultado[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != 0) // Copia s2 en la nueva cadena.
    {
        resultado[i] = s2[j];
        i++;
        j++;
    }
    resultado[tamanototal] = 0; // Añade el carácter nulo al final de la nueva cadena.
    free (s1); // Libera la memoria de s1.
    return (resultado); // Devuelve la nueva cadena.
}

// Esta función calcula la longitud de una cadena de caracteres.
size_t	ft_strlen(char *s)
{
    int	i; // Índice para recorrer la cadena.

    i = 0;
    while (s[i]) // Recorre la cadena hasta encontrar el carácter nulo.
        i++;
    return (i); // Devuelve la longitud de la cadena.
}

// Esta función asigna memoria para un array de nmemb elementos de tamaño size y la inicializa a cero.
char	*ft_calloc_gnl(size_t nmemb, size_t size)
{
    char	*resultado; // Puntero para el array resultante.
    size_t	i; // Índice para recorrer el array.
    size_t	longitud; // Longitud total del array.

    longitud = size * nmemb; // Calcula la longitud total del array.
    resultado = malloc(longitud); // Asigna memoria para el array.
    if (!resultado) // Verifica si la asignación de memoria fue exitosa.
        return (NULL);
    i = 0;
    while (i < longitud) // Inicializa el array a cero.
    {
        resultado[i] = 0;
        ++i;
    }
    return (resultado); // Devuelve el array inicializado.
}

// Esta función busca el primer carácter c en la cadena s y devuelve un puntero a esa posición.
char	*ft_strchr(char *s, int c)
{
    char	*str; // Puntero para recorrer la cadena.

    str = s;
    while (*str != c && *str != 0) // Recorre la cadena hasta encontrar el carácter c o el carácter nulo.
        str++;
    if (*str == c) // Si encuentra el carácter c, devuelve un puntero a esa posición.
        return (str);
    else // Si no encuentra el carácter c, devuelve NULL.
        return (NULL);
}
