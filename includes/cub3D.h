/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/23 04:12:28 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "error.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
/*
 FONCTIONS AUTORISEES:
open, cose, read, write, printf, malloc, free, perror, strerror, exit
toutes les fonctions de math.h
*/

/*
**---------------Enum---------------
*/

enum	e_TYPE
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE
};

enum	e_INFOS
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
};

enum	e_MOVE
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

enum	e_TEXTURE
{
	FLOORTEX = 0,
	CEILINGTEX,
	NORTHTEX,
	SOUTHTEX,
	WESTTEXT,
	EASTTEX
};

enum	e_RGB
{
	RED_COLOR = 0,
	GREEN_COOR,
	BLUE_COLOR
};

/*
**--------------struct--------------
*/
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef struct s_list	t_list;
typedef struct s_mlx	t_mlx;

struct s_data
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_rgb	*floor;
	t_rgb	*ceiling;
	int		map_height;
	int		map_width;
	int		map_chars;
	void	*mlx;
	int		res_x;
	int		res_y;
};

struct s_rgb
{
	int		red;
	int		green;
	int		blue;
};

struct s_list
{
	char	*line;
	int		line_size;
	int		type;
	t_list	*next;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
};

// basic_parsing.c
void	parsing(int argc, char **arg, t_data **data);

// fill_list.c
void	fill_list(int fd, t_list **list);

// string_utils.c
int		ft_strlen(char *str);
int		is_cardinal_char(char c);
int		is_color_char(char c);
int		check_cardinal_syntax(char *str);
int		check_floor_ceiling_syntax(char *str);
int		set_line_type(char *str);

// string_utils2.c
char	*ft_strndup(char *str, int n);
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(char *str1, char *str2, unsigned int n);

// lst_utils.c
int		ft_lst_size(t_list *list);
t_list	*ft_lst_create(char *line);
void	ft_lst_clear(t_list **list);
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lst_addback(t_list **list, t_list *elem);

// free.c
void	clear_list_exit(t_list **list, char *msg);
void	clear_list_syntax_exit(t_list **list, int i, char *line, char *msg);
void	clear_list_free_line_exit(t_list **list, char *line);
void	free_map(char **map);
void	clear_data(t_data *data);

// print.c
void	exit_error(char *msg);
void	print_list(t_list *list);
void	print_data(t_data *data);

// main.c
void	check_open(char *filename, int *fd);
int		check_close(int fd, t_list *list);

#endif
