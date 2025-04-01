/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:32:22 by lpatin            #+#    #+#             */
/*   Updated: 2025/04/02 00:01:47 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd[0] != pipex->path)
		free(pipex->path);
	if (pipex->cmd)
		free_split(pipex->cmd);
}

void	pipex_fork1(t_pipex *pipex, int pid)
{
	if (pid == 1)
	{
		if (pipex->infile == -1)
		{
			free_all(pipex);
			return ;
		}
		pipex->pid_1 = fork();
		if (pipex->pid_1 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_1 == 0)
			exec_fork1(pipex);
		free_all(pipex);
	}
}

void	pipex_fork2(t_pipex *pipex, int pid)
{
	if (pid == 2)
	{
		if (pipex->outfile == -1)
		{
			free_all(pipex);
			return ;
		}
		pipex->pid_2 = fork();
		if (pipex->pid_2 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_2 == 0)
			exec_fork2(pipex);
		free_all(pipex);
	}
}
