/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:00:59 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 18:44:10 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

static void	ft_putnbr_positive(t_arg *pars, int nbr)
{
	int len;
	int prec;

	len = (pars->precision == 0 && nbr == 0) ? 0 : ft_lennbr(nbr);
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
		ft_putnbr_fd(nbr, 1);
	g_length += len;
	if (pars->flag == '-')
		ft_putchar_width(' ', pars->width - prec);
}

static int	ft_pars_flag_0(int nbr, t_arg *pars, int prec)
{
	if (pars->flag == '0')
	{
		if (pars->precision < 0)
		{
			ft_putchar_width('-', 1);
			nbr = -nbr;
			ft_putchar_width('0', pars->width - prec);
		}
		else
			ft_putchar_width(' ', pars->width - prec);
	}
	return (nbr);
}

static void	ft_putnbr_negative(t_arg *pars, int nbr)
{
	int	len;
	int	prec;

	len = ft_lennbr(nbr);
	prec = (pars->precision > len) ? pars->precision - len + 1 : 0;
	pars->width = (pars->width > len) ? pars->width - len : 0;
	if (pars->flag == '\0')
		ft_putchar_width(' ', pars->width - prec);
	nbr = ft_pars_flag_0(nbr, pars, prec);
	if (pars->precision > 0)
	{
		ft_putchar_width('-', 1);
		nbr = -nbr;
		ft_putchar_width('0', prec);
	}
	ft_putnbr_fd(nbr, 1);
	g_length += ft_lennbr(nbr);
	if (pars->flag == '-')
		ft_putchar_width(' ', pars->width - prec);
}

int			ft_proc_d_i(t_arg *pars, va_list *arg_ptr)
{
	int	nbr;

	nbr = va_arg(*arg_ptr, int);
	if (nbr >= 0)
		ft_putnbr_positive(pars, nbr);
	else
		ft_putnbr_negative(pars, nbr);
	return (0);
}
