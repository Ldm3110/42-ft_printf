/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:40:58 by jhervoch          #+#    #+#             */
/*   Updated: 2025/10/23 23:11:35 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
}

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (*format == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	return (1);
}

int	main(void)
{
	ft_printf("Bonjour %s, tu as %d ans", "Ludovic", 37);
}
