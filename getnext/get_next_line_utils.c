#include "get_next_line.h"

// Calcula la longitud de una cadena de caracteres.
unsigned long int	ft_strlen(char *s)
{
    unsigned long int	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

// Busca la primera aparición de un carácter en una cadena.
char	*ft_strchr(char *save, int character)
{
    unsigned long int	i;

    i = 0;
    while (save[i] != character && save[i] != '\0')
        i++;
    if (save[i] == character)
        return (&save[i]);
    return (NULL);
}

// Establece los primeros n bytes del área de memoria apuntada por str a cero.
void	ft_bzero(void *str, unsigned long int n)
{
    char				*s;
    unsigned long int	i;

    s = (char *)str;
    i = 0;
    while (i < n)
        s[i++] = '\0';
}

// Asigna memoria para una matriz de elementos, inicializa a cero y devuelve un puntero a la memoria asignada.
void	*ft_calloc(unsigned long int size, unsigned long int c)
{
    char	*result;

    result = malloc(size * c);
    if (!result)
        return (NULL);
    ft_bzero(result, (size * c));
    return (result);
}
