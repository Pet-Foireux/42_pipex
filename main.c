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

#include "pipex.h"

static void	handle_error(char **all_cmd, char **all_path, char *path, char *msg)
{
	perror(msg);
	ft_free_tab(all_cmd);
	ft_free_tab(all_path);
	free(path);
	exit(EXIT_FAILURE);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**all_cmd;
	char	*path;
	char	**all_path;

	if (!cmd || *cmd == '\0')
		handle_error(NULL, NULL, NULL, "Error");
	all_cmd = ft_split(cmd, ' ');
	all_path = get_all_path(env);
	path = get_cmd_path(all_path, cmd);
	if (path == NULL)
		handle_error(all_cmd, all_path, path, "Error");
	if (execve(path, all_cmd, env) == -1)
		handle_error(all_cmd, all_path, path, "Error");
	ft_free_tab(all_cmd);
	ft_free_tab(all_path);
	free(path);
}

void	child(char **argv, int pipefd[2], char **env)
{
	int	fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nInfile");
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec_cmd(argv[2], env);
	exit(EXIT_FAILURE);
}

void	parent(char **argv, int pipefd[2], char **env)
{
	int		fd;

	close(pipefd[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error\nOutfile");
		close(pipefd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	exec_cmd(argv[3], env);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	if (argc != 5)
		return (perror("Error\n"), 0);
	if (pipe(pipefd) == -1)
		return (perror("Error\npipe"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("Error\nfork"), 1);
	if (pid == 0)
		child(argv, pipefd, env);
	else
	{
		waitpid(pid, &status, 0);
		parent(argv, pipefd, env);
	}
	return (0);
}
