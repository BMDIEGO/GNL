#include "get_next_line.h"

char	*ft_free_strjoin(char *save, char *tmp)
{
    char	*new;

    new = ft_strjoin(save, tmp);
    free(save);
    return (new);
}

char	*the_rest(char *save)
{
    int		i;
    int		n;
    char	*new_save;

    i = 0;
    while (save[i] != '\0' && save[i] != '\n')
        i++;
    if (save[i] == '\0')
    {
        free(save);
        return (NULL);
    }
    new_save = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
    i++;
    n = 0;
    while (save[i] != '\0')
        new_save[n++] = save[i++];
    new_save[n] = '\0';
    free(save);
    return (new_save);
}

char	*make_line_from(char *save)
{
    int		i;
    char	*line;

    i = 0;
    if (save[i] == '\0')
        return (NULL);
    while (save[i] != '\0' && save[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    i = 0;
    while (save[i] != '\0' && save[i] != '\n')
    {
        line[i] = save[i];
        i++;
    }
    if (save[i] == '\n')
        line[i] = '\n';
    line[i + 1] = '\0';
    return (line);
}

char	*read_until_enter(int fd, char *save)
{
    int		n_of_chars;
    char	*tmp;

    if (!save)
        save = (char *)malloc(1);
    tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    n_of_chars = 1;
    while (n_of_chars > 0)
    {
        n_of_chars = read(fd, tmp, BUFFER_SIZE);
        if (n_of_chars == -1)
        {
            free(tmp);
            free(save);
            return (NULL);
        }
        tmp[n_of_chars] = '\0';
        save = ft_free_strjoin(save, tmp);
        if (ft_strchr(save, '\n'))
            break ;
    }
    free(tmp);
    return (save);
}

char	*get_next_line(int fd)
{
    char		*line;
    static char	*save;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    save = read_until_enter(fd, save);
    if (save == NULL)
        return (NULL);
    line = make_line_from(save);
    save = the_rest(save);
    return (line);
}