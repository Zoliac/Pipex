/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:32:50 by lpatin            #+#    #+#             */
/*   Updated: 2025/04/02 00:03:24 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include "../src/libft/includes/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	char	*path;
	char	**cmd;
	char	**env;
}	t_pipex;

void	free_split(char **tab);
char	*find_cmd_path(char *cmd, char **env);
char	*create__check_path(t_pipex *pipex, char *cmd);
void	pipex_fork1(t_pipex *pipex, int pid);
void	pipex_fork2(t_pipex *pipex, int pid);
void	close_all(t_pipex *pipex);
void	exec_fork1( t_pipex *pipex);
void	exec_fork2(t_pipex *pipex);
