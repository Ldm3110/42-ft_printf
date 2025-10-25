/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-matt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:29:01 by lude-matt         #+#    #+#             */
/*   Updated: 2025/10/25 22:50:33 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define HEXA_TABLE 16
# define HEXA_LOW "0123456789abcde"
# define HEXA_UPP "0123456789ABCDE" 

typedef int	(*t_handler_func)(va_list *args);

typedef struct s_dict_func
{
	char			specifier;
	t_handler_func	handler;
}					t_dict_func;

int		handle_int(va_list *args);
int		handle_char(va_list *args);
int		handle_str(va_list *args);
int		handle_hexa_lower(va_list *args);
int		handle_hexa_upper(va_list *args);
int		print_putchar_fd(char c, int fd);
int		print_putstr_fd(char *s, int fd);
char	*convert_hexa(char *res, int nb, int *i, int hexa);

#endif
