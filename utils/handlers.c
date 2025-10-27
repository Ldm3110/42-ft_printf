/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-matt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:09:34 by lude-matt         #+#    #+#             */
/*   Updated: 2025/10/25 22:44:35 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

int	handle_int(va_list *args)
{
	char	*str_nb;
	size_t	len;

	str_nb = ft_itoa(va_arg(*args, int));
	len = print_putstr_fd(str_nb, 1);
	free(str_nb);
	return (len);
}

int	handle_char(va_list *args)
{
	char	c;

	c = (char) va_arg(*args, int);
	return (print_putchar_fd(c, 1));
}

int	handle_str(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	if (!str)
		return (print_putstr_fd("(null)", 1));
	return (print_putstr_fd(str, 1));
}

int	handle_address(va_list *args)
{
	unsigned long	addr_nb;
	int				i;
	int				len;	

	i = 0;
	addr_nb = va_arg(*args, unsigned long);
	if (!addr_nb)
		return (print_putstr_fd("(nil)", 1));
	len = print_putstr_fd("0x", 1);
	convert_hexa(addr_nb, 1, &len);
	return ((int)len);
}

int	handle_unsigned(va_list *args)
{
	int	len;

	len = 0;
	ft_put_unsnbr(va_arg(*args, unsigned int), &len);
	return (len);
}
