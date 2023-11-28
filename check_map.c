/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:11:15 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 19:21:16 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sizemap(t_matrix *var)
{
	int		cols;
	int		line;

	cols = 0;
	while (cols < var->count_cols)
	{
		line = 0;
		while (var->matrix_malloc[cols][line] != '\0')
		{
			if (var->matrix_malloc[cols][line] == '\n'
				|| var->matrix_malloc[cols][line] == '\r')
				var->matrix_malloc[cols][line] = '\0';
			line++;
		}
		cols++;
	}
	cols = 0;
	var->numberline = ft_strlen(var->matrix_malloc[cols]);
	while (cols < var->count_cols)
	{
		if (ft_strlen (var->matrix_malloc[cols]) != var->numberline)
			return (WRONG);
		cols++;
	}
	return (RIGHT);
}

int	check_wall(t_matrix *var)
{
	int	cols;
	int	line;

	cols = 0;
	line = 0;
	while (var->matrix_malloc[cols][line] != '\0')
		if (var->matrix_malloc[cols][line++] != '1')
			return (WRONG);
	line--;
	while (cols < var->count_cols)
		if (var->matrix_malloc[cols++][line] != '1')
			return (WRONG);
	cols--;
	while (cols >= 0)
	{
		if (var->matrix_malloc[cols][line] != '1')
			return (WRONG);
		while (line >= 0)
			if (var->matrix_malloc[cols][line--] != '1')
				return (WRONG);
		line++;
		cols--;
	}
	return (RIGHT);
}

int	char_strange(t_matrix *var)
{
	int	line;
	int	cols;

	line = 0;
	cols = 0;
	while (var->matrix_malloc[cols] != NULL)
	{
		while (var->matrix_malloc[cols][line] != '\0')
		{
			if (var->matrix_malloc[cols][line] != '1'
				&& var->matrix_malloc[cols][line] != '0'
				&& var->matrix_malloc[cols][line] != 'E'
				&& var->matrix_malloc[cols][line] != 'P'
				&& var->matrix_malloc[cols][line] != 'C'
				&& var->matrix_malloc[cols][line] != '\n'
				&& var->matrix_malloc[cols][line] != '\r')
				return (WRONG);
			line++;
		}
		line = 0;
		cols++;
	}
	return (RIGHT);
}

int	check_elements(t_matrix *var)
{
	int	player_count;
	int	line;
	int	cols;
	int	exit_count;

	player_count = 0;
	cols = -1;
	exit_count = 0;
	while (var->matrix_malloc[++cols] != NULL)
	{
		line = 0;
		while (var->matrix_malloc[cols][line] != '\0')
		{
			if (var->matrix_malloc[cols][line] == 'P')
				player_count++;
			if (var->matrix_malloc[cols][line] == 'C')
				var->colet_count++;
			if (var->matrix_malloc[cols][line] == 'E')
				exit_count++;
			line++;
		}
	}
	if (player_count == 1 && var->colet_count > 0 && exit_count == 1)
		return (RIGHT);
	return (WRONG);
}
