/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:19:29 by progerio          #+#    #+#             */
/*   Updated: 2022/10/01 16:06:36 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	message(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	message_error(char *error)
{
	perror(error);
	exit (1);
}
