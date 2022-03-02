/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:07:42 by samoreno          #+#    #+#             */
/*   Updated: 2021/12/15 09:07:42 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char *str, char c);
static int	ft_special(const char *str, va_list arg, int it);

int	ft_printf(const char *str, ...)
{
	int		iter;
	int		printed;
	va_list	args;

	va_start(args, str);
	iter = 0;
	printed = 0;
	while (str[iter])
	{
		if (str[iter] != '%')
		{
			ft_putchar_fd(str[iter], 1);
			printed++;
		}
		else
		{
			printed += ft_special(str, args, (iter + 1));
			iter++;
		}
		iter++;
	}
	va_end(args);
	return (printed);
}

static int	ft_special(const char *str, va_list arg, int it)
{
	int		count;
	char	*to_print;

	count = 0;
	to_print = ft_check(str[it], arg);
	if (to_print)
		count += ft_print(to_print, str[it]);
	else
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	return (count);
}

static int	ft_print(char *str, char c)
{
	int	count;

	count = 0;
	if (c == 'c' && str[count] == 0)
	{
		ft_putchar_fd(str[count], 1);
		count++;
	}
	while (str[count])
	{
		ft_putchar_fd(str[count], 1);
		count++;
	}
	free(str);
	return (count);
}
