/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:33:45 by bvaujour          #+#    #+#             */
/*   Updated: 2023/09/15 01:25:21 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

static int	pass_out(t_data *data, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == '>')
		i++;
	while (cmd[i] == ' ')
		i++;
	while ((cmd[i] && cmd[i] != ' ' && cmd[i] != '<' && cmd[i] != '>')
		|| (is_lit(data) || data->par))
	{
		edit_lit(data, cmd[i]);
		edit_par(data, cmd[i]);
		i++;
	}
	return (i);
}

static int	count_out(t_data *data, char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		edit_lit(data, cmd[i]);
		edit_par(data, cmd[i]);
		if (cmd[i] == '>' && !is_lit(data) && !data->par)
		{
			i += pass_out(data, cmd + i);
			count++;
		}
		else
			i++;
	}
	return (count);
}

static int	out_size(t_data *data, char *clone)
{
	int	i;

	i = 0;
	while (clone[i] == '>')
		i++;
	while (clone[i] == ' ')
		i++;
	while ((clone[i] && clone[i] != ' ' && clone[i] != '<' && clone[i] != '>')
		|| (is_lit(data) || data->par))
	{
		edit_lit(data, clone[i]);
		edit_par(data, clone[i]);
		i++;
	}
	return (i);
}

static void	get_out(t_data *data, char *cmd, char **out)
{
	int		i;
	int		j;
	char	*clone;

	clone = cmd;
	j = 0;
	while (*clone)
	{
		i = 0;
		edit_lit(data, clone[i]);
		edit_par(data, clone[i]);
		if (clone[i] == '>' && !is_lit(data) && !data->par)
		{
			i += out_size(data, clone);
			out[j] = ft_strndup(clone, i, 0);
			remove_str(clone, out[j]);
			if (!out[j])
				end(data);
			j++;
		}
		else
			clone++;
	}
	out[j] = 0;
}

void	fill_out(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (i < data->count)
	{
		len = count_out(data, data->cmds[i].cmd) + 1;
		data->cmds[i].out = malloc(sizeof(char *) * len);
		if (!data->cmds[i].out)
			exit(666); //revoir
		get_out(data, data->cmds[i].cmd, data->cmds[i].out);
		i++;
	}
}
