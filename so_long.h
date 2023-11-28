/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:37:37 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 19:55:04 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>

# define RIGHT 1
# define WRONG 0
# define PIXEL 64
# define COLET "textures/colet.xpm"
# define EXIT "textures/exit.xpm"
# define FLOOR "textures/floor.xpm"
# define PLAYER "textures/player.xpm"
# define WALL "textures/wall.xpm"
# define ERROR_0 "Invalid number of arguments\n"
# define ERROR_1 "Invalid extension\n"
# define ERROR_2 "Impossible to read the file\n"
# define ERROR_3 "Invalid map size\n"
# define ERROR_4 "Invalid wall\n"
# define ERROR_5 "Impossible to access elements\n"
# define ERROR_6 "Invalid number of elements\n"
# define ERROR_7 "Map contains invalid character\n"
# define ERROR_8 "Empty Map\n"
# define ERROR_9 "Mlx error\n"
# define ERROR_10 "Sprites error\n"
# define ERROR_11 "Window error\n"
# define ERROR_12 "Invalid malloc\n"

typedef struct s_matrix
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix_malloc;
	int		count_cols;
	void	*floor;
	void	*wall;
	void	*colet;
	void	*player;
	void	*exit;
	size_t	numberline;
	int		colet_count;
}t_matrix;

typedef struct s_player
{
	int	cols;
	int	line;
}t_player;

int			sizemap(t_matrix *var);
int			check_wall(t_matrix *var);
int			char_strange(t_matrix *var);
int			playrum(int bot, t_matrix *x);
int			namemap( char *filename);
int			countcols(int fd);
char		**makematrix(char **argv, int fd, t_matrix *var);
void		printmap(t_matrix *var);
int			check_elements(t_matrix *var);
int			check_thing(t_matrix *var);
int			close_win(t_matrix *s_libmlx);
char		**clonematrix(t_matrix *var);
void		flood_fill(char **clone_matrix, t_player player);
int			check_matrix(char **clone_matrix);
int			moveplayer(t_player player, t_matrix *var, int newlin, int newcol);
t_player	get_player_position(t_matrix *var);
void		put_image(t_matrix *var, int line, int cols);
int			print_error(char *e);
int			put_files(t_matrix *var);
int			check_imagens(t_matrix *var);
int			ft_close(t_matrix *var);
void		ft_free_matrix(char **matrix);
#endif 
