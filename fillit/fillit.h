/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:13:10 by gbellege          #+#    #+#             */
/*   Updated: 2019/05/16 13:09:22 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct			s_tetra
{
	int					num;
	int					x[4];
	int					y[4];
	char				letter;
	struct s_tetra		*next;
}						t_tetra;

typedef struct			s_map
{
	short int			tetra_qt;
	short int			map_size;
}						t_map;

char					**draw_map(char **map, short int size);
short int				set_min_size(short int tetra_qt);
void					get_solution(t_tetra *tetramino, t_map *map_op);
t_tetra					*ft_read_tetraminos(int fd, t_tetra *tetramino);
int						ft_check_block(char *buffer, int ret);
int						ft_check_figure(char *buffer);
t_tetra					*ft_newtetra(char *buf, char let, t_tetra *tetramino);
t_tetra					*ft_newfigure(t_tetra **figure, t_tetra *tetramino);
void					ft_free_tetraminos(t_tetra *tetraminos);
void					ft_free_tetraminos_fin(t_tetra *tetraminos);
void					finish(void);
char					**fillit(t_tetra *tetramino, t_map *map_op, char **map);
void					check_open(int fd);
void					check_close(int fd);
t_map					*ft_create_map_option(t_tetra **tetramino);
t_tetra					*ft_create_tetra(t_tetra *tetramino, char *buffer);
void					ft_freearray(char **array);
void					ft_free_tetraminos_fin(t_tetra *tetraminos);

#endif
