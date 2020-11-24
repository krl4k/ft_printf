/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:00:59 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 15:20:02 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

static int	ft_lennbr_uint(unsigned int nbr)
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
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr_positive(t_arg *pars, unsigned int nbr)
{
	int len;
	int prec;

	len = (pars->precision == 0 && nbr == 0) ? 0 : ft_lennbr_uint(nbr);
	prec = (pars->precision >= len) ? pars->precision - len : 0;
	pars->width = (pars->width >= len) ? pars->width - len : 0;
	if (pars->flag == '\0')
		ft_putchar_width(' ', pars->width - prec);
	if (pars->flag == '0')
	{
		if (pars->precision < 0)
			ft_putchar_width('0', pars->width - prec);
		else
			ft_putchar_width(' ', pars->width - prec);
	}
	if (pars->precision >= 0)
		ft_putchar_width('0', prec);
	if (len > 0)
		ft_putnbr_uint_fd(nbr, 1);
	g_length += len;
	if (pars->flag == '-')
		ft_putchar_width(' ', pars->width - prec);
}

int			ft_proc_uint(t_arg *pars, va_list *arg_ptr)
{
	unsigned int nbr;

	nbr = va_arg(*arg_ptr, unsigned int);
	ft_putnbr_positive(pars, nbr);
	return (0);
}
