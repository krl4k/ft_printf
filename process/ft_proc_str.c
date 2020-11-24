/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:27:54 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 19:54:17 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

void	ft_putstr_prec(char *s, int prec)
{
	int i;

	i = 0;
	while (i < prec)
	{
		ft_putchar_global(s[i]);
		i++;
	}
}

int		ft_proc_str(t_arg *pars, va_list *arg_ptr)
{
	char	*str;
	int		len;

	str = va_arg(*arg_ptr, char *);
	if (!str)
		str = "(null)";
	len = (pars->precision >= 0 &&
	pars->precision < ft_strlen(str)) ? pars->precision : ft_strlen(str);
	if (pars->flag == '\0' && pars->width >= 0)
		ft_putchar_width(' ', pars->width - len);
	ft_putstr_prec(str, len);
	if (pars->flag == '-' && pars->width)
		ft_putchar_width(' ', pars->width - len);
	return (0);
}
