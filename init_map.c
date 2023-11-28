/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:07:23 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 19:45:15 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	namemap( char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i >= 4)
		i = i - 4;
	if (filename[i] == '.')
		i++;
	else
		return (WRONG);
	if (filename[i] == 'b')
		i++;
	else
		return (WRONG);
	if (filename[i] == 'e')
		i++;
	else
		return (WRONG);
	if (filename[i] == 'r')
		i++;
	else
		return (WRONG);
	return (RIGHT);
}

int	check_thing(t_matrix *var)
{
	char	**clone_matrix;

	if (char_strange(var) == 0)
		return (print_error(ERROR_7));
	if (sizemap(var) == 0)
		return (print_error(ERROR_3));
	if (check_wall(var) == 0)
		return (print_error(ERROR_4));
	if (check_elements(var) == 0)
		return (print_error(ERROR_6));
	clone_matrix = clonematrix(var);
	if (clone_matrix == NULL)
		return (print_error(ERROR_12));
	flood_fill(clone_matrix, get_player_position(var));
	if (check_matrix(clone_matrix) == 0)
		return (print_error(ERROR_5));
	return (RIGHT);
}

void	flood_fill(char **clone_matrix, t_player player)
{
	if (clone_matrix[player.cols][player.line] == '1' ||
	clone_matrix[player.cols][player.line] == 'S' ||
	clone_matrix[player.cols][player.line] == 'x')
		return ;
	if (clone_matrix[player.cols][player.line] == 'E')
	{
		clone_matrix[player.cols][player.line] = 'S';
		return ;
	}
	clone_matrix[player.cols][player.line] = 'x';
	flood_fill(clone_matrix, (t_player){player.cols + 1, player.line});
	flood_fill(clone_matrix, (t_player){player.cols - 1, player.line});
	flood_fill(clone_matrix, (t_player){player.cols, player.line + 1});
	flood_fill(clone_matrix, (t_player){player.cols, player.line - 1});
}

int	check_matrix(char **clone_matrix)
{
	int	colet_count;
	int	line;
	int	cols;
	int	exit_count;

	colet_count = 0;
	cols = 0;
	exit_count = 0;
	while (clone_matrix[cols] != NULL)
	{
		line = 0;
		while (clone_matrix[cols][line] != '\0')
		{
			if (clone_matrix[cols][line] == 'C')
				colet_count++;
			if (clone_matrix[cols][line] == 'E')
				exit_count++;
			line++;
		}
		cols++;
	}
	ft_free_matrix(clone_matrix);
	if (colet_count == 0 && exit_count == 0)
		return (RIGHT);
	return (WRONG);
}

t_player	get_player_position(t_matrix *var)
{
	t_player	player;

	player.cols = 0;
	while (var->matrix_malloc[player.cols] != NULL)
	{
		player.line = 0;
		while (var->matrix_malloc[player.cols][player.line] != '\0')
		{
			if (var->matrix_malloc[player.cols][player.line] == 'P')
				break ;
			player.line++;
		}
		if (var->matrix_malloc[player.cols][player.line] == 'P')
			break ;
		player.cols++;
	}
	return (player);
}
