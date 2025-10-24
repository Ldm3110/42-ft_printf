/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-matt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:09:34 by lude-matt         #+#    #+#             */
/*   Updated: 2025/10/24 16:46:24 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft/libft.h"

int	handle_int(va_list *args)
{
	char	*str_nb;
	int		len;

	str_nb = ft_itoa(va_arg(*args, int));
	len = ft_strlen(str_nb);
	print_putstr_fd(str_nb, 1);
	return (len);
}

int	handle_char(va_list *args)
{
	char	c;

	c = (char) va_arg(*args, int);
	print_putchar_fd(c, 1);
	return (1);
}

int	handle_str(va_list *args)
{
	return (print_putstr_fd(va_arg(*args, char *), 1));
}
