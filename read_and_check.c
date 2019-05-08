#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

// являются ли полученные символы в строках корректными фигурами
int     ft_check_figure(char *buffer)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
// подсчет в цикле количества соседних слева, справа, сверху и снизу символов '#'
    while (i <= 19)
    {
        if (buffer[i] == '#')
        {
            if (buffer[i + 1] == '#' && (i + 1) <= 19)
                count++;
            if (buffer[i - 1] == '#' && (i - 1) >= 0)
                count++;
            if (buffer[i + 5] == '#' && (i + 5) <= 19)
                count++;
            if (buffer[i - 5] == '#' && (i - 5) >= 0)
                count++;
        }
        i++;
    }
    if (count != 6 || count != 8)
        return (0);
    return (1);
}

// проверка символов и расположения \n'ов
int     ft_check_block(char *buffer, int ret)
{
    int     i;
    int     count;
    int     newline;
    
    i = 0;
    count = 0;
    while (i <= 19)
    {
// все символы кроме последних в строке(4го, 9го, 14го и 19го) - '.' или '#'
        if ((buffer[i] == '#' || buffer[i] == '.') && i % 5 < 4)
        {
            if (buffer[i] == '#')
                count++;
            if (count > 4)
                return (0);
            i++;
        }
        else if (buffer[i] == '\n')
            i++;
        else
            return (0);
    }
// проверка последнего \n'а
    if (ret > 20 && buffer[i] != '\n')
        return (0);
// проверка корректного расположения символов относительно друг друга
    if (!(ft_check_figure(buffer))
        return (0);
    return (1);
}

// чтение из файла
t_list  *ft_read_tetraminos(fd)
{
    t_list      *figures;
    int         ret;
    char        letter;
    char        *bufer;
    t_tetras    *tetramino;

    if (!(buffer = (char *)malloc(sizeof(char) * 21)))
        return (NULL);
    letter = 'A';
// читаем в буфер по одному блоку (все - по 21 символу, кроме последнего)
// в последнем - 20, т.к после него нет \n
    while ((ret = (read(fd, buffer, 21) >= 20)
    {
// отправляем прочитанное на проверку, создаем новый элемент для списка типа тетрас (прочитанная фигура)
        if (ft_check_block(buffer, ret) && tetramino = ft_newtetra(buffer, letter))
        {
// добавляем новую фигуру в связный список в порядке получения 
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