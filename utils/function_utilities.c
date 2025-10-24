/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:06:05 by jhervoch          #+#    #+#             */
/*   Updated: 2025/10/24 16:08:04 by jhervoch         ###   ########.fr       */
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
