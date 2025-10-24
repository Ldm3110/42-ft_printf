/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:40:58 by jhervoch          #+#    #+#             */
/*   Updated: 2025/10/24 16:53:47 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	init_format_handler(t_dict_func *table)
{
	table[0] = (t_dict_func){'c', handle_char};
	table[1] = (t_dict_func){'d', handle_int};
	table[2] = (t_dict_func){'s', handle_str};
	table[3] = (t_dict_func){'\0', NULL};
}

int	dispatch_function(char c, va_list *argument)
{
	int				len;
	int				i;
	t_dict_func		format_handler[4];
	t_handler_func	function;

	init_format_handler(format_handler);
	i = 0;
	len = 0;
	while (format_handler[i].specifier != '\0')
	{
		if (format_handler[i].specifier == c)
		{
			function = format_handler[i].handler;
			len = function(argument);
		}
		i++;
	}
	return (len);
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
			len_f += dispatch_function(*format, &args);
		}
		else
			len_f += print_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (len_f);
}

int	main(void)
{
	printf("\n%d\n", ft_printf("Il y a %d cartes et %d %s", 32, 4, "rois"));
}

// len_f += _ft_putstr_fd(va_arg(args, char *), 1);
