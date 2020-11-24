/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:30:57 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/23 11:06:58 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int			ft_pars_flag(const char *format, t_arg *pars)
{
	int		len;
	char	flag;

	len = 0;
	flag = 0;
	while ((*format == '-' || *format == '0') && *format)
	{
		if (*format == '0')
			flag = '0';
		else if (*format == '-')
			pars->flag = '-';
		format++;
		len++;
	}
	if (flag == '0' && pars->flag != '-')
		pars->flag = '0';
	return (len);
}

int			pars_width_helper(const char *format, t_arg *pars,
			int width, int len)
{
	if (ft_isdigit(*format))
	{
		pars->width = ft_atoi(format);
		if (pars->width < 0)
		{
			if (pars->flag == '-')
				if (pars->flag != '0')
					pars->flag = '\0';
			pars->width = -width;
		}
		len = ft_lennbr(pars->width);
	}
	return (len);
}

int			ft_pars_width(const char *format, t_arg *pars, va_list *arg_ptr)
{
	int len;
	int width;

	len = 0;
	width = 0;
	if (*format == '*')
	{
		width = va_arg(*arg_ptr, int);
		if (width < 0 && pars->flag == '-')
			width = -width;
		else if (width < 0 && pars->flag != '-')
		{
			pars->flag = '-';
			width = -width;
		}
		pars->width = width;
		return (1);
	}
	else if (ft_isdigit(*format))
	{
		len = pars_width_helper(format, pars, width, len);
	}
	return (len);
}

int			ft_pars_precision(const char *format, t_arg *pars, va_list *arg_ptr)
{
	int len;

	len = 0;
	if (*format == '.')
	{
		pars->precision = 0;
		format++;
		if (ft_isdigit(*format))
		{
			while (*(format + len) == '0')
				len++;
			if (ft_isdigit(*(format + len)))
			{
				pars->precision = ft_atoi(format);
				len += ft_lennbr(pars->precision);
			}
		}
		else if (*format == '*')
		{
			pars->precision = va_arg(*arg_ptr, int);
			len++;
		}
		len++;
	}
	return (len);
}

int			ft_pars_type(const char *format, t_arg *pars)
{
	char *types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (*format == *types)
		{
			pars->type = *format;
			return (1);
		}
		types++;
	}
	return (0);
}
