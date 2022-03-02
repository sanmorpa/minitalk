/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:03:26 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/31 11:58:13 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_mini
{
	int		iter;
	char	ch;
	int		len_flag;
	int		len;
	int		iter_str;
	char	*str;
}	t_mini;

#endif