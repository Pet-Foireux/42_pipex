/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   besoin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:37:29 by mpapin            #+#    #+#             */
/*   Updated: 2025/02/23 13:59:03 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

char	**get_all_path(char **env)
{
	int		i;
	char	*path_env;
	char	**all_path;

	path_env = NULL;
	all_path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			path_env = env[i] + 5;
		i++;
	}
	if (!path_env)
		return (NULL);
	all_path = ft_split(path_env, ':');
	return (all_path);
}

char	*build_cmd_path(char *path, char *cmd)
{
	char	*cmd_no_path;
	char	*cmd_path;

	cmd_no_path = ft_strjoin(path, "/");
	if (!cmd_no_path)
		return (NULL);
	cmd_path = ft_strjoin(cmd_no_path, cmd);
	free(cmd_no_path);
	return (cmd_path);
}

char	*try_cmd_path(char **all_cmd, char **all_path)
{
	char	*cmd_path;
	int		i;

	i = -1;
	while (all_path[++i])
	{
		cmd_path = build_cmd_path(all_path[i], all_cmd[0]);
		if (cmd_path && access(cmd_path, F_OK) == 0
			&& access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

char	*get_cmd_path(char **all_path, char *cmd)
{
	char	**all_cmd;
	char	*cmd_path;

	if (!cmd || *cmd == '\0')
		return (NULL);
	all_cmd = ft_split(cmd, ' ');
	if (!all_cmd)
		return (NULL);
	if (all_path)
		cmd_path = try_cmd_path(all_cmd, all_path);
	else
		cmd_path = NULL;
	ft_free_tab(all_cmd);
	return (cmd_path);
}
