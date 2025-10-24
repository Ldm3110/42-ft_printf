/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:40:58 by jhervoch          #+#    #+#             */
/*   Updated: 2025/10/24 11:45:58 by lude-matt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <unistd.h>

static int	_ft_putchar_fd(char c, int fd)
{
	int	nb_c;

	nb_c = write(fd, &c, 1);
	return (nb_c);
}

static int	_ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
	return (index);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len_f;

	va_start(args, format);
	len_f = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				len_f += _ft_putstr_fd(va_arg(args, char *), 1);
			else if (*format == 'd')
				len_f += handle_nbr(va_arg(args, int));
		}
		else
			len_f += _ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (len_f);
}

int	main(void)
{
	printf("\n%d\n", ft_printf("Bonjour %s, tu as %d ans", "Ludovic", 37));
}
