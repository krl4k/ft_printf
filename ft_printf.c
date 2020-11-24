/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:10:05 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/23 11:13:26 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_process.h"

void	ft_putchar_global(char c)
{
	ft_putchar_fd(c, 1);
	g_length++;
}

t_arg	*ft_parser(const char *format, va_list *arg_ptr)
{
	t_arg		*pars;
	const char	*temp;

	temp = format;
	if ((pars = (t_arg *)malloc(sizeof(t_arg))))
	{
		pars->flag = '\0';
		pars->width = 0;
		pars->precision = -1;
		pars->size = 0;
		pars->type = 0;
		format += ft_pars_flag(format, pars);
		format += ft_pars_width(format, pars, arg_ptr);
		format += ft_pars_precision(format, pars, arg_ptr);
		format += ft_pars_type(format, pars);
		pars->len_of_str = format - temp;
		if (!(pars->type))
		{
			free(pars);
			pars = NULL;
		}
	}
	return (pars);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	t_arg	*pars;

	va_start(arg_ptr, format);
	g_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(pars = ft_parser(++format, &arg_ptr)))
			{
				va_end(arg_ptr);
				return (g_length);
			}
			format += pars->len_of_str;
			ft_process(pars, &arg_ptr);
			free(pars);
		}
		else
			ft_putchar_global(*format++);
	}
	va_end(arg_ptr);
	return (g_length);
}
