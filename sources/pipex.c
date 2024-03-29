/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:19:29 by progerio          #+#    #+#             */
/*   Updated: 2022/10/01 16:03:37 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (message(ERROR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		message_error(ERROR_INFILE);
	pipex.outfile = open(argv[argc -1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pipex.outfile < 0)
		message_error(ERROR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		message_error(ERROR_PIPE);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		process_one(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		process_two(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	initial_process_free(&pipex);
	return (0);
}
