/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-matt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:29:01 by lude-matt         #+#    #+#             */
/*   Updated: 2025/10/24 11:13:25 by lude-matt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef int (*t_handler_func)(va_list args);

typedef struct s_dict_func
{
	char			specifier; 
	t_handler_func	handler;
}					t_dict_func;

/*t_dict_func	format_handler[] = {
	{'c', handle_char},
	{'d', handle_int},
	{'s', handle_string},
	{'\0', NULL}
}*/

int	handle_nbr(int nb);

#endif
