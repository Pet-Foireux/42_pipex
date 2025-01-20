/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:00:03 by mpapin            #+#    #+#             */
/*   Updated: 2025/01/19 21:00:03 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **get_path(char **env)
{
    int i;
    char *path_env;
    char **all_path;

    path_env = NULL;
    all_path = NULL;
    i = 0;
    while(env[i])
    {
        if (ft_strnstr(env[i], "PATH=", 5))
            path_env = env[i] + 5;
        i++;
    }
    if (!path_env)
        printf("Error\nPATH pas recupere/trouve");
    all_path = ft_split(path_env, ':');
    if (!all_path)
        printf("Error\nsplit a fail");
    return(all_path);
}

void    get_cmd_path(char **all_path, char *cmd)
{
    char **all_cmd;
    char *cmd_path;
    int i;

    i = 0;
    all_cmd = ft_split(cmd, ' ');
    while(all_path[i])
    {
        cmd_path = ft_strjoin(all_path[i], "/");
        cmd_path = ft_strjoin(cmd_path, all_cmd[0]);
        if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) == 0)
        {
            printf("TROUVER");
            return ;
        }
        i++;
    }
}

int main(int argc, char **argv, char **env)
{
    if (argc != 5)
        return(1);
    get_cmd_path(get_path(env), argv[2]);
}