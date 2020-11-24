/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_x_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:43:02 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/23 09:29:29 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

int	ft_proc_x_x(t_arg *pars, va_list *arg_ptr)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(*arg_ptr, unsigned int);
	len = (pars->precision == 0 && nbr == 0) ? 0 : ft_lennbr_16(nbr);
	if (pars->precision > 0 && pars->precision > len)
	{
		len = pars->precision;
		g_length += ft_lennbr_16(nbr);
	}
	else
		g_length += len;
	if (pars->flag == '0' && pars->precision < 0)
		ft_putchar_width('0', pars->width - len);
	else if (pars->flag != '-' && pars->width)
		ft_putchar_width(' ', pars->width - len);
	ft_putchar_width('0', pars->precision - ft_lennbr_16(nbr));
	if (len > 0)
		ft_putnbr_base_fd(nbr, 16, 1, (pars->type == 'x') ? 0 : 1);
	if (pars->width && pars->flag == '-')
		ft_putchar_width(' ', pars->width - len);
	return (0);
}
