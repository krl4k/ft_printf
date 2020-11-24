/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:26:19 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 15:46:54 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

int	ft_proc_percent(t_arg *pars)
{
	int len;

	len = (pars->precision == 0) ? 0 : 1;
	if (pars->precision > len)
		len = pars->precision;
	if (pars->width && pars->flag != '-' && pars->flag != '0')
		ft_putchar_width(' ', pars->width - len);
	if (pars->width && pars->flag == '0')
		ft_putchar_width('0', pars->width - len);
	if (len > 0)
		ft_putchar_width('%', 1);
	if (pars->width && pars->flag == '-')
		ft_putchar_width(' ', pars->width - 1);
	return (0);
}
