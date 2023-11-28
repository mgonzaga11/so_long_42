/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:56:47 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 20:01:30 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_close(t_matrix *var)
{
	if (var->mlx && var->mlx_win)
	{
		if (var->colet != NULL)
			mlx_destroy_image(var->mlx, var->colet);
		if (var->exit != NULL)
			mlx_destroy_image(var->mlx, var->exit);
		if (var->floor != NULL)
			mlx_destroy_image(var->mlx, var->floor);
		if (var->player != NULL)
			mlx_destroy_image(var->mlx, var->player);
		if (var->wall != NULL)
			mlx_destroy_image(var->mlx, var->wall);
		mlx_destroy_window (var->mlx, var->mlx_win);
		mlx_destroy_display(var->mlx);
	}
	ft_free_matrix(var->matrix_malloc);
	free(var->mlx);
	exit (0);
	return (0);
}
