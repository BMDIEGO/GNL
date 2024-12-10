/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:35:33 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 13:17:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // Para funciones de asignación de memoria y NULL
# include <sys/types.h> // Para tipos de datos como size_t
# include <sys/uio.h> // Para la función read
# include <unistd.h> // Para funciones del sistema como read y close
# include <fcntl.h> // Para la función open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 // Define el tamaño del buffer si no está definido
# endif

// Prototipos de funciones
char	*get_next_line(int fd); // Función principal para obtener la siguiente línea de un archivo
char	*ft_strjoin_gnl(char *s1, char *s2); // Une dos cadenas de caracteres
char	*ft_strchr(char *s, int c); // Busca el primer carácter c en la cadena s
char	*ft_calloc_gnl(size_t nmemb, size_t size); // Asigna memoria para un array y la inicializa a cero
size_t	ft_strlen(char *s); // Calcula la longitud de una cadena de caracteres

#endif