/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:30:21 by bvaujour          #+#    #+#             */
/*   Updated: 2023/08/18 14:37:58 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minishell.h"

int	g_last_ret;

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	data.argc = argc;
	if (argc == 1)
		header();
	init(&data, argv, env);
	process(&data);
	return (0);
}
