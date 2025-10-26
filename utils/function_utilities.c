/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:06:05 by jhervoch          #+#    #+#             */
/*   Updated: 2025/10/25 22:48:29 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_putchar_fd(char c, int fd)
{
	int	len;

	len = write(fd, &c, 1);
	return (len);
}

int	print_putstr_fd(char *s, int fd)
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

char	*convert_hexa(char *res, unsigned long nb, int *i, int hexa)
{
	char	table[HEXA_TABLE];

	if (hexa == 1)
		ft_strlcpy(table, HEXA_LOW, sizeof(table));
	else if (hexa == 2)
		ft_strlcpy(table, HEXA_UPP, sizeof(table));
	if (nb >= 16)
		convert_hexa(res, nb / 16, i, hexa);
	res[*i] = table[nb % 16];
	(*i)++;
	res[*i] = '\0';
	return (res);
}
