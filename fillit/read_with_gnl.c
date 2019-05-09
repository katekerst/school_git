#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

// являются ли полученные символы в строках корректными фигурами
int     ft_check_figure(char *buffer)
{
    int     i;
    int     count;

    i = 0;
    while (buffer[i])
    {
        count = 0;
        while (buffer[i] != '\n')
        {
            if (buffer[i] == '#')
            {
                if (buffer[i + 1] == '#')
                    count++;
                if (buffer[i - 1] == '#')
                    count++;
                if (buffer[i + 5] == '#')
                    count++;
                if (buffer[i - 5] == '#')
                    count++;
            }
            i++;
        }
        if (count != 6 || count != 8)
            return (0);
        else
            i++;
    }
    return (1);
}

// проверка символов и расположения \n'ов
int     ft_check_block(char *buffer)
{
    int     i;
    int     count;
    
    i = 0;
    count = 0;
    while (buffer[i])
    {
        if (buffer[i] == '#' || buffer[i] == '.')
        {
            if (buffer[i] == '#')
                count++;
            if (count > 4)
                return (0);
            i++;
        }
        else if (i % 17 == 16 && buffer[i] == '\n')
            i++;
        else
            return (0);
    }
    if (!(ft_check_figure(buffer)))
        return (0);
    return (1);
}

// чтение из файла
t_list  *ft_read_tetraminos(fd)
{
    t_list      *figures;
    t_tetras    *tetramino;
    char        letter;
    char        *buffer;
    char        *line;

    if (!(buffer = (char *)malloc(sizeof(char) * 21)))
        return (NULL);
    letter = 'A';
    while (get_next_line(fd, *line) >= 0)
    {
        if (!(*line))
            line = '\n';
        buffer = ft_strjoin(buffer, line);
        if ((ft_check_block(buffer)) && (tetramino = ft_newtetra(buffer, letter)))
        {
            ft_lstnew(tetramino, sizeof(t_tetras));
            ft_newfigure(&figures, tetramino);
        }
        else
        {
            free(buffer);
            free_figures(figures);
            return (NULL);
        }
        letter++;
    }
    free(buffer);
    return (figures);
}