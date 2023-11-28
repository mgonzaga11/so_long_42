/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:06:44 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 19:08:33 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			line;
	int			cols;
	t_matrix	var;

	line = 0;
	cols = 0;
	var = (t_matrix){0};
	if (argc != 2)
		return (print_error(ERROR_0));
	if (namemap(argv[1]) != 1)
		return (print_error(ERROR_1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(ERROR_2));
	var.count_cols = countcols(fd);
	var.matrix_malloc = makematrix(argv, fd, &var);
	if (check_thing(&var) == WRONG)
		return (ft_close(&var));
	if (put_files(&var) != RIGHT)
		return (ft_close(&var));
	printmap(&var);
	mlx_loop(var.mlx);
}
