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

#include "../ft_printf.h"
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

void	ft_put_unsnbr(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_put_unsnbr(n / 10, len);
		ft_put_unsnbr(n % 10, len);
	}
	else
		*len += print_putchar_fd((n + '0'), 1);
}

void	convert_hexa(unsigned long nb, int hexa, int *len)
{
	char	table[HEXA_TABLE];

	if (hexa == 1)
		ft_strlcpy(table, HEXA_LOW, sizeof(table));
	else if (hexa == 2)
		ft_strlcpy(table, HEXA_UPP, sizeof(table));
	if (nb >= 16)
		convert_hexa(nb / 16, hexa, len);
	*len += print_putchar_fd(table[nb % 16], 1);
}
