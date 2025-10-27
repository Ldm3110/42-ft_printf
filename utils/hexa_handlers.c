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

#include "../ft_printf.h"

static int	handle_hexa(va_list *args, int hexa)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	convert_hexa((unsigned int) va_arg(*args, int), hexa, &len);
	return (len);
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
