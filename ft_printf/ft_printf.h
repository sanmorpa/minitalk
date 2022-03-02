/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:07:53 by samoreno          #+#    #+#             */
/*   Updated: 2021/12/15 09:07:53 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_itoa(long long n);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	ft_toupper(char *str);
void	ft_copy(char *dst, const char *src);
char	*ft_tohex(unsigned int decimal);
char	*ft_tohex_ptr(unsigned long decimal);
char	*ft_check(char c, va_list args);
void	ft_putstr_fd(char *s, int fd);

#endif