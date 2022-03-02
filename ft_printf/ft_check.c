/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:07:37 by samoreno          #+#    #+#             */
/*   Updated: 2021/12/20 14:02:57 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_check_diux(char c, va_list args)
{
	char		*str;
	long long	numb;

	if (c == 'd' || c == 'i')
	{
		numb = va_arg(args, int);
		str = ft_itoa(numb);
	}
	if (c == 'u')
	{
		numb = va_arg(args, int);
		str = ft_itoa((unsigned)numb);
	}
	if (c == 'x' || c == 'X')
	{
		numb = va_arg(args, int);
		str = ft_tohex(numb);
		if (c == 'X' && str)
			ft_toupper(str);
	}
	return (str);
}

static char	*ft_check_cper(char c, va_list args)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (str)
	{
		if (c == 'c')
			str[0] = va_arg(args, int);
		if (c == '%')
			str[0] = '%';
		str[1] = 0;
	}
	return (str);
}

static char	*ft_check_ps(char c, va_list args)
{
	char	*str;
	char	*temp;
	void	*ptr_v;

	if (c == 'p')
	{
		ptr_v = va_arg(args, void *);
		str = ft_tohex_ptr((long long)ptr_v);
	}
	if (c == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
			return (NULL);
		str = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		ft_copy(str, temp);
	}
	return (str);
}

char	*ft_check(char c, va_list args)
{
	char	*str;

	if (c == 'c' || c == '%')
		str = ft_check_cper(c, args);
	if (c == 's' || c == 'p')
		str = ft_check_ps(c, args);
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		str = ft_check_diux(c, args);
	return (str);
}
