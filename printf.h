/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-matt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:29:01 by lude-matt         #+#    #+#             */
/*   Updated: 2025/10/24 16:39:44 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef int	(*t_handler_func)(va_list *args);

typedef struct s_dict_func
{
	char			specifier;
	t_handler_func	handler;
}					t_dict_func;

int	handle_int(va_list *args);
int	handle_char(va_list *args);
int	handle_str(va_list *args);
int	print_putchar_fd(char c, int fd);
int	print_putstr_fd(char *s, int fd);

#endif
