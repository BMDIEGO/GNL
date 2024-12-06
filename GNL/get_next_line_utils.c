#include "get_next_line.h"

unsigned long int	ft_strlen(char *s)
{
    unsigned long int	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

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

void	ft_bzero(void *str, unsigned long int n)
{
    char				*s;
    unsigned long int	i;

    s = (char *)str;
    i = 0;
    while (i < n)
        s[i++] = '\0';
}

void	*ft_calloc(unsigned long int size, unsigned long int c)
{
    char	*result;

    result = malloc(size * c);
    if (!result)
        return (NULL);
    ft_bzero(result, (size * c));
    return (result);
}

char	*ft_strcat(char *s1, char *s2)
{
    char	*s;
    int		i;
    int		j;

    s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!s)
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        s[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        s[i] = s2[j];
        i++;
        j++;
    }
    s[i] = '\0';
    return (s);
}