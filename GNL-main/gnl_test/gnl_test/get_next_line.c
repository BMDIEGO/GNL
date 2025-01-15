/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:28 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 16:23:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Lee del archivo hasta encontrar un salto de línea o el final del archivo. Esta funcion se usa para leer el archivo y almacenar su contenido en el buffer
char	*leer_buffer(char *s_buffer, int fd) // Recibe el buffer y el descriptor de archivo. el fd es el file descriptor que se pasa como argumento
{
    char	*tr_buffer; // Buffer temporal para leer del archivo
    int		leido; // Cantidad de bytes leídos

    tr_buffer = ft_calloc_gnl(1, BUFFER_SIZE + 1); // Asigna memoria para el buffer temporal. Se hace el +1 para añadir el carácter nulo al final del buffer
    if (!tr_buffer) // Verifica si la asignación de memoria fue exitosa
        return (NULL);
    while (!ft_strchr(s_buffer, 10)) // Mientras no se encuentre un salto de línea en el buffer. El 10 es el valor ASCII del salto de línea
    {
        leido = read(fd, tr_buffer, BUFFER_SIZE); // Lee del archivo
        if (leido < 0) // Si hay un error en la lectura. Si el valor de retorno es menor a 0, significa que hubo un error ya que read retorna la cantidad de bytes leídos
        {
            free(s_buffer);
            free(tr_buffer);
            return (NULL);
        }
        if (leido == 0) // Si se llega al final del archivo
            break;
        tr_buffer[leido] = 0; // Añade el carácter nulo al final del buffer temporal
        s_buffer = ft_strjoin_gnl(s_buffer, tr_buffer); // Une el buffer temporal al buffer principal esto se hace para que el buffer principal tenga todo el contenido del archivo
    }
    free(tr_buffer); // Libera la memoria del buffer temporal
    return (s_buffer); // Devuelve el buffer principal
}

// Extrae una línea completa del buffer. Esta funcion se usa para extraer una línea del buffer y almacenarla en una variable
char	*extraer_linea(char *s_buffer)
{
    char	*linea; // Puntero para la línea extraída
    int		i; // Índice para recorrer el buffer
    int		j; // Índice para recorrer la línea

    i = 0;
    if (!s_buffer[i]) // Si el buffer está vacío
        return (NULL);
    while (s_buffer[i] != 10 && s_buffer[i]) // Recorre el buffer hasta encontrar un salto de línea o el final del buffer
        ++i;
    linea = ft_calloc_gnl(1, i + 2); // Asigna memoria para la línea extraída
    if (!linea) // Verifica si la asignación de memoria fue exitosa
        return (NULL);
    j = 0;
    while (j <= i) // Copia la línea del buffer
    {
        linea[j] = s_buffer[j];
        ++j;
    }
    return (linea); // Devuelve la línea extraída
}

// Resta el buffer después de extraer una línea.
char	*restar_buffer(char *s_buffer)
{
    int		i; // Índice para recorrer el buffer
    int		j; // Índice para recorrer el nuevo buffer
    char	*new_buffer; // Puntero para el nuevo buffer

    i = 0;
    while (s_buffer[i] && s_buffer[i] != '\n') // Recorre el buffer hasta encontrar un salto de línea o el final del buffer.
        i++;
    if (!s_buffer[i]) // Si no se encuentra un salto de línea
    {
        free(s_buffer);
        return (NULL);
    }
    new_buffer = ft_calloc_gnl((ft_strlen(s_buffer) - i + 1), sizeof(char)); // Asigna memoria para el nuevo buffer
    i += 1;
    j = 0;
    while (s_buffer[i - 1]) // Copia el resto del buffer al nuevo buffer
    {
        new_buffer[j] = s_buffer[i];
        ++i;
        ++j;
    }
    free(s_buffer); // Libera la memoria del buffer original
    return (new_buffer); // Devuelve el nuevo buffer
}

// Función principal para obtener la siguiente línea de un archivo
char	*get_next_line(int fd)
{
    static char	*s_buffer; // Buffer estático para almacenar los datos leídos
    char		*linea; // Puntero para la línea extraída

    if (!s_buffer) // Si el buffer está vacío
        s_buffer = ft_calloc_gnl(1, BUFFER_SIZE + 1); // Asigna memoria para el buffer
    if (fd < 0 || BUFFER_SIZE <= 0) // Verifica si el descriptor de archivo es válido y si el tamaño del buffer es mayor a cero
        return (NULL);
    s_buffer = leer_buffer(s_buffer, fd); // Lee del archivo hasta encontrar un salto de línea
    if (!s_buffer) // Si no se pudo leer del archivo
        return (NULL);
    linea = extraer_linea(s_buffer); // Extrae una línea completa del buffer
    s_buffer = restar_buffer(s_buffer); // Resta el buffer después de extraer la línea
    return (linea); // Devuelve la línea extraída
}
