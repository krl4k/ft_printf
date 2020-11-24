/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:12:10 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/23 09:29:48 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

int	ft_putchar_width(int c, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_global(c);
		i++;
	}
	return (i);
}

int	ft_proc_char(t_arg *pars, va_list *arg_ptr)
{
	int c;
	int i;

	i = 0;
	c = va_arg(*arg_ptr, int);
	if (pars->width != 0)
	{
		if (pars->flag == '\0')
			ft_putchar_width(' ', pars->width - 1);
		ft_putchar_global(c);
		if (pars->flag == '-')
			ft_putchar_width(' ', pars->width - 1);
	}
	else
		ft_putchar_global(c);
	return (0);
}
