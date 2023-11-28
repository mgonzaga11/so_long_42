/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:25:54 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/10/16 16:53:59 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	playrum(int bot, t_matrix *x)
{
	static int	move;
	t_player	player;

	player = get_player_position(x);
	if (bot == XK_w || bot == XK_Up || bot == XK_W)
		if (moveplayer(player, x, player.cols - 1, player.line) == RIGHT)
			move++;
	if (bot == XK_a || bot == XK_Left || bot == XK_A)
		if (moveplayer(player, x, player.cols, player.line - 1) == RIGHT)
			move++;
	if (bot == XK_d || bot == XK_Right || bot == XK_D)
		if (moveplayer(player, x, player.cols, player.line + 1) == RIGHT)
			move++;
	if (bot == XK_s || bot == XK_Down || bot == XK_S)
		if (moveplayer(player, x, player.cols + 1, player.line) == RIGHT)
			move++;
	if (bot == 65307)
	{	
		ft_printf("Closing the window and stopping the game\n");
		ft_close(x);
	}
	ft_printf("Movements: %i\n", move);
	printmap(x);
	return (0);
}

int	moveplayer(t_player player, t_matrix *var, int newcols, int newline)
{
	if (var->matrix_malloc[newcols][newline] == 'E' && var->colet_count > 0)
		return (WRONG);
	if (var->matrix_malloc[newcols][newline] == '1')
		return (WRONG);
	if (var->matrix_malloc[newcols][newline] == 'C')
		var->colet_count--;
	if (var->matrix_malloc[newcols][newline] == 'E' && var->colet_count == 0)
	{
		ft_printf("Congratulations you are the best!!!\n");
		ft_close(var);
		exit(0);
	}
	var->matrix_malloc[player.cols][player.line] = '0';
	var->matrix_malloc[newcols][newline] = 'P';
	return (RIGHT);
}

int	close_win(t_matrix *var)
{
	ft_printf("Closing the window and stopping the game\n");
	ft_close(var);
	exit(0);
}

int	print_error(char *e)
{
	ft_printf("Error\n%s", e);
	return (WRONG);
}
