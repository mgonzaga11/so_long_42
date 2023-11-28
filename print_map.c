/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:19:29 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 19:58:30 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countcols(int fd)
{
	int		count;
	char	*string;

	count = 0;
	string = get_next_line(fd);
	if (string == NULL)
	{
		print_error(ERROR_8);
		exit(0);
	}
	while (string != NULL)
	{
		count++;
		free(string);
		string = get_next_line(fd);
	}
	return (count);
}

char	**makematrix(char **argv, int fd, t_matrix *var)
{
	char	**matriz_malloc;
	int		count;

	count = 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(print_error(ERROR_2));
	matriz_malloc = ft_calloc (var->count_cols + 1, sizeof(char *));
	if (matriz_malloc == NULL)
		exit(print_error(ERROR_12));
	while (count < var->count_cols)
	{
		matriz_malloc[count] = get_next_line(fd);
		count++;
	}
	return (matriz_malloc);
}

char	**clonematrix(t_matrix *var)
{
	int		line;
	int		cols;
	char	**clone;

	cols = -1;
	clone = ft_calloc((var->count_cols + 1), sizeof(char *));
	if (clone == NULL)
		ft_close(var);
	while (var->matrix_malloc[++cols] != NULL)
	{
		line = -1;
		clone[cols] = malloc((var->numberline + 1) * sizeof(char));
		if (clone[cols] == NULL)
		{
			ft_free_matrix(clone);
			ft_close(var);
		}
		while (var->matrix_malloc[cols][++line] != '\0')
			clone[cols][line] = var->matrix_malloc[cols][line];
		clone[cols][line] = '\0';
	}
	clone[cols] = NULL;
	return (clone);
}
