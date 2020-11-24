/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:23:02 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/23 11:29:52 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFTPRINTF_H
# define __LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_arg
{
	char		type;
	int			width;
	int			precision;
	int			size;
	char		flag;
	int			len_of_str;
}				t_arg;
int				g_length;
int				ft_printf(const char *format, ...);
t_arg			*ft_parser(const char *format, va_list *arg_ptr);
void			ft_putchar_global(char c);
int				pars_width_helper(const char *format,
				t_arg *pars, int width, int len);
#endif
