/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:59:52 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 20:47:10 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

int	ft_lennbr_16(size_t nbr)
{
	int len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_proc_pointer(t_arg *pars, va_list *arg_ptr)
{
	size_t	adress;
	int		len;

	adress = va_arg(*arg_ptr, size_t);
	len = (pars->precision == 0 && adress == 0) ? 0 : ft_lennbr_16(adress);
	if (pars->precision > len)
		len = pars->precision;
	if (pars->width && pars->flag != '-')
		ft_putchar_width(' ', pars->width - len - 2);
	ft_putstr_prec("0x", 2);
	ft_putchar_width('0', pars->precision - len);
	if (len > 0)
		ft_putnbr_base_fd(adress, 16, 1, 0);
	g_length += len;
	if (pars->width && pars->flag == '-')
		ft_putchar_width(' ', pars->width - len - 2);
	return (0);
}
