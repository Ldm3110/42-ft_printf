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
