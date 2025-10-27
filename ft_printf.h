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

# define HEXA_TABLE 17
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF" 

typedef int	(*t_handler_func)(va_list *args);

typedef struct s_dict_func
{
	char			specifier;
	t_handler_func	handler;
}					t_dict_func;

void	init_format_handler(t_dict_func *table);
int		dispatch_function(char c, va_list *argument);
int		ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
int		handle_int(va_list *args);
int		handle_char(va_list *args);
int		handle_str(va_list *args);
int		handle_hexa_lower(va_list *args);
int		handle_hexa_upper(va_list *args);
int		handle_address(va_list *args);
int		handle_unsigned(va_list *args);
int		print_putchar_fd(char c, int fd);
int		print_putstr_fd(char *s, int fd);
void	convert_hexa(unsigned long nb, int hexa, int *len);
void	ft_put_unsnbr(unsigned int nb, int *len);
#endif
