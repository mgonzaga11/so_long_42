/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:28:14 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 20:08:00 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_imagens(t_matrix *var)
{
	if (var->floor == NULL)
		return (WRONG);
	if (var->wall == NULL)
		return (WRONG);
	if (var->player == NULL)
		return (WRONG);
	if (var->colet == NULL)
		return (WRONG);
	if (var->exit == NULL)
		return (WRONG);
	return (RIGHT);
}

void	printmap(t_matrix *var)
{
	int	cols;
	int	line;

	cols = 0;
	while (var->matrix_malloc[cols] != NULL)
	{
		line = 0;
		while (var->matrix_malloc[cols][line] != '\0')
		{
			put_image(var, line, cols);
			line++;
		}
		cols++;
	}
}

void	put_image(t_matrix *var, int line, int cols)
{
	if (var->matrix_malloc[cols][line] == '1')
		mlx_put_image_to_window (var->mlx, var->mlx_win, var->wall,
			line * PIXEL, cols * PIXEL);
	if (var->matrix_malloc[cols][line] == '0')
		mlx_put_image_to_window (var->mlx, var->mlx_win, var->floor,
			line * PIXEL, cols * PIXEL);
	if (var->matrix_malloc[cols][line] == 'P')
		mlx_put_image_to_window (var->mlx, var->mlx_win, var->player,
			line * PIXEL, cols * PIXEL);
	if (var->matrix_malloc[cols][line] == 'C')
		mlx_put_image_to_window (var->mlx, var->mlx_win, var->colet,
			line * PIXEL, cols * PIXEL);
	if (var->matrix_malloc[cols][line] == 'E')
		mlx_put_image_to_window (var->mlx, var->mlx_win, var->exit,
			line * PIXEL, cols * PIXEL);
}

int	put_files(t_matrix *var)
{
	int	line;
	int	cols;

	line = 0;
	cols = 0;
	var->mlx = mlx_init();
	if (var->mlx == NULL)
		return (print_error(ERROR_9));
	var->mlx_win = mlx_new_window(var->mlx, var->numberline * PIXEL,
			var->count_cols * PIXEL, "so_long_game");
	if (var->mlx_win == NULL)
		return (print_error(ERROR_11));
	var->floor = mlx_xpm_file_to_image(var->mlx, FLOOR, &line, &cols);
	var->wall = mlx_xpm_file_to_image(var->mlx, WALL, &line, &cols);
	var->player = mlx_xpm_file_to_image(var->mlx, PLAYER, &line, &cols);
	var->colet = mlx_xpm_file_to_image(var->mlx, COLET, &line, &cols);
	var->exit = mlx_xpm_file_to_image(var->mlx, EXIT, &line, &cols);
	if (check_imagens(var) == WRONG)
	{
		print_error(ERROR_10);
		ft_close(var);
	}
	mlx_hook(var->mlx_win, 2, 1L << 0, playrum, var);
	mlx_hook(var->mlx_win, 17, 0L, close_win, var);
	return (RIGHT);
}
