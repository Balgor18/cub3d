/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:02:25 by fcatinau          #+#    #+#             */
/*   Updated: 2022/03/21 09:31:51 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "mlx.h"
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

/*
**--------------struct--------------
*/
typedef struct s_tmp	t_tmp;
typedef struct s_mlx	t_mlx;

struct s_tmp
{
	char	*line;
	t_tmp	*next;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
};

/*
**----------------------------------
**----------------MLX---------------
**----------------------------------
*/
void	start_mlx(t_tmp *file);
#endif
