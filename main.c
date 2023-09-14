/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:30:21 by bvaujour          #+#    #+#             */
/*   Updated: 2023/09/14 19:15:20 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minishell.h"

int	g_last_ret;

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int	pid;

	data.argc = argc;
	if (argc == 1)
		header();
	init(&data, argv, env);
	process(&data);
	return (0);
}
