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

#include <stdio.h>

#include "../printf.h"
#include "../libft/libft.h"

int	handle_int(va_list *args)
{
	char	*str_nb;

	str_nb = ft_itoa(va_arg(*args, int));
	return (print_putstr_fd(str_nb, 1));
}

int	handle_char(va_list *args)
{
	char	c;

	c = (char) va_arg(*args, int);
	return (print_putchar_fd(c, 1));
}

int	handle_str(va_list *args)
{
	return (print_putstr_fd(va_arg(*args, char *), 1));
}

int	handle_address(va_list *args)
{
	void			*c_addr;
	unsigned long	addr_nb;
	char			*res;
	int				i;
	size_t			len;	

	i = 0;
	c_addr = va_arg(*args, void *);
	addr_nb = (unsigned long) &c_addr;
	res = malloc(sizeof(char) * 17);
	if (!res)
		return (0);
	res[i] = '0';
	res[i + 1] = 'x';
	i = 2;
	convert_hexa(res, addr_nb, &i, 1);
	len = print_putstr_fd(res, 1);
	free(res);
	return ((int)len);
}
