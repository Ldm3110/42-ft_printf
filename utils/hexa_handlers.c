/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:44:11 by jhervoch          #+#    #+#             */
/*   Updated: 2025/10/25 22:46:31 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	handle_hexa(va_list *args, int hexa)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	res = malloc(sizeof(char) * 16);
	if (!res)
		return (0);
	convert_hexa(res, va_arg(*args, int), &i, hexa);
	len = print_putstr_fd(res, 1);
	free(res);
	return ((int)len);
}

int	handle_hexa_lower(va_list *args)
{
	int	len;

	len = handle_hexa(args, 1);
	return (len);
}

int	handle_hexa_upper(va_list *args)
{
	int	len;

	len = handle_hexa(args, 2);
	return (len);
}
