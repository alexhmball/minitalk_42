/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:26:08 by aball             #+#    #+#             */
/*   Updated: 2022/04/18 21:45:20 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_client
{
	int		num[7];
	int		index;
	char	*str;
}		t_client;

#endif