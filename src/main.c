/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:33:28 by lpatin            #+#    #+#             */
/*   Updated: 2025/04/02 00:02:13 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	*init_struct(char **av, char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(1);
	pipex->infile = open(av[1], O_RDONLY, 0644);
	if (pipex->infile == -1)
		(perror("Infile"));
	pipex->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		(perror("Outfile"));
	pipex->env = env;
	pipex->path = NULL;
	return (pipex);
}

void	close_all(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
}

void	exec_fork1( t_pipex *pipex)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close_all(pipex);
	execve(pipex->path, pipex->cmd, pipex->env);
	if (pipex->path != pipex->cmd[0])
		free(pipex->path);
	free_split(pipex->cmd);
	free(pipex);
	perror("Execve fail");
	exit(1);
}

void	exec_fork2(t_pipex *pipex)
{
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close_all(pipex);
	execve(pipex->path, pipex->cmd, pipex->env);
	if (pipex->path != pipex->cmd[0])
		free(pipex->path);
	free_split(pipex->cmd);
	free(pipex);
	perror("Execve fail");
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac != 5)
		(ft_putstr_fd("Usage: <infile> <cmd1> <cmd2> <outfile>\n", 2), exit(1));
	pipex = init_struct(av, env);
	if (pipe(pipex->pipe_fd) == -1)
		(close(pipex->infile), close(pipex->outfile), free(pipex));
	create__check_path(pipex, av[2]);
	if (pipex->path)
		pipex_fork1(pipex, 1);
	create__check_path(pipex, av[3]);
	if (pipex->path)
		pipex_fork2(pipex, 2);
	return (close_all(pipex), wait(NULL), wait(NULL),
		free(pipex), 0);
}
