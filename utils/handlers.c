/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-matt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:09:34 by lude-matt         #+#    #+#             */
/*   Updated: 2025/10/24 11:09:36 by lude-matt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "printf.h"

int	handle_nbr(int nb)
{
	char	*str_nb;
	int		len;

	str_nb = ft_itoa(nb);
	len = ft_strlen(str_nb);
	ft_putstr_fd(str_nb, 1);
	return (len);
}
