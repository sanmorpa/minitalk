/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:08:13 by samoreno          #+#    #+#             */
/*   Updated: 2021/12/15 09:08:13 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill(unsigned int decimal, char *in_hex);
static char	*ft_reverse(char *str);

char	*ft_tohex(unsigned int decimal)
{
	int				size;
	unsigned int	copy;
	char			*in_hex;

	size = 0;
	copy = decimal;
	while (copy % 10 != 0 || copy / 10 != 0)
	{
		size++;
		copy /= 10;
	}
	if (decimal == 0)
		in_hex = malloc(sizeof(char) * 2);
	else
		in_hex = malloc(sizeof(char) * (size + 1));
	if (!in_hex)
		return (NULL);
	ft_fill(decimal, in_hex);
	return (ft_reverse(in_hex));
}

static void	ft_fill(unsigned int decimal, char *in_hex)
{
	int	iter;

	iter = 0;
	if (decimal == 0)
	{
		in_hex[iter] = '0';
		iter++;
	}
	else
	{
		while (decimal % 16 != 0 || decimal / 16 != 0)
		{
			if (decimal % 16 < 10)
				in_hex[iter] = (decimal % 16) + '0';
			else
				in_hex[iter] = (decimal % 16) + 87;
			decimal /= 16;
			iter++;
		}
	}
	in_hex[iter] = 0;
}

static char	*ft_reverse(char *str)
{
	int		iter_rev;
	int		iter_str;
	char	*reversed;

	iter_rev = 0;
	reversed = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!reversed)
		return (NULL);
	iter_str = (ft_strlen(str) - 1);
	while (iter_str >= 0)
	{
		reversed[iter_rev] = str[iter_str];
		iter_rev++;
		iter_str--;
	}
	reversed[iter_rev] = 0;
	free(str);
	return (reversed);
}
