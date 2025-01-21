/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   besoin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:37:29 by mpapin            #+#    #+#             */
/*   Updated: 2025/01/21 06:36:06 by mpapin           ###   ########.fr       */
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
		return (ft_printf("Error\nPATH pas recupere/trouve"), NULL);
	all_path = ft_split(path_env, ':');
	if (!all_path)
		return (ft_printf("Error\nEchec split"), NULL);
	return (all_path);
}

char	*get_cmd_path(char **all_path, char *cmd)
{
	char	**all_cmd;
	char	*cmd_path;
	char	*cmd_no_path;
	int		i;

	i = 0;
	all_cmd = ft_split(cmd, ' ');
	if (!all_cmd)
		return (ft_printf("Error\nEchec split"), NULL);
	while (all_path[i])
	{
		cmd_no_path = ft_strjoin(all_path[i], "/");
		cmd_path = ft_strjoin(cmd_path, all_cmd[0]);
		free(cmd_no_path);
		if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) == 0)
		{
			free(cmd_path);
			return (cmd_path);
		}
		i++;
	}
	return (ft_printf("Error\nCmd pas trouver..."), NULL);
}
