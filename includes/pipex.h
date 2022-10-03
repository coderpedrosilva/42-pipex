/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:19:29 by progerio          #+#    #+#             */
/*   Updated: 2022/10/01 16:03:14 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/*
 unistd.h - is the name of the header file that provides 
 access to the POSIX operating system API. 
*/
# include <unistd.h>

/*
The sys/types.h header file defines a collection of typedef 
symbols and structures.
*/
# include <sys/types.h>

/*
The sys/uio.h header file contains definitions for vector 
I/O operations
*/
# include <sys/uio.h>

/*
Stdlib.h - it has functions involving memory allocation, 
process control, conversions and others.
*/
# include <stdlib.h>

/*
fcntl.h - header shall define the following requests 
and arguments for use by the functions fcntl() and open().
*/
# include <fcntl.h>

/*
The sys/wait.h header file declares the functions like  
wait() and waitpid(), used for holding processes.
*/
# include <sys/wait.h>

/*
string.h - it is a header file that provides C programming 
language standard library functions, macros, and definitions 
for manipulating strings and memory regions.
*/
# include <string.h>

/*
stdio.h - its name comes from the English expression standard 
input-output header, which means "standard input/output header".
*/
# include <stdio.h>

# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_PIPE "Pipe"
# define ERROR_CMD "Command not found\n"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	char	*cmd;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
}t_pipex;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	message_error(char *err);
int		message(char *err);

void	initial_process_free(t_pipex *pipex);
void	process_free(t_pipex *pipex);

void	process_one(t_pipex pipex, char *argv[], char *envp[]);
void	process_two(t_pipex pipex, char *argv[], char *envp[]);

#endif
