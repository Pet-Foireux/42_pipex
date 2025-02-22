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
	ft_putendl_fd(msg, STDERR_FILENO);
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
		handle_error(NULL, NULL, NULL, "Error : argument invalide");
	all_cmd = ft_split(cmd, ' ');
	all_path = get_all_path(env);
	if (access(all_cmd[0], X_OK) == 0)
	{
		if (execve(all_cmd[0], all_cmd, env) == -1)
			handle_error(all_cmd, all_path, NULL, "Error : impossible d'exec");
	}
	else
	{
		path = get_cmd_path(all_path, cmd);
		if (path == NULL)
			handle_error(all_cmd, all_path, path, "Error : path non trouver");
		if (execve(path, all_cmd, env) == -1)
			handle_error(all_cmd, all_path, path, "Error : impossible d'exec");
		free(path);
	}
	ft_free_tab(all_cmd);
	ft_free_tab(all_path);
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
		return (ft_printf("./pipex infile cmd1 cmd2 outfile\n"));
	if (pipe(pipefd) == -1)
		return (perror("Error\npipe\n"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("Error\nfork\n"), 1);
	if (pid == 0)
		child(argv, pipefd, env);
	else
	{
		parent(argv, pipefd, env);
		waitpid(pid, &status, 0);
	}
	return (0);
}
