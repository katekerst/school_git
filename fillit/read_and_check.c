/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:06:28 by siolive           #+#    #+#             */
/*   Updated: 2019/05/09 15:13:19 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

t_list		*ft_newfigure(t_list **figure, t_tetras *tetramino)
{
	t_list	*begin;
// для первой фигуры (в случае, если список пустой)
	if (!*figure)
		begin = ft_lstnew(tetramino, sizeof(t_tetras));
// для остальных случаев - доходим до последнего элемента и добавляем новый
	else
	{
		begin = *figure;
		while (*figure->next)
			*figure = *figure->next;
		figure->next = ft_lstnew(tetramino, sizeof(t_tetras));
	}
	return (begin);
}

t_tetras	*ft_newtetra(char *buffer, char let)
{
	t_tetras	*tetramino;
	int			i;
	int			j;
	int			k;
	int			count;

	i = 0;
	j = 0;
	count = 0;
	tetramino = (t_tetras *)malloc(sizeof(t_tetras));
// сохраняем букву в элемент структуры 
	tetramino->letter = let;
// находим первый квадрат тетрамино
	while (buffer[i] != '#')
		i++;
// запоминаем индекс первого символа '#'       
	k = i;
// проходим всю строку и ищем в ней следующие квадраты    
	while (++i <= 18)
	{
		if (buffer[i] == '#')
		{
// координата x - это разница между текущим индексом и индексом первого квадрата - количество строк (в которой 5 элементов)
			tetramino->x[++j] = i - count - k;
// координата y - это разница между строками (номер строки, на которой находимся определяется делением на 5)
			tetramino->y[j] = i / 5 - k / 5;
		}
// для определения количества строк в дальнейшем при переходе на следующую строку прибавляем к переменной по 5        
		if (buffer[i] == '\n')
			count += 5;
	}
	return (tetramino);
}

// являются ли полученные символы в строках корректными фигурами
int			ft_check_figure(char *buffer)
{
	int			i;
	int			count;

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
int			ft_check_block(char *buffer, int ret)
{
	int			i;
	int			count;
	int			newline;

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
	if (!(ft_check_figure(buffer)))
		return (0);
	return (1);
}

// чтение из файла
t_list		*ft_read_tetraminos(int fd)
{
	t_list		*figures;
	int			ret;
	char		letter;
	char		buffer[21];
	t_tetras	*tetramino;

	letter = 'A';
// читаем в буфер по одному блоку (все - по 21 символу, кроме последнего)
// в последнем - 20, т.к после него нет \n
	while ((ret = (read(fd, buffer, 21) >= 20)))
	{
// отправляем прочитанное на проверку, создаем новый элемент для списка типа тетрас (прочитанная фигура)
		if ((ft_check_block(buffer, ret)) && (tetramino = ft_newtetra(buffer, letter)))
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
